# Linux Revision Course

Welcome to the **User and Permissions Section**!

## All of the commands we used

### 1. Su
- Switch to the root user to perform administrative tasks.
- Execute commands with elevated privileges.
- Troubleshoot permission issues by temporarily assuming another user's identity.
- Test configurations or scripts as a different user.
- Manage system services and processes that require root access.
- Modify system files and configurations located in restricted directories.
- Access logs and system information that require elevated permissions.
- Perform user management tasks, such as adding or removing users.
- Debug embedded Linux systems by accessing restricted resources.

### 2. Adding Users

#### A. User Add
- Create a new user account on the system.
- Assign a default home directory for the user.
- Set up initial configurations for the new user.
- Specify a unique user ID (UID) if needed.
- Add the user to specific groups for access control.
- Configure shell preferences for the user.
- Ensure proper permissions for the user's home directory.
- Automate user creation with predefined templates or scripts.

#### B. User Mod
- Modify existing user account details.
- Change the user's home directory location.
- Update the user's login shell.
- Add or remove the user from groups.
- Lock or unlock the user account.
- Change the user's UID or group ID (GID).
- Rename the user account if required.
- Adjust account expiration settings.

#### C. User Del
- Remove a user account from the system.
- Optionally delete the user's home directory and files.
- Ensure no processes are running under the user's account.
- Clean up any residual files or configurations.
- Reassign ownership of files to another user if necessary.
- Verify the removal of the user from all groups.
- Audit system logs for any activity by the deleted user.

#### D. Group Add
- Create a new group on the system.
- Assign a unique group ID (GID) to the group.
- Add users to the group for shared access.
- Manage group memberships for collaboration.
- Set group ownership for files and directories.
- Use groups to simplify permission management.
- Apply group-based access control for resources.
- Automate group creation with scripts or templates.
- Ensure proper group configurations for security.

#### E. gpasswd
- Administer group passwords for enhanced security.
- Restrict access to groups with password protection.
- Delegate group administration to specific users.
- Remove group passwords when no longer needed.
- Use `gpasswd` to manage group membership interactively.

#### F. /etc/passwd, /etc/group, /etc/shadow
- `/etc/passwd`: Contains user account information, such as usernames, UIDs, and home directories.
- `/etc/group`: Lists groups and their associated GIDs, along with group memberships.
- `/etc/shadow`: Stores encrypted user passwords and password aging information.
- Use `cat`, `less`, or `grep` to view these files.
- Modify these files cautiously using tools like `vipw` or `vigr`.
- Ensure proper permissions to protect sensitive information.
- Audit these files for unauthorized changes or inconsistencies.
- Automate user and group management with scripts.
- Backup these files regularly to prevent data loss.

and there is much MUCH more...

### 3. File Permissions

#### A. Chmod
- Change file or directory permissions.
- Use symbolic or numeric modes to set permissions.
- Grant or revoke read, write, and execute access.
- Apply recursive changes to directories.
- Secure sensitive files by restricting access.
- Enable executable permissions for scripts or binaries.
- Adjust permissions for shared resources.

#### B. Chown
- Change ownership of files or directories.
- Assign a new owner to a file.
- Modify the group ownership of a file.
- Combine owner and group changes in one command.
- Apply recursive ownership changes to directories.
- Transfer ownership of files between users.
- Ensure proper ownership for system-critical files.

#### C. Chgrp
- Change the group ownership of files or directories.
- Assign a file to a specific group.
- Apply recursive group changes to directories.
- Manage shared resources by adjusting group ownership.
- Ensure group permissions align with access requirements.
- Simplify collaboration by grouping related files.
- Verify group ownership changes with `ls -l`.

