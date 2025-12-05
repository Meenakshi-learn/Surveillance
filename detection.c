#include <stdio.h>
#include "survsim.h"

// Global function pointer initialized to default handler
AlertCallback alertHandler = defaultAlertHandler;


// -------- SIMULATE DETECTION ----------
void simulateDetection() {
    int camID;
    printf("Enter Camera ID to simulate motion: ");

    camID = safeReadInt();   // safe integer input

    if (camID <= totalCameras && camID > 0) {
        cameras[camID - 1].motion = MOTION_DETECTED;
        triggerAlert(&cameras[camID - 1]);
    } else {
        printf("Invalid camera ID.\n");
    }
}


// -------- TRIGGER ALERT USING CALLBACK ----------
void triggerAlert(Camera *cam) {
    alertCount++;

    // Call selected alert handler callback
    alertHandler(cam);

    // Log common alert data
    char logMsg[200];
    sprintf(logMsg,
            "ALERT #%d\nCamera: %s (ID %d)\n",
            alertCount, cam->location, cam->id);

    logEvent(logMsg);
}


// -------- CALLBACK IMPLEMENTATIONS ----------

// DEFAULT MODE
void defaultAlertHandler(Camera *cam) {
    printf("\n[DEFAULT ALERT] Motion detected at %s (Camera %d)\n",
           cam->location, cam->id);

    logEvent("Default alert handler executed.\n");
}


// LOUD MODE
void loudAlertHandler(Camera *cam) {
    printf("\n LOUD ALERT! Motion at %s (Camera %d)\n",
           cam->location, cam->id);

    logEvent("Loud alert handler executed.\n");
}


// SILENT MODE
void silentAlertHandler(Camera *cam) {
    printf("\n(Silent Mode) Motion detected at %s (Camera %d)\n",
           cam->location, cam->id);

    logEvent("Silent alert handler executed.\n");
}