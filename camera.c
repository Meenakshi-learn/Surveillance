#include <stdio.h>
#include <string.h>
#include "survsim.h"

// ------- GLOBAL DEFINITIONS ----------
Camera cameras[5];
int totalCameras = 0;
int alertCount = 0;

// ------- VALID LOCATIONS ----------
const char *validLocations[6] = {
    "Entrance",
    "LivingRoom",
    "Kitchen",
    "Hallway",
    "Garage",
    "Backyard"
};

const int totalValidLocations = 6;

// ------- LOCATION VALIDATION ----------
int isValidLocation(const char *loc) {
    for (int i = 0; i < totalValidLocations; i++) {
        if (strcmp(loc, validLocations[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// -------- ADD CAMERA ----------
void addCamera() {
    if (totalCameras < 5) {
        Camera cam;
        cam.id = totalCameras + 1;

        printf("\nSelect Camera Location from the list below:\n");
        for (int i = 0; i < totalValidLocations; i++) {
            printf("%d. %s\n", i + 1, validLocations[i]);
        }

        char inputLocation[50];

        while (1) {
            printf("Enter location exactly as shown: ");
            safeReadString(inputLocation, sizeof(inputLocation));

            if (isValidLocation(inputLocation)) {
                strcpy(cam.location, inputLocation);
                break;
            } else {
                printf(" Invalid location! Please choose from the defined list.\n");
            }
        }

        cam.status = CAMERA_ACTIVE;
        cam.motion = MOTION_CLEAR;

        cameras[totalCameras] = cam;
        totalCameras++;

        printf("Camera added successfully!\n");
    } else {
        printf("Max camera limit reached!\n");
    }
}

// -------- SHOW CAMERA STATUS ----------
void showStatus() {
    printf("\nCamera Status:\n");
    for (int i = 0; i < totalCameras; i++) {
        printf("ID: %d | Location: %s | Status: %s | Motion: %s\n"),
               cameras[i].id,
               cameras[i].location,
               cameras[i].status == CAMERA_ACTIVE ? "Active" : "Inactive",

              cameras[i].motion == MOTION_DETECTED ? "Detected" : "Clear";
    }
}
