#!/bin/bash

# Configuration
CSV_FILE="sensor_data.csv"
REMOTE_USER="ismail"
REMOTE_HOST="192.168.1.18"
REMOTE_DIR="~/Desktop"

while true; do
    echo "Transferring CSV file..."
    
    # Transfer file using SCP
    scp "$CSV_FILE" "${REMOTE_USER}@${REMOTE_HOST}:${REMOTE_DIR}" && \
    echo "Transfer successful" || echo "Transfer failed"
    
    echo "Waiting for next transfer..."
    sleep 60  # 1 minute interval
done
