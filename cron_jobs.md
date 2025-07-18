# Notes

**source**: perplexity.ai

- A cron job schedule is defined by five fields representing time, followed by the command or script
  to execute:

```
* * * * * command-to-execute
- - - - -
| | | | |
| | | | ----- Day of the Week (0 - 6) (Sunday = 0)
| | | ------- Month (1 - 12)
| | --------- Day of the month (1 - 31)
| ----------- Hour (0 - 23)
------------- Minute (0 - 59)
```

- An asterik `*` means `every` unit (e.g., every minute, every hour).

- Example: to run a script every day at 3:00 AM:

```
0 3 * * * /path/to/your/script.sh
```

**Testing**:

- Creata a sample script to check the cron job:

**Sample script**:

```
#!/bin/bash
echo "Current Date and Time: $(date)" >> /path/to/output.log
```

- Make the script executable:

```
chmod + your_script.sh
```

- edit your crontab file:

**open the crontab editor**:

```
crontab -e
```

- Add your cron schedule and command or script. For example, to run your script every hour:

```
0 * * * * * /path/to/script.sh
```

- Save exit the editor. The cron daemon will automatically load your new schedule.

- To list your active cron jobs for the current user:

```
crontab -l
```

- Check whether the jobs are scheduled correctly:

- cron logs are available at:

```
/var/log/cron
```
