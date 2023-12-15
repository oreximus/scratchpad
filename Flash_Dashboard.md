# Creating User Dashboard in Flask Python

## Creating Custom Error Pages:

- we have to create new routes, and functions:

    - Creating Invalid URL, and flask has mechanism to deal with these things.
    ```
    @app.errorhandler(404)
    def page_not_found(e):
        return_template("404.html"), 404

    # Internal Server Error

    @app.errorhandler(500)
    def page_not_found(e):
        return_template("500.html"), 500
    ```

## Version Control System:

- Deactivate the venv first, and clone the repo by ssh method!

`.gitingore file content`

```
.gitingore

virt/
```

## Templates, Navbar and Links:

- create a templates dir, and inside it our all pages will lie.

- using bootstrap framework for our work!

- copying starter template and pasting all in the `templates/base.html`

- a simple modification in the \<body\> tag:

```
<body>
    <br>
    <div class="container">
        {% block content %}
        {% endblock %}
</body>
```


## Creating a Logggin-In

- 
