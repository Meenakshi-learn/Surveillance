#include <stdio.h>
#include "survsim.h"

// -------- SIMULATE DETECTION ----------
void simulateDetection() {
    int camID;
    printf("Enter Camera ID to simulate motion: ");
    scanf("%d", &camID);

    if (camID <= totalCameras && camID > 0) {
        cameras[camID - 1].motionDetected = true;
        triggerAlert(&cameras[camID - 1]);
    } else {
        printf("Invalid camera ID.\n");
    }
}

void triggerAlert(Camera *cam) {
    alertCount++;
    printf("\nALERT! Motion detected at %s (Camera %d)\n",
           cam->location, cam->id);

    char logMsg[200];
    sprintf(logMsg,
            "ALERT #%d\nCamera: %s (ID %d)\n",
            alertCount, cam->location, cam->id);

    logEvent(logMsg);
}