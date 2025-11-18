#include <stdio.h>
#include <string.h>
#include "survsim.h"

// ------- GLOBAL DEFINITIONS ----------
Camera cameras[5];
int totalCameras = 0;
int alertCount = 0;

// -------- ADD CAMERA ----------
void addCamera() {
    if (totalCameras < 5) {
        Camera cam;   // using typedef

        cam.id = totalCameras + 1;

        printf("Enter camera location: ");
        scanf("%s", cam.location);

        cam.isActive = true;
        cam.motionDetected = false;

        cameras[totalCameras] = cam;
        totalCameras++;

        printf("Camera added successfully!\n");
    } else {
        printf("Max camera limit reached!\n");
    }
}

// -------- SHOW CAMERA STATUS ----------
void showStatus() {
    register int i;
    printf("\nCamera Status:\n");

    for (i = 0; i < totalCameras; i++) {
        printf("ID: %d | Location: %s | Status: %s | Motion: %s\n",
               cameras[i].id,
               cameras[i].location,
               cameras[i].isActive ? "Active" : "Inactive",
               cameras[i].motionDetected ? "Detected" : "Clear");
    }
}
