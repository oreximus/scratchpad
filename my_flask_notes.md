## Flask Notes
#### source: https://flask.palletsprojects.com/en/3.0.x/tutorial/factory/

creating a simple web application using **flask official tutorial documenation**.

### Notes:

**Directory and files structure to follow**:

```
/home/user/Projects/flask-tutorial
├── flaskr/
│   ├── __init__.py
│   ├── db.py
│   ├── schema.sql
│   ├── auth.py
│   ├── blog.py
│   ├── templates/
│   │   ├── base.html
│   │   ├── auth/
│   │   │   ├── login.html
│   │   │   └── register.html
│   │   └── blog/
│   │       ├── create.html
│   │       ├── index.html
│   │       └── update.html
│   └── static/
│       └── style.css
├── tests/
│   ├── conftest.py
│   ├── data.sql
│   ├── test_factory.py
│   ├── test_db.py
│   ├── test_auth.py
│   └── test_blog.py
├── .venv/
├── pyproject.toml
└── MANIFEST.in
```

- Instead of creating a **Flask** instance globally, we are creating the application inside function. The function is known as the *application factory*. Any configuration, registration, and other setup the applcation needs will happed inside the function, then the application will be returned.

- `instance_relatvie_config=True` tells the app that configuration files are relative to the `instance folder`. The instance folder is located outside the `flaskr` package and can hold local data that shouldn't be commited to version control, such as configuration secrets and the database file.

- `SECRET_KEY` is used by Flask and extensions to keep data safe. It's set to 'dev' to provide a convenient value during the development, but it should be overridden with random value when deploying.

- `app.config.from_pyfile()` overrides the default configuration with values taken from the `config.py` file in the instance folder if it exists. For example, when deploying, this can be used to set a real `SECRET_KEY`.

    - `test_config` can also be passed to the factory, and will be used instead of the instance configuration. This is so the tests you'll write later in the tutorial can be configured independently of any development values you have configured.

### Database

- **g** is a special object that is unique for each request. It is used to store data that might be accessed by multiple functions during the request. The connection is stored and reused instead of creating a new connection if `get_db` is called a second time in the same request.

- Documentation has got wrong in the Database Section, for init_db, it mentioned something `init-db`, causes error while initializing the databse.

### Blueprints and Views

### Jinja Language


