#!/bin/bash

Source_DIR="/home/ismail/maindir"
Backup_DIR="/home/ismail/backup"
Log_FILE="/home/ismail/backup/backup.log"
Timestamp=$(date +"%Y-%m-%d %H:%M:%S")
Backupfilename="backup_$Timestamp.tar.gz"

if [ ! -d "$Source_DIR" ]; then
    echo "Source directory does not exist. Exiting." >> "$Log_FILE"
    exit 1
fi
if [ ! -d "$Backup_DIR" ]; then
    echo "Backup directory does not exist. Creating it." >> "$Log_FILE"
    exit 1
fi
echo "Starting backup at $Timestamp" >> "$Log_FILE"
tar -czf "$Backup_DIR/$Backupfilename" "$Source_DIR"

find "$Backup_DIR" -type f -name "backup_*.tar.gz" -mtime +7 -delete

if [ $? -eq 0 ]; then
    echo "Backup completed successfully at $(date +"%Y-%m-%d %H:%M:%S")" 
else
    echo "Backup failed at $(date +"%Y-%m-%d %H:%M:%S")" >> "$Log_FILE"
fi