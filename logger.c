#include <stdio.h>
#include <time.h>
#include "survsim.h"

// -------- LOGGING FUNCTION --------
void logEvent(const char *message) {
    FILE *fp = fopen("surv_log.txt", "a");   // open log in append mode

    if (fp == NULL) {
        printf("Error opening log file!\n");
        return;   // exit if file not available
    }

    time_t now = time(NULL);                  // get current timestamp
    char *timestamp = ctime(&now);            // convert to readable string

    fprintf(fp, "%s", message);               // write event message
    fprintf(fp, "Time: %s\n", timestamp);      // write timestamp
    fprintf(fp, "--------------------------\n");

    fclose(fp);   
}

void showLog() {
    FILE *fp = fopen("surv_log.txt", "r");
    if (!fp) {
        printf("No log file found.\n");
        return;
    }

    char line[256];
    printf("\n----- LOG FILE -----\n");
    
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("---------------------\n");

    fclose(fp);
}