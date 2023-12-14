# Flask Tutorial Using Official Documentation
### source: https://flask.palletsprojects.com/en/3.0.x/tutorial/factory/

## Notes

- A Flask application is an instance of the **Flask** class. Everything about the application, such as configuration and URLs, will be registered with this class.

- Instead of creating a **Flask** instance globally, you will create it inside a function. This function is known as the *application factory*. Any configuration, registration, and other setup the application needs will happen inside the function, then the application will be returned.

## The Application Factory

- Create the `flaskr` directory and add the `__init__.py` file. The `__init__.py` serves double duty: it will contain the application factory, and it tells Python that the `flaskr` directory should be treated as a package.

**flaskr/__\init__\.py**

```
import os

from flask import Flask


def create_app(test_config=None):
    # create and configure the app
    app = Flask(__name__, instance_relative_config=True)
    app.config.from_mapping(
        SECRET_KEY='dev',
        DATABASE=os.path.join(app.instance_path, 'flaskr.sqlite'),
    )

    if test_config is None:
        # load the instance config, if it exists, when not testing
        app.config.from_pyfile('config.py', silent=True)
    else:
        # load the test config if passed in
        app.config.from_mapping(test_config)

    # ensure the instance folder exists
    try:
        os.makedirs(app.instance_path)
    except OSError:
        pass

    # a simple page that says hello
    @app.route('/hello')
    def hello():
        return 'Hello, World!'

    return app
```

- create\_app is the application factory function. You'll add to it later in the tutorial, but it already does a lot.

1. `app = Flask(__name__, instance_relative_config=True)` creates the **Flask** instance.

    - `__name__` is the name of the current Python module. The app needs to know where it's located to set up some paths, and `__name__` is a convenient way to tell it that.
    - `instance_relative_config=True` tells the app that configuration files are relative to the `instance folder`. The instance folder is located outside the `flaskr` package and can hold local data that shouldn't be committed to verison control, such as configuration secrets and the database file.

2. **app.config.from
