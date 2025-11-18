#ifndef SURVSIM_H
#define SURVSIM_H

#include <stdbool.h>

// ---------- TYPEDEF STRUCT ----------
typedef struct {
    int id;
    char location[50];
    bool isActive;
    bool motionDetected;
} Camera;

// ---------- GLOBAL VARIABLES ----------
extern Camera cameras[5];
extern int totalCameras;
extern int alertCount;

// ---------- FUNCTION PROTOTYPES ----------
void addCamera();
void showStatus();
void simulateDetection();
void triggerAlert(Camera *cam);
void displaySummary();
void logEvent(const char *message);

#endif
