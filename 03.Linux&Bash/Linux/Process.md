# Linux Revision Course

Welcome to the **Process and Daemon Section**!

## All of the commands we used

### 1. Bg/Fg
- Managing processes to work in the foreground (fg) and background (bg).
- Killing process using Kill command

### 2. Jobs
- Lists all background jobs in the current shell session.
- Displays detailed information, including process IDs, for background jobs.
- Killing the process using it's number %

### 3. Kill
- Sends a signal to terminate a process by its Process ID (PID).
- Forcefully terminates a process using the SIGKILL signal.
- Gracefully terminates a process using the SIGTERM signal.
- Restarts a process using the SIGHUP signal.

### 4. Ps
- Displays information about active processes using the `ps` command.
- Lists all processes running on the system with detailed information using `ps aux`.
- Shows all processes in a full-format listing with `ps -ef`.
- Displays processes owned by a specific user using `ps -u [username]`.
- Displays information about a specific process by its PID using `ps -p [PID]`.
- Customizes the output format to display specific fields using `ps -o [fields]`.
- Displays processes by command name using `ps -C [command]`.
- Shows processes in a tree-like structure with `ps --forest`.
- Combines `ps` with other tools like `grep` to filter processes based on specific criteria.
- Useful for monitoring and managing system processes effectively.
- Leverage `ps` to troubleshoot and analyze system performance.
- Experiment with different `ps` options to suit specific needs.
- and much more...

### 5. Top
- Displays real-time information about system processes, including CPU and memory usage.
- Interactive commands within `top`:
    - `k`: Kill a process by entering its PID.
    - `r`: Renice a process by entering its PID and new priority.
    - `q`: Quit the `top` interface.
    - `h`: Display help for `top` commands.
- Sort processes by specific fields:
    - `P`: Sort by CPU usage.
    - `M`: Sort by memory usage.
    - `T`: Sort by runtime.
- Customize the display by toggling fields or changing the update interval.
- Save the current configuration for future sessions.
- Provides a snapshot of system performance at a glance.
- Monitor specific processes by filtering with `top -p [PID]`.
- Highlight processes consuming excessive resources for easier identification.
- Export `top` output to a file for later analysis using `top -b -n 1 > output.txt`.
- Use `htop` as an alternative to `top` for a more user-friendly interface.
- Explore advanced options like setting thresholds for alerts.
- Understand the impact of processes on system performance over time.
- Optimize resource allocation based on insights from `top`.
- Leverage `top` to troubleshoot performance bottlenecks effectively.
- Experiment with different `top` configurations to suit specific needs.

### 6. Nice/Renice
- Adjusts the priority of a process when it is started using the `nice` command.
- Changes the priority of a running process using the `renice` command.
- Priority values range from -20 (highest priority) to 19 (lowest priority).
- Syntax for `nice`: `nice -n [priority] [command]`.
- Syntax for `renice`: `renice [priority] -p [PID]`.
- Allows better control over CPU resource allocation.
- Useful for ensuring critical processes get more CPU time.
- Helps in managing system performance during high load.
- Requires root privileges for setting negative priorities.
- Avoids resource starvation for lower-priority processes.

### 7. Writting ower own shell
- you can find it in file called Simple_Shell.c

### 8. Systemctl
- `systemctl start [service]`: Starts a specific service.
- `systemctl stop [service]`: Stops a specific service.
- `systemctl restart [service]`: Restarts a specific service.
- `systemctl status [service]`: Displays the status of a specific service.
- `systemctl enable [service]`: Enables a service to start at boot.
- `systemctl disable [service]`: Disables a service from starting at boot.
- `systemctl is-active [service]`: Checks if a service is currently active.
- `systemctl is-enabled [service]`: Checks if a service is enabled to start at boot.
- `systemctl list-units --type=service`: Lists all active services.
- `systemctl list-unit-files --type=service`: Lists all installed service unit files.
- `systemctl daemon-reload`: Reloads the systemd manager configuration.
- `journalctl -u [service]`: Views logs for a specific service.
- `systemctl mask [service]`: Prevents a service from being started manually or automatically.
- `systemctl unmask [service]`: Removes the mask from a service.
- `systemctl isolate [target]`: Switches the system to a specific target (runlevel).
- `systemctl get-default`: Displays the default target (runlevel).
- `systemctl set-default [target]`: Sets the default target (runlevel).
- `systemctl cat [service]`: Displays the content of a service's unit file.
- `systemctl edit [service]`: Opens the unit file for editing, allowing customization.
- `systemctl show [service]`: Displays detailed properties of a service.
- `systemctl reset-failed [service]`: Resets the failed state of a service.
- `systemctl list-dependencies [service]`: Lists all dependencies of a service.
- `systemctl suspend`: Suspends the system.
- `systemctl hibernate`: Hibernates the system.
- `systemctl hybrid-sleep`: Puts the system into hybrid sleep mode.
- `systemctl list-units --type=target`: Lists all active targets.
- `systemctl start [target]`: Starts a specific target.
- `systemctl stop [target]`: Stops a specific target.
- `systemctl isolate [target]`: Switches the system to a specific target.
- `systemctl get-default`: Displays the default target (runlevel).
- `systemctl set-default [target]`: Sets the default target (runlevel).
- `systemctl list-dependencies [target]`: Lists all dependencies of a target.
- `systemctl rescue`: Switches to rescue mode (single-user mode).
- `systemctl emergency`: Switches to emergency mode (minimal environment).
- `systemctl poweroff`: Powers off the system.
- `systemctl reboot`: Reboots the system.
- `systemctl list-timers`: Lists all active timers.
- `systemctl start [timer]`: Starts a specific timer.
- `systemctl stop [timer]`: Stops a specific timer.
- `systemctl list-sockets`: Lists all active sockets.
- `systemctl start [socket]`: Starts a specific socket.
- `systemctl stop [socket]`: Stops a specific socket.
- `systemctl list-units --type=mount`: Lists all active mount units.
- `systemctl start [mount]`: Mounts a specific filesystem.
- `systemctl stop [mount]`: Unmounts a specific filesystem.
- `systemctl list-units --type=swap`: Lists all active swap units.
- `systemctl start [swap]`: Activates a specific swap unit.
- `systemctl stop [swap]`: Deactivates a specific swap unit.

