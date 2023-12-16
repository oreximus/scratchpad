# Notes on Network Scanning Application

## Creating a Network Scanner with Web UI, integrated with Scanning Application and User Authentication!

### Web Application Part:

- Creating Webapplication with the use of flask framework.
    1. first creating a simple web-app with some default pages:(login, register, dashboard, about, error404, error500).
    2. then working on the Dashboard Part Specifically to able to perform these operations:
        1. has a `Add a Scan` option, to be able add the multiple scans options in the queue.
        2. has a side bar where options like: export, settings, history; will appear!
        3. has a top navigation and info bar; on login we will have profile welcome! and a logout option.
        4. Dashboard main page has `scan section` where `scan's queue` will appear and the process can be seen and initiated.
        5. If `scan got completed` we can see the results on the dashboard main by `dropping-down` feature on clicking the scans.
    3. Scans related options and features:
        1. we can see the report in already formatted way with graphical data representation,
        2. also the `raw view of reports will be available!`
    4. Side options and features:
        1. In Export Option:
            1. we can export the desired data of any specific scan in the form of csv,html,pdf,json
        2. In setting option we can change default scan to something more specific:
            1. remember it is a network scan which is using nmap in the backend so we'll be using nmap options for modification.
            2. option for dashboard theming.
            3. changing account password or username.
            4. mailing scan data
            5. backing up the data; and reset the account
        3. History Option:
            1. We can have history of all scans that we've performed till now!
            2. Able to jump to the particular scan, if presented in the DB

### Script Part:
