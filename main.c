#include <stdio.h>
#include "survsim.h"

int main() {
    int choice;
    printf("\nSmart Surveillance System Simulator v1.2\n");

    do {
        printf("\n========= MENU =========\n");
        printf("1. Add Camera\n");
        printf("2. Show Camera Status\n");
        printf("3. Simulate Motion Detection\n");
        printf("4. Show System Summary\n");
        printf("5. View Log File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        choice = safeReadInt();  // safe input

        switch (choice) {
            case 1: addCamera(); break;
            case 2: showStatus(); break;
            case 3: simulateDetection(); break;
            case 4: displaySummary(); break;
            case 5: showLog(); break;   // NEW: show log file on terminal
            case 6: 
                printf("System shutting down... Goodbye!\n");
                break;

            default: 
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}