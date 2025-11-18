#include <stdio.h>
#include "survsim.h"

void displaySummary() {
    printf("\n========= SYSTEM SUMMARY =========\n");
    printf("Total Cameras Registered: %d\n", totalCameras);
    printf("Total Alerts Triggered: %d\n", alertCount);
    printf("==================================\n");
}
