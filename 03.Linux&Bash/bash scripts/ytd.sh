#!/bin/bash

download_videos(){
    videourl=$1
    outputdir="ytdownload"

    echo "Downloading video from $videourl..."
    yt-dlp -f 'bestvideo+bestaudio' --merge-output-format mp4 -o "$outputdir/%(title)s.%(ext)s" "$videourl"
    if [ $? -eq 0 ]; then
        echo "Download completed successfully."
    else
        echo "Download failed."
    fi
}



download_videos $1
