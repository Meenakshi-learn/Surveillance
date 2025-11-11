// SurvSim: Smart Surveillance System Simulator v1.0
// Author: Meenakshi
// Date: November 2025
// Description: Console-based simulation of an AI-driven surveillance backend
// Concepts: arrays, loops, structures, functions, storage classes, pointers, decision making

#include<stdio.h>
#include<string.h>
#include <stdbool.h>

//Structure to hold Camera info
//camera database
struct Camera {
    int id;
    char location[50];
    bool isActive;  // for active/inactive state
    bool motionDetected; // for detection flag
};

// Static variables retain system state across function calls
static struct Camera cameras[5];
static int totalCameras = 0;
static int alertCount = 0;

// Function declarations
void addCamera();
void showStatus();
void simulateDetection();
void triggerAlert(struct Camera *cam);
void displaySummary();

// Function definitions

// To add new camera
/*Create a new camera record 
 * → mark it active → set motion to “no” 
 * → store it in your camera database 
 * → update the total count. */

void addCamera() {
  if (totalCameras < 5) {
        struct Camera cam;
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

// Function to show camera status

void showStatus() {
    register int i;  // register variable for faster loop iteration
    printf("\n Camera Status:\n");

    for (i = 0; i < totalCameras; i++) {
        printf("ID: %d | Location: %s | Status: %s | Motion: %s\n",
            cameras[i].id,
            cameras[i].location,
            cameras[i].isActive ? "Active" : "Inactive",
            cameras[i].motionDetected ? "Detected" : "Clear");
        }
    }

    // Simulate motion detection

    void simulateDetection() {
        int camID;
        printf("Enter Camera ID to simulate motion: ");
        scanf("%d", &camID);
        if (camID <= totalCameras && camID > 0) {
        cameras[camID - 1].motionDetected = 1;
        triggerAlert(&cameras[camID - 1]);
    } else {
        printf("Invalid camera ID.\n");
    }
}

// Trigger alert for motion
void triggerAlert(struct Camera *cam) {
    alertCount++;
    printf("\nALERT! Motion detected at %s (Camera %d)\n",
           cam->location, cam->id);
}

// Show system summary
void displaySummary() {
    printf("\n========= SYSTEM SUMMARY =========\n");
    printf("Total Cameras Registered: %d\n", totalCameras);
    printf("Total Alerts Triggered: %d\n", alertCount);
    printf("==================================\n");
}

int main() {
    int choice;
    printf("\n Smart Surveillance System Simulator v1.0\n");

    do {
        printf("\n========= MENU =========\n");
        printf("1. Add Camera\n");
        printf("2. Show Camera Status\n");
        printf("3. Simulate Motion Detection\n");
        printf("4. Show System Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCamera(); break;
            case 2: showStatus(); break;
            case 3: simulateDetection(); break;
            case 4: displaySummary(); break;
            case 5: printf("System shutting down... Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}