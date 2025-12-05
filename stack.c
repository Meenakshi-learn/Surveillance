#include <stdio.h>
#include <string.h>
#include "survsim.h"

char alertStack[MAX_ALERTS][200];
int top = -1;

void pushAlert(const char *msg) {
    if (top < MAX_ALERTS - 1) {
        strcpy(alertStack[++top], msg);
    }
}

void popAlert() {
    if (top >= 0) {
        top--;
    }
}

void showAlertStack() {
    if (top == -1) {
        printf("Alert Stack is empty.\n");
        return;
    }

    printf("\n--- Recent Alerts (Stack) ---\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", alertStack[i]);
    }
    printf("-----------------------------\n");
}
