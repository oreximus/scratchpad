## Prompts Collection for various purposes:

### Notes:

```
check this notes file, improvise the content inside this, add some better easy to understand context, and complete the incomplete portion,
carefully analyze the content, understand the relation and provide the notes in much better understanding sense
```

## React Native:

1. for starting development with the agent via chat:

```
the provided code is react native bare community cli app,
<description about the app>
<then provide what do you want to do with the project>
```

2. for integration for feature extension:

```
this is my react native bare community cli app,
about task/project management with attendance and more like these features,

I want to integrate the push notification system for android devices into this app for these situations:
1. when I create some task and assigned it to the user, the assigned user will get the notification for it,

2. when I invite any to the organization, the invited user will get the notification,

properly understand my code and flow of the data needed to integrate this solution,

without any unnecessary modification to my existing code, provide me the solution and integration for my bare react native community cli app
```

## NodeJS Server:

- for creating APIs with the existing code reference:

```
I've attached you the example nodejs server api flow for the reference to provide me the API endpoints that you've suggested to me to create,

Your suggested endpoints:
// POST /api/user/update-fcm-token
// Body: { fcm_token: string, device_type: string }

// POST /api/notifications/send-task-assignment
// Body: { task_id: string, assigned_to_user_id: string, task_title: string, assigned_by_name: string }

// POST /api/notifications/send-invitation
// Body: { invitation_id: string, invited_user_id: string, organization_name: string, invited_by_name: string }

// POST /api/notifications/get-notifications
// Body: { page: number }

// PUT /api/notifications/:id/read

take the reference from my flow and provide me these enpoints!
```

- taking server API flow reference to provide the similar functionality:

```
I've provided you the flow of the APIs from my nodejs server, that How I structured my code, based on that can you provide the essential mentioned in my screenshot, also do suggest me the better way to do what I'm trying to do,
also the notification will trigger right now in the case of task creation only for just now, to test, with clean flow that's referenced here for you.
the notification message, will going to the use who is assigned the task to
```

- SIR structure backend reimplementation with our custom DB:

```
take the reference from existing admin app APIs from user APIs flow or available APIs flow under admin/
routes, controllers, services and validate_schema,

based on the anantpragya.sql file (mysql database exported file) contains my new blogging website database,

provide all of the needed authentication APIs for users according to the database structure I've, take existing admin APIs flow to structure the code in that way using properly messages, error handling, schema following, etc. with all of the need models and all

under app/ and that followed the same code organized way: routes, controllers, services and validate_schema
```

## For Database:

```
I want you to provide me the sql to build make these tables in my mysql database with the database name "Your-DB-Name" also, keep in mind there shouldn't be any foreign key relation in the tables, I'll identify them with the normal id columns as I've described for my personal convenience,

also provide the needed default values setting where required
```

## For Next FrontEnd:

### Blogging Website:

```
this is postman collection with the examples of the APIs that I'm currently using,

what you need to modify in the blog:
1. provide the perfect APIs integration for creating new blog post, (a good UI improvement to be able find and write new blogposts, use existing page for improvisation).
2. provide the posts control in the user dashboard, (for edit and delete the post)
3. provide the good editor (user-friendly for the blogging feature)
4. provide the good dynamic routing for displaying posts by categories and also I've attached you the current database file, for having idea of currently present blogs and blog categories data, (so you can remove the hard coded not needed things from the frontEnd, we will use the dynamic data showing all here,)
5. also balance some of the colors in the UI hence someplaces the text is dull and colors are not that pleasing,
6. follow good state management and smooth site optimizations,
7. remember to follow practices without breaking anything analyze and do things correctly without any errors
```

- for enhancing the pre-existing APIs according to the frontEnd form:

```
this is the page for creating post checkout the post creation related APIs from my Backend codes flows, and provide the these fields related form data submissions for the database and the post creation logic,

also for more of your reference I've provided you the entire database files and there are models in the the nodejs code do take reference from the things that you needed and do provide any SQL if there is any changes required in the database (we're not using foreign key relation, keep in mind that)
```