### 9. Creating Your Own Service
- Create a custom service using `systemd` to manage your application or script.
- Steps to create a service:
    1. Create a service file in `/etc/systemd/system/`:
        ```bash
        sudo nano /etc/systemd/system/my_service.service
        ```
    2. Define the service configuration:
        ```ini
        [Unit]
        Description=My Custom Service
        After=network.target

        [Service]
        ExecStart=/path/to/your/script_or_application
        Restart=always
        User=your_username
        Group=your_groupname

        [Install]
        WantedBy=multi-user.target
        ```
    3. Save and close the file.
    4. Reload the systemd manager configuration:
        ```bash
        sudo systemctl daemon-reload
        ```
    5. Start the service:
        ```bash
        sudo systemctl start my_service
        ```
    6. Enable the service to start at boot:
        ```bash
        sudo systemctl enable my_service
        ```
    7. Check the status of the service:
        ```bash
        sudo systemctl status my_service
        ```
    8. Stop the service:
        ```bash
        sudo systemctl stop my_service
        ```
    9. Disable the service from starting at boot:
        ```bash
        sudo systemctl disable my_service
        ```
- Use `journalctl -u my_service` to view logs for the service.
- Customize the service file to suit your application's requirements.
- Ensure the script or application has executable permissions.

### 10. Cron Jobs
- Automates repetitive tasks by scheduling commands or scripts to run at specific times or intervals.
- Uses the `crontab` command to manage cron jobs.
- Syntax for a cron job entry: `minute hour day month day_of_week command`.
- Example of a cron job: `0 2 * * 1 /path/to/script.sh` (Runs every Monday at 2:00 AM).
- `crontab -e`: Edits the current user's crontab file.
- `crontab -l`: Lists the current user's cron jobs.
- `crontab -r`: Removes the current user's crontab file.
- Special strings for scheduling:
    - `@reboot`: Runs once at system startup.
    - `@yearly` or `@annually`: Runs once a year.
    - `@monthly`: Runs once a month.
    - `@weekly`: Runs once a week.
    - `@daily`: Runs once a day.
    - `@hourly`: Runs once an hour.
- Logs for cron jobs can be found in `/var/log/syslog` or `/var/log/cron` (depending on the system).
- Use `cron.allow` and `cron.deny` files to control user access to cron.
- Debugging tips:
    - Ensure the script has executable permissions.
    - Use absolute paths for commands and files.
    - Redirect output to a log file for troubleshooting.
- Combine with `systemctl` to ensure the cron service is active: `systemctl status cron`.
- Explore alternatives like `anacron` for tasks that need to run even if the system was off.
- Leverage cron jobs for tasks like backups, monitoring, and maintenance.
- Test cron job commands manually before scheduling them.
- Use `crontab -u [user]` to manage cron jobs for a specific user (requires root privileges).
- Combine cron jobs with other tools like `rsync`, `tar`, or `scp` for advanced automation.
- Use `cron` in conjunction with monitoring tools to create proactive alerts.
- Leverage cron jobs to automate repetitive tasks and improve productivity.
- Experiment with different cron configurations to suit specific needs.
- Ensure the cron daemon is running: `systemctl start cron` or `service cron start`.
- Use `cron` to schedule tasks across distributed systems for coordinated workflows.

### 11. At Command
- Schedules a one-time task to run at a specific time using the `at` command.
- Syntax: `echo "[command]" | at [time]`.
- Example: `echo "ls -l" | at 14:00` (Runs `ls -l` at 2:00 PM).
- Use `atq` to view the list of pending jobs.
- Use `atrm [job_id]` to remove a scheduled job.
- Requires the `atd` service to be running: `systemctl start atd`.
- Supports various time formats:
    - `now + [minutes|hours|days|weeks]`.
    - Specific times like `HH:MM` or `midnight`, `noon`, etc.
- Logs for `at` jobs can be found in `/var/log/at` or `/var/spool/at` (depending on the system).
- Use `at.allow` and `at.deny` files to control user access to the `at` command.
- Combine with scripts to automate one-time tasks effectively.
- Useful for scheduling tasks that don't need to recur.
- Test commands manually before scheduling them with `at`.
- Ensure the `atd` daemon is active: `systemctl status atd`.
- Leverage the `at` command for quick, one-off task scheduling.
- Use `at` to complement cron jobs for flexible task scheduling.

### 12. Signals
- `kill -l`: Lists all available signals.
- Common signals:
    - `SIGTERM`: Gracefully terminates a process.
    - `SIGKILL`: Forcefully terminates a process.
    - `SIGHUP`: Restarts a process.
- writing C program to capture the number of signal called Simple_Shell.c


