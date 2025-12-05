#ifndef SURVSIM_H
#define SURVSIM_H

#include <stdbool.h>
#define MAX_ALERTS 10
// ---------- TYPEDEF ENUM ----------

typedef enum {
    CAMERA_INACTIVE,
    CAMERA_ACTIVE
} CameraStatus;

typedef enum {
    MOTION_CLEAR,
    MOTION_DETECTED
} MotionState;

// ---------- TYPEDEF STRUCT ----------
typedef struct {
    int id;
    char location[50];
    CameraStatus status;
    MotionState motion;
} Camera;

// ---------- CALLBACK FUNCTION POINTER ----------
typedef void (*AlertCallback)(Camera *cam);

// ---------- GLOBAL VARIABLES ----------
extern Camera cameras[5];
extern int totalCameras;
extern int alertCount;
extern const char *validLocations[6];
extern const int totalValidLocations;
extern AlertCallback alertHandler;
extern char alertStack[MAX_ALERTS][200];
extern int top;
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

void pushAlert(const char *msg);
void popAlert();
void showAlertStack();

// Callback handlers
void defaultAlertHandler(Camera *cam);
void loudAlertHandler(Camera *cam);
void silentAlertHandler(Camera *cam);

#endif
