# 🚀 Backend Server Deployment Checklist

## Pre-Deployment Setup

### DNS Configuration

- [ ] Configure A record for `api.thegrid.work.gd` → `136.109.189.15`
- [ ] Configure A record for `dev-api.thegrid.work.gd` → `136.109.189.15`
- [ ] Verify DNS propagation with `nslookup api.thegrid.work.gd`

### Server Initial Setup

- [ ] SSH into server: `gcloud compute ssh clepsydra-vm01 --zone=us-west1-a`
- [ ] Update system: `sudo apt update && sudo apt upgrade -y`
- [ ] Install Node.js 20.x
- [ ] Install Nginx
- [ ] Install PM2 globally
- [ ] Configure UFW firewall
- [ ] Install fail2ban

### Application Setup

- [ ] Create `/var/www/backend-task` directory
- [ ] Set proper ownership to `clepsydratechnologies`
- [ ] Clone repository to server
- [ ] Create `.env.development` file
- [ ] Create `.env.production` file
- [ ] Run `npm ci --production`
- [ ] Update `ecosystem.config.js` with optimized config
- [ ] Update `package.json` with proper scripts

### Nginx Configuration

- [ ] Create `/etc/nginx/sites-available/dev-api.thegrid.work.gd`
- [ ] Create `/etc/nginx/sites-available/api.thegrid.work.gd`
- [ ] Enable both sites in `sites-enabled`
- [ ] Remove default Nginx site
- [ ] Update `/etc/nginx/nginx.conf` with optimizations
- [ ] Test Nginx config: `sudo nginx -t`
- [ ] Restart Nginx: `sudo systemctl restart nginx`

### SSL/TLS Setup

- [ ] Obtain certificate for `api.thegrid.work.gd`
- [ ] Obtain certificate for `dev-api.thegrid.work.gd`
- [ ] Test auto-renewal: `sudo certbot renew --dry-run`
- [ ] Verify HTTPS works for both domains

### Security Hardening

- [ ] Configure fail2ban for Nginx and SSH
- [ ] Harden SSH configuration
- [ ] Setup UFW firewall rules
- [ ] Configure log rotation

### PM2 Setup

- [ ] Start applications: `pm2 start ecosystem.config.js`
- [ ] Verify both apps running: `pm2 status`
- [ ] Save PM2 process list: `pm2 save`
- [ ] Setup PM2 startup script
- [ ] Check logs: `pm2 logs`

### GitHub Actions Setup

- [ ] Add `GCP_SSH_PRIVATE_KEY` to GitHub secrets
- [ ] Add `GCP_VM_IP` to GitHub secrets
- [ ] Add `GCP_VM_USER` to GitHub secrets
- [ ] Update `.github/workflows/deploy-dev.yml`
- [ ] Update `.github/workflows/deploy-prod.yml`
- [ ] Test deployment by pushing to `develop` branch
- [ ] Test deployment by pushing to `main` branch

## Post-Deployment Verification

### Application Health

- [ ] Test dev API: `curl http://dev-api.thegrid.work.gd/health`
- [ ] Test prod API: `curl https://api.thegrid.work.gd/health`
- [ ] Check PM2 status: `pm2 status`
- [ ] Check PM2 logs: `pm2 logs`
- [ ] Verify no errors in application logs

### Nginx Verification

- [ ] Check Nginx status: `sudo systemctl status nginx`
- [ ] Review access logs: `sudo tail -f /var/log/nginx/api-access.log`
- [ ] Review error logs: `sudo tail -f /var/log/nginx/api-error.log`
- [ ] Test rate limiting works

### SSL/TLS Verification

- [ ] Verify SSL certificate validity
- [ ] Test HTTPS redirect works
- [ ] Check SSL grade at SSL Labs
- [ ] Verify HSTS headers present

### Security Verification

- [ ] Test fail2ban is active: `sudo fail2ban-client status`
- [ ] Verify UFW is enabled: `sudo ufw status`
- [ ] Check SSH hardening applied
- [ ] Test that only necessary ports are open

### Database Connection

- [ ] Verify MongoDB connection works (if applicable)
- [ ] Test database read/write operations
- [ ] Check database logs for errors

### Monitoring Setup

- [ ] Create monitoring script: `/home/clepsydratechnologies/monitor.sh`
- [ ] Make script executable: `chmod +x monitor.sh`
- [ ] Test monitoring script: `./monitor.sh`
- [ ] Setup cron job for regular monitoring (optional)

### Performance Testing

- [ ] Test API response times
- [ ] Check memory usage: `free -h`
- [ ] Check disk usage: `df -h`
- [ ] Monitor CPU usage: `top`
- [ ] Test under load (optional)

### Documentation

- [ ] Update README with deployment instructions
- [ ] Document environment variables
- [ ] Create runbook for common operations
- [ ] Save Quick Reference guide

## GitHub Repository Updates

- [ ] Push updated `ecosystem.config.js` to repo
- [ ] Push updated `package.json` to repo
- [ ] Push updated GitHub Actions workflows
- [ ] Update `.gitignore` to exclude `.env.*` files
- [ ] Create deployment documentation

## Environment-Specific Tests

### Development Environment (dev-api.thegrid.work.gd)

- [ ] API responds on port 3001
- [ ] Nginx proxy works correctly
- [ ] Logs are being written to `logs/dev-*.log`
- [ ] Environment variables loaded from `.env.development`
- [ ] Auto-deployment from `develop` branch works

### Production Environment (api.thegrid.work.gd)

- [ ] API responds on port 3000
- [ ] Nginx proxy works correctly with HTTPS
- [ ] Logs are being written to `logs/prod-*.log`
- [ ] Environment variables loaded from `.env.production`
- [ ] Auto-deployment from `main` branch works
- [ ] Rate limiting is more strict than dev

## Maintenance Tasks Setup

- [ ] Setup log rotation
- [ ] Schedule regular backups (if using local DB)
- [ ] Setup monitoring alerts (optional)
- [ ] Document disaster recovery procedures
- [ ] Create backup and restore scripts

## Final Sign-Off

- [ ] All APIs accessible and responding correctly
- [ ] No errors in any log files
- [ ] PM2 applications stable and running
- [ ] SSL certificates valid and auto-renewing
- [ ] Security measures in place
- [ ] Documentation complete
- [ ] Team notified of deployment
- [ ] Rollback procedure documented

---

## Emergency Contacts & Resources

**Server IP:** 136.109.189.15
**SSH User:** clepsydratechnologies
**Project Path:** /var/www/backend-task

**Important Commands:**

- Emergency restart: `pm2 restart all && sudo systemctl restart nginx`
- Check status: `pm2 status && sudo systemctl status nginx`
- View logs: `pm2 logs && sudo tail -f /var/log/nginx/error.log`

**Useful Links:**

- PM2 Documentation: https://pm2.keymetrics.io/
- Nginx Documentation: https://nginx.org/en/docs/
- Let's Encrypt: https://letsencrypt.org/
- MongoDB Docs: https://docs.mongodb.com/
