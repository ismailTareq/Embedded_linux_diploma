#include <wiringPi.h>
#include <stdio.h>
#include <curl/curl.h>

#define BUTTON_PIN 4
#define LED_PIN 0  

void downloadFile() {
    CURL *curl;
    CURLcode res;
    FILE *fp;

    // Update with your server URL and filename
    char *url = "http://192.168.1.16/download.php?file=example.txt";
    char outfile[100];
    sprintf(outfile, "/home/pi/downloads/downloaded_file.txt");

    curl = curl_easy_init();
    if(curl) {
        fp = fopen(outfile, "wb");
        if(fp == NULL) {
            printf("Failed to open file for writing\n");
            return;
        }
        
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("File downloaded successfully\n");
            digitalWrite(LED_PIN, HIGH); 
        }
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

int main() {
    if (wiringPiSetup() == -1) {
        printf("WiringPi setup failed!\n");
        return 1;
    }

    // Initialize button pin
    pinMode(BUTTON_PIN, INPUT);
    pullUpDnControl(BUTTON_PIN, PUD_UP);
    
    // Initialize LED pin
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); 

    printf("Waiting for button press...\n");
    
    while(1) {
        if (digitalRead(BUTTON_PIN) == LOW) { 
            printf("Button pressed, downloading file...\n");
            downloadFile();
            delay(1000); // Debounce delay
            break; 
        }
        delay(100);
    }

    return 0;
}