#### D. Chage
- Modify password aging policies for user accounts.
- Set account expiration dates for temporary users.
- Enable or disable password expiration warnings.
- Audit password aging settings with `chage -l`.
- Automate password aging configurations with scripts.
- Ensure compliance with security policies using `chage`.
- Use `chage` to enforce password change intervals.
- Prevent unauthorized access by locking inactive accounts.
- Configure minimum and maximum password age limits.
- Update user account expiration dates interactively.
- Verify password expiration settings for all users.
- Enhance security by enforcing regular password updates.
- Manage account inactivity periods with `chage`.
- Troubleshoot account expiration issues effectively.
- Document password aging policies for system audits.

### 4. DAC
#### A. Basic Permissions
- Understand the three permission types: read (r=4), write (w=2), and execute (x=1).
- Represent permissions symbolically as `rwx` for read, write, and execute.
- Use numerical values: `4` for read, `2` for write, and `1` for execute.
- Combine numerical values to set permissions (e.g., `7` for `rwx`, `6` for `rw-`).
- Example: `chmod 755 file` sets `rwxr-xr-x` permissions.
- Symbolic example: `chmod u+rwx,g+rx,o+rx file`.
- Use `ls -l` to view symbolic permissions.
- Use `stat` to view numerical permissions.
- Apply permissions recursively with `chmod -R`.
- View file permissions using `ls -l`.
- Modify permissions with `chmod` using symbolic or numeric modes.
- Set default permissions for new files and directories with `umask`.
- Restrict access to sensitive files by adjusting permissions.
- Grant execute permissions to scripts or binaries.
- Use `chmod -R` to apply changes recursively to directories.
- Verify permission changes with `ls -l`.
- Troubleshoot permission issues by analyzing file ownership and permissions.
- Combine permissions to create custom access rules.
- Use `chmod` to remove write permissions for critical files.
- Apply read-only permissions to shared resources.
- Secure directories by restricting execute permissions.
- Manage permissions for collaborative projects effectively.

#### B. Special Permissions
- Understand and apply the `setuid` permission to allow executables to run with the file owner's privileges.
- Use the `setgid` permission to ensure files created in a directory inherit the group ownership.
- Apply the `sticky bit` to directories to restrict file deletion to the file owner or root.
- Use `chmod` with symbolic modes (`u+s`, `g+s`, `o+t`) to set special permissions.
- Verify special permissions with `ls -l` (e.g., `s` for `setuid`/`setgid`, `t` for sticky bit).
- Secure shared directories by enabling the sticky bit to prevent unauthorized file deletions.
- Combine special permissions with standard permissions for advanced access control.
- Document the use of special permissions for compliance and security audits.
- Avoid misuse of `setuid` and `setgid` to minimize security risks.
- Use `chmod` to remove/add necessary special permissions when required.
- Enhance system security by limiting the use of `setuid` and `setgid` binaries.
- Ensure proper ownership and permissions for files with special attributes.
- Integrate special permissions into your overall security strategy effectively.

#### C. ACL
- Extend file permissions beyond the traditional user-group-other model.
- Grant or deny specific permissions to individual users or groups.
- Use `setfacl` to add or modify ACL entries for files and directories.
- View existing ACLs with the `getfacl` command.
- Apply default ACLs to directories to ensure inherited permissions.
- Remove all ACL entries with `setfacl -b`.
- Combine ACLs with standard permissions for granular access control.
- Troubleshoot access issues by analyzing ACL configurations.
- Use `chmod` and `setfacl` together for advanced permission setups.
- Automate ACL management with scripts for consistency.
- Restricts the maximum permissions for users and groups in ACLs.
- Use `setfacl -m m::rwx <file>` to set the mask.
- View the mask with `getfacl <file>`.
- Adjust the mask to control access without modifying individual ACL entries.
- Ensure the mask aligns with security policies for shared resources.
- Defines permissions inherited by new files and directories.
- Use `setfacl -d -m u:<user>:rwx <directory>` to set default ACLs.
- View default ACLs with `getfacl <directory>`.
- Apply default ACLs to directories for consistent permission inheritance.
 - Combine default ACLs with standard permissions for advanced setups.

