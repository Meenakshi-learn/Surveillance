#include <stdio.h>
#include "survsim.h"

int main() {
    int choice;
  printf("\nSmart Surveillance System Simulator v1.4\n");

do {
    printf("\n========= MENU =========\n");
    printf("1. Add Camera\n");
    printf("2. Show Camera Status\n");
    printf("3. Simulate Motion Detection\n");
    printf("4. Show System Summary\n");
    printf("5. View Log File\n");
    printf("6. Change Alert Mode\n");
    printf("7. Show Recent Alerts\n");  // <-- NEW OPTION
    printf("8. Exit\n");               // <-- Exit moved to 8
    printf("Enter your choice: ");

    choice = safeReadInt();

    switch (choice) {
        case 1: addCamera(); break;
        case 2: showStatus(); break;
        case 3: simulateDetection(); break;
        case 4: displaySummary(); break;
        case 5: showLog(); break;

        case 6: {
            printf("\nSelect Alert Mode:\n");
            printf("1. Default Alert\n");
            printf("2. Loud Alert\n");
            printf("3. Silent Alert\n");
            printf("Enter choice: ");

            int mode = safeReadInt();

            if (mode == 1)      alertHandler = defaultAlertHandler;
            else if (mode == 2) alertHandler = loudAlertHandler;
            else if (mode == 3) alertHandler = silentAlertHandler;
            else printf("Invalid mode!\n");

            printf("Alert mode updated!\n");
            break;
        }

        case 7:
            showAlertStack();
            break;

        case 8:
            printf("System shutting down... Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
    }

} while (choice != 8);

    return 0;
}