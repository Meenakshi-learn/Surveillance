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
extern const char *validLocations[6];
extern const int totalValidLocations;

// ---------- FUNCTION PROTOTYPES ----------
void addCamera();
void showStatus();
void simulateDetection();
void triggerAlert(Camera *cam);
void displaySummary();
void logEvent(const char *message);
void clearInputBuffer();
int safeReadInt();
void safeReadString(char *buffer, int size);
void showLog();
int isValidLocation(const char *loc);
#endif
