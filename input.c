#include <stdio.h>
#include <string.h>
#include "survsim.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int safeReadInt() {
    int value;
    while (1) {
        if (scanf("%d", &value) == 1) {
            clearInputBuffer();
            return value;
        }
        printf("Invalid input! Enter a number: ");
        clearInputBuffer();
    }
}

void safeReadString(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}
