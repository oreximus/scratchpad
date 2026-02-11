On a **GCP `e2‑micro` (2 vCPUs, 1 GB RAM)**, the bottleneck will be **CPU + RAM**, not your Node.js code itself. You can still run a performant, secure backend by tuning **Nginx**, **MongoDB**, and your **Node.js setup**, but you must keep resource usage lean. [blog.appsignal](https://blog.appsignal.com/2023/11/15/how-to-optimize-mongodb-performance-for-nodejs.html)

Below is a complete production‑oriented configuration guide step‑by‑step, then I’ll tell you when it makes more sense to change the stack.

***

## 1. System hardening on GCP

On the **Ubuntu/Debian VM**:

- Enable automatic security updates:
  ```bash
  sudo apt update
  sudo apt upgrade -y
  sudo apt install unattended-upgrades
  sudo dpkg-reconfigure --priority=low unattended-upgrades
  ```

- **Limit SSH access**:
  - Use SSH keys only, disable password login in `/etc/ssh/sshd_config`:
    ```conf
    PasswordAuthentication no
    PermitRootLogin no
    AllowUsers deployuser
    ```
  - Restart: `sudo systemctl restart ssh`.

- On **GCP Console**, tighten the VPC‑Firewall:  
  - Allow only **443 (HTTPS), 22 (SSH from your IPs)** and any custom ports for deployment. Avoid exposing MongoDB (27017) to the internet. [cloud.google](https://cloud.google.com/products/compute)

***

## 2. Node.js process setup (PM2)

Use `PM2` as process manager in **cluster + memory‑conscious mode**.

```bash
npm install pm2 -g
pm2 start server.js --name "api" --max-memory-restart 300M
```

- For e2‑micro, run **one cluster process only** (no over‑provisioning CPU):
  ```bash
  pm2 start server.js --name "api" --instances 1 --max-memory-restart 300M
  ```
- Enable auto‑restart on system reboot:
  ```bash
  pm2 startup
  pm2 save
  ```

This keeps one robust Node.js worker, schedules restart if memory > 300 MB, and survives reboot. [stackoverflow](https://stackoverflow.com/questions/62230608/scaling-performance-issues-with-mongodb-node-js-system-design-on-aws-ec2)

***

## 3. Nginx reverse proxy config

Install Nginx on the same VM:

```bash
sudo apt install nginx -y
```

Use a site‑specific config in `/etc/nginx/sites-available/api`:

```nginx
upstream node_backend {
    server 127.0.0.1:3000;
    keepalive 32;
}

server {
    listen 80;
    listen [::]:80;

    server_name api.yourdomain.com;

    # Reduce timeouts and buffers for a small instance
    client_max_body_size 10M;

    location / {
        proxy_pass http://node_backend;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;

        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection "upgrade";

        proxy_read_timeout 120s;
    }

    # API‑only optimizations: disable search bots / cache where it makes sense
    location ~* \.(js|css|png|jpg|jpeg|gif|ico|svg|woff|woff2)$ {
        expires 7d;
        add_header Cache-Control "public, immutable";
    }
}
```

Enable it and reload:

```bash
sudo ln -s /etc/nginx/sites-available/api /etc/nginx/sites-enabled/
sudo nginx -t
sudo systemctl reload nginx
```

Then move to HTTPS using **Let’s Encrypt** (next step). [youtube](https://www.youtube.com/watch?v=XbFQj7NYjZQ)

***

## 4. HTTPS + security headers

Install Certbot:

```bash
sudo apt install certbot python3-certbot-nginx -y
sudo certbot --nginx -d api.yourdomain.com
```

Further strengthen in your Nginx `server` block:

```nginx
server {
    listen 443 ssl http2;
    listen [::]:443 ssl http2;

    ssl_certificate /etc/letsencrypt/live/api.yourdomain.com/fullchain.pem;
    ssl_certificate_key /etc/letsencrypt/live/api.yourdomain.com/privkey.pem;

    # Modern TLS only (requires HTTP/2 support)
    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_ciphers ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256;

    # Security / CSP headers for API (adjust if serving UI)
    add_header Strict-Transport-Security "max-age=15768000; includeSubDomains; preload" always;
    add_header X-Content-Type-Options nosniff;
    add_header X-Frame-Options DENY;
    add_header X-Xss-Protection "1; mode=block";

    location / {
        proxy_pass http://node_backend;
        proxy_set_header ...
    }
}
```

Reload Nginx again. [dev](https://dev.to/shadid12/how-to-deploy-your-node-js-app-on-aws-with-nginx-and-ssl-3p5l)

***

## 5. MongoDB config on e2‑micro

MongoDB will **compete for RAM with Node.js**, so limit it gently.

- Edit `/etc/mongod.conf`:

```yaml
storage:
  dbPath: /var/lib/mongodb
  journal:
    enabled: true

systemLog:
  destination: file
  logAppend: true
  path: /var/log/mongodb/mongod.log

net:
  port: 27017
  bindIp: 127.0.0.1   # Only local, no public internet

# Tuning for 1 GB RAM VM
processManagement:
  fork: true

# Disable hugePages: often trappy in cloud
operationProfiling:
  slowOpThresholdMs: 100

# Prevent swapping as much as you can
storage:
  wiredTiger:
    engineConfig:
      cacheSizeGB: 0.4  # ~400 MB max cache on 1 GB RAM (Node needs ~300M+)
```

- Enable authentication and a dedicated user:

```bash
mongo admin
> db.createUser({ user: "apiuser", pwd: "STRONG_PASS", roles: [{ role: "readWrite", db: "myapp" }] })
> exit
```

- In Node.js (Mongoose / MongoDB driver), connect with:

```js
mongoose.connect(
  "mongodb://apiuser:STRONG_PASS@127.0.0.1:27017/myapp?directConnection=true",
  {
    maxPoolSize: 10,      // usually enough for small‑traffic API
    connectTimeoutMS: 5000,
    socketTimeoutMS: 30000,
  }
);
```

This avoids MongoDB blasting you with too many background threads and hugging all the RAM. [stackoverflow](https://stackoverflow.com/questions/62996445/how-to-properly-configure-nodejs-servers-running-on-gcp-vms-to-talk-to-each-othe)

***

## 6. Resource limits and monitoring

On such a small machine:

- Use `htop`, `iotop`, and `pm2 monit` to watch:
  - Keep Node.js heap under ~150–200 MB in production.
  - Ensure MongoDB cache (`wiredTiger.cacheSizeGB`) + Node process never push the system into heavy swap.
- Configure logs rotation (via `logrotate`) for both `nginx` and `mongod` to avoid disk fills.

Also add basic **health checks** in Node.js (`/health`) and, if needed, a lightweight struct like:

```js
app.get("/health", (req, res) => {
  res.json({ status: "ok", uptime: process.uptime() });
});
```

Use Nginx upstream health checks in future bigger clusters.

***

## 7. When e2‑micro becomes a bottleneck

For **true “maximum performance”** on e2‑micro, you simply cannot scale many concurrent users or heavy loads. In that case:

- **Better architecture options**:
  - Migrate MongoDB to **MongoDB Atlas** (managed), and keep only **Node.js + nginx** on GCP. This relieves you of DB‑ops and its RAM. [linkedin](https://www.linkedin.com/posts/okesh-prajapati-406ab825b_sheryianscodingschool-backenddevelopment-activity-7420535420171689984-YNoi)
  - Or, split roles:
    - 1 x small GCP VM for **API + Nginx (Node)**.
    - 1 x small VM or Atlas for **MongoDB**, with proper replication / backups.
  - Upgrade machine to **e2‑small (2 vCPUs, 2 GB RAM)** as soon as you see:
    - ≥ 75% RAM constantly used.
    - OOM‑killed services.
    - Frequent 5xx errors under light load.

Tuning here gives **good performance *within* the limits of e2‑micro**, not infinite scale. [blog.appsignal](https://blog.appsignal.com/2023/11/15/how-to-optimize-mongodb-performance-for-nodejs.html)

***

## 8. Optional performance improvements in code

Even with optimized infra, ensure your Node.js + MongoDB layer is lean:

- Always define **minimal, indexed queries** and use projections in MongoDB.
- Limit result size (no `find()` without pagination `/limit`).
- Use **batch writes** if possible rather than per‑request inserts/updates. [blog.appsignal](https://blog.appsignal.com/2023/11/15/how-to-optimize-mongodb-performance-for-nodejs.html)

If you paste your current `server.js`, `mongoose` schema, and Nginx conf, I can tailor the configs even more finely for your exact e2‑micro workload.
