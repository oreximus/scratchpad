## Flask Environment Setting-UP!

### Windows 11

- Install Choco Package Manager!

- First Website:

command:

```
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

- Run powershell as admin, and paste the cmd.

- For installation:

```
choco install python3 python3-pip
```

- Creating Virtual Env:

```
python -m venv .env
```

- Activating virtual environment:

```
./.env/Scripts/activate.ps1
```

- After activating, install Flask package:

```
pip install flask
```

- Check Packages:

```
pip freeze
```

- if got output of packages, then you're done!

- For Running Flask application:

```
flask --app folder_name run
```