### 5. MAC (Selinux)
#### Enforcing Mode
- Use `getenforce` to check the current SELinux mode.
- Switch to enforcing mode with `setenforce 1`.
- Enforcing mode applies all SELinux policies strictly.
- Ensure system security by enforcing mandatory access controls.
- Verify the mode change with `getenforce`.

#### Permissive Mode
- Switch to permissive mode with `setenforce 0`.
- Permissive mode logs policy violations without enforcing them.
- Use permissive mode for troubleshooting SELinux issues.
- Analyze SELinux logs in `/var/log/audit/audit.log` for violations.
- Return to enforcing mode after resolving issues.

#### SELinux Policies
- List all SELinux booleans with `getsebool -a`.
- Enable or disable specific booleans with `setsebool <boolean> on/off`.
- Use `setsebool -P <boolean> on/off` to make changes persistent.
- Customize SELinux behavior by toggling policy booleans.
- Example: Enable HTTPD scripts with `setsebool -P httpd_enable_cgi on`.
- Audit SELinux policy changes for compliance and security.
- and much MUCH more...

#### Troubleshooting SELinux
- Use `sestatus` to view SELinux status and policy details.
- Check for denied actions in `/var/log/audit/audit.log`.
- Use `audit2allow` to generate custom policies for denied actions.
- Temporarily disable SELinux for critical troubleshooting with `setenforce 0`.
- Re-enable SELinux after resolving issues to maintain security.

These commands and concepts help manage SELinux effectively, ensuring a secure and controlled environment.

### 6. Sudo
- Execute commands with elevated privileges as a non-root user.
- Configure `sudo` access in the `/etc/sudoers` file.
- Use `visudo` to safely edit the sudoers file.
- Grant specific commands to users with `sudo`.
- Log all `sudo` activities for auditing purposes.
- Limit `sudo` access to specific users or groups.
- Enhance security by avoiding direct root login.
- The `sudoers` file controls and defines who can use `sudo` and what commands they can execute.
- Use `visudo` to safely edit the `/etc/sudoers` file and avoid syntax errors.
- Grant specific users or groups access to administrative commands.
- Example: Add a user to the sudoers file with `username ALL=(ALL) ALL`.
- Restrict `sudo` access to specific commands for enhanced security.
- Use aliases to group commands, users, or hosts for easier management.
- Log all `sudo` activities for auditing and compliance purposes.
- Test sudo configurations with `sudo -l` to list allowed commands for a user.
- Avoid granting unrestricted `sudo` access to minimize security risks.
- Use `sudo` with care to prevent accidental system changes.
- Combine `sudo` with password policies for additional security.
- Document sudoers configurations for team collaboration and audits.
- Automate sudoers management with configuration management tools like Ansible.
- Regularly review and update the sudoers file to ensure it aligns with current security policies.
- Example of a restricted command: `username ALL=(ALL) NOPASSWD: /usr/bin/systemctl restart apache2`.
- Use `Defaults` options in the sudoers file to customize sudo behavior (e.g., `Defaults timestamp_timeout=5`).
- Ensure the sudoers file has proper permissions (`chmod 440 /etc/sudoers`) to prevent unauthorized modifications.
- Troubleshoot sudo issues by checking `/var/log/auth.log` or `/var/log/secure`.
- Enhance security by limiting the use of `NOPASSWD` where possible.
- Use `sudoedit` for secure file editing with elevated privileges.
- and much MUCH more...

### 7. Groups
- Organize users into groups for access control.
- Create new groups with `groupadd`.
- Add users to groups with `usermod -aG`.
- Remove users from groups with `gpasswd` or `deluser`.
- List group memberships with `groups` or `id`.
- Manage group passwords with `gpasswd`.
- Use groups to simplify permission management.

### 8. Password Management
- Change user passwords with `passwd`.
- Enforce password policies for security.
- Lock or unlock user accounts with `passwd -l` or `passwd -u`.
- Expire passwords to force a reset on next login.
- Configure password aging policies in `/etc/login.defs`.
- Audit password changes in system logs.
- Use strong passwords to enhance account security.
- Implement multi-factor authentication for critical accounts.

