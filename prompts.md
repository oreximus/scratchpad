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
