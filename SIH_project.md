## Web App Environment!

### Using WSL System to Access!

- Open the WSL Instance you have: In case of Ubuntu, Open it from the Windows Start!

- cd to the Working Directory, where all the Flask Files are!

- Activate the Python Env, If not then First create One.

**command to create and python virtual env:**
run these commands in the working directory, where all the codes are stored!

1.
```
python -m venv .env
```

2.
```
./env/Scripts/Activate.ps1
```

- Install all the flask and essential packages to run the web-app, if not installed

**command to install flask and python3-nmap**

```
pip install flask python3-nmap
```

#### Running the Flask Application

- Running Flask Application, make sure that you are in the Virtual Environment, where all the packages are installed!

**command to run the web app**
```
flask --app flaskr run --debug
```

### Running Scanner Script separately

- Make sure that you're in the python virtual environment, and have python3-nmap is installed!

**command to run the script**:


```
python3 scanner01.py
```

**enter the valid IP**

- and wait it'll scan and output the scan results as json file and as well as appear on the screen.
