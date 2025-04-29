# Linux Revision Course

Welcome to the **Network Section**!

## All of the commands we used

### 1. Ip/Ifconfig
- Bring the link Up/Down.
- Display all addresses associated with the interface.
- Add new addresses to the interface.
- Remove addresses from the interface.
- View detailed information about the interface.
- Enable or disable promiscuous mode.
- And more...

### 2. Nmcli
- Show all interfaces and their statuses.
- Control and display active and inactive connections.
- Display detailed information about a specific interface or device.
- Add new IP addresses to an interface.
- Modify configuration files for network connections.
- Bring specific IP addresses or interfaces Up/Down.
- Connect or disconnect from a network interface.
- Modify IP addresses or interface settings dynamically.
- Delete IP addresses from an interface.
- Check the status of all interfaces.
- Verify and manage firewall zones associated with an interface.
- Troubleshoot network connectivity issues.
- And much more...

### 3. Hostname
- Print the current hostname.
- Change the hostname temporarily.
- Change the hostname permanently.
- Check and modify its configuration file.
- Verify the hostname resolution.
- Troubleshoot hostname-related issues.
- And more...

### 4. SSH
- Understand symmetric and asymmetric encryption in SSH.
- Generate public and private key pairs for secure authentication.
- Configure and modify SSH configuration files (`/etc/ssh/sshd_config` and `~/.ssh/config`).
- Set up passwordless authentication using SSH keys.
- Secure SSH by disabling root login and changing the default port.
- Use SSH for remote command execution.
- Establish SSH tunnels for secure data transfer.
- Troubleshoot common SSH connection issues.
- And much more...
### 5. Nslookup
- Query DNS records for a specific domain.
- Perform reverse DNS lookups.
- Specify a DNS server for queries.
- Troubleshoot DNS resolution issues.
- Modify and use the `/etc/resolv.conf` configuration file.
- Check and verify DNS propagation.
- And much more...

### 6. Archive and Compress
- Use `tar` to create and extract archives.
- Combine `tar` with compression tools like `gzip`, `xz`, or `bzip2` for efficient storage.
- Compress and decompress files using `gzip`, `xz`, and `bzip2` individually.
- Extract files to a specific location using `tar` or other tools.
- View the contents of an archive without extracting it.
- Create incremental backups using `tar`.
- Verify the integrity of compressed files.
- Troubleshoot issues with corrupted archives.
- And much more...

### 7. Remote Backup
- Use `rsync`, `scp`, and `sftp` for secure file transfers.
- Copy and remove files, including compressed files, between devices.
- Download and upload files between two devices efficiently.
- Synchronize directories while preserving permissions, timestamps, and symbolic links.
- Perform incremental backups to save bandwidth and time.
- Automate backup tasks using scripts and cron jobs.
- Verify file integrity during transfers.
- Troubleshoot common issues with remote backups.
- And much more...
### 8. Disk Management
- List and display storage devices and their details.
- View and manage mount points for partitions and devices.
- Add and remove partitions using tools like `fdisk` or `gdisk` or `parted`.
- Resize existing partitions without data loss.
- Format disks or partitions with specific file systems (e.g., `ext4`, `xfs`, `ntfs`).
- Create and manage Logical Volumes (LV) using LVM.
- Mount and unmount disks or partitions dynamically.
- Create and resize swap space for improved memory management.
- Set swap priorities and format swap file systems.
- Troubleshoot disk-related issues and errors.
- And much more...

### 9. NFS
- Create a temporary NFS share manually.
- Set up a permanent NFS share for persistent use.
- Configure the NFS server and client for seamless communication.
- Mount NFS shares automatically during system boot.
- Manage permissions and access control for NFS shares.
- Optimize NFS performance for large-scale deployments.
- Troubleshoot common NFS connectivity and performance issues.

### 10. Autofs
- Install and configure the `autofs` package.
- Set up automatic mounting of file systems on demand.
- Define mount points and options in the `auto.master` and `auto.*` configuration files.
- Use wildcards for dynamic mounting of multiple directories.
- Test and verify the functionality of `autofs` mounts.
- Troubleshoot common issues with `autofs` configurations.
- Optimize `autofs` for performance and reliability.
- And much more...

### 11. Firewall
- Add, remove, and list firewall rules dynamically.
- Create and manage custom zones for specific network interfaces.
- Allow or block specific ports and protocols.
- Enable or disable masquerading for NAT configurations.
- Save and restore firewall configurations persistently.
- Monitor and log firewall activity for security auditing.
- Create new firewall zones for specific use cases.
- Modify existing firewall zones to update rules or settings.
- And much more...

### 12. Ping
- Test network connectivity to a specific host or IP address.
- Measure round-trip time for packets sent to a host.
- Specify the number of packets to send.
- Set the packet size for testing purposes.
- Use continuous ping to monitor network stability.
- Limit the time for pinging a host.
- Troubleshoot network latency and packet loss issues.
- Verify DNS resolution by pinging domain names.
- And much more...

### 13. Telnet
- Connect to remote servers using the Telnet protocol.
- Test and troubleshoot network services on specific ports.
- Establish interactive sessions with remote systems.
- Verify open ports and service availability.
- Use Telnet for debugging and testing purposes.
- Troubleshoot connectivity issues in network environments.
- And much more...

### 14. Traceroute
- Trace the route packets take to reach a destination.
- Identify network hops and their response times.
- Troubleshoot network routing issues.
- Specify the maximum number of hops to trace.
- Use different protocols (e.g., ICMP, UDP) for tracing.
- Analyze latency and packet loss at each hop.
- Resolve IP addresses to hostnames for better readability.
- And much more...

### 15. Curl
- Perform HTTP/HTTPS requests to test APIs and websites.
- Download files from remote servers.
- Send custom headers and payloads in requests.
- Authenticate using basic or token-based authentication.
- Test and debug RESTful APIs.
- Follow redirects automatically.
- Save response headers and bodies to files.
- And much more...

### 16. Package Management
- Install, update, and remove packages using `apt`, `yum`, or `dnf`.
- Search for packages in repositories.
- Manage package dependencies.
- Add or remove third-party repositories.
- Upgrade the entire system to the latest version.
- Verify package integrity and authenticity.
- And much more...