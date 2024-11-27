#include <stdio.h>
#include "menu.h"
#include "utils.h"

// Function to print architecture information
void printArchitectureInfo() {
    #ifdef _WIN32
        printf("Operating System: Windows\n");
    #elif _WIN64
        printf("Operating System: Windows 64-bit\n");
    #elif __unix || __unix__
        printf("Operating System: Unix-based (e.g., Linux, macOS)\n");
    #elif __APPLE__ || __MACH__
        printf("Operating System: macOS\n");
    #elif __linux__
        printf("Operating System: Linux\n");
    #else
        printf("Operating System: Unknown\n");
    #endif

    #ifdef __x86_64__
        printf("CPU Architecture: x86-64\n");
    #elif __i386__
        printf("CPU Architecture: x86\n");
    #elif __arm__
        printf("CPU Architecture: ARM\n");
    #elif __aarch64__
        printf("CPU Architecture: ARM64\n");
    #else
        printf("CPU Architecture: Unknown\n");
    #endif
}

int main() {
    int choice;

    printf("Architecture Information:\n");
    printArchitectureInfo();

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printHelloWorld();
                break;
            case 2:
                printBeagleBoneMessage();
                break;
            case 3:
                exitProgram();
                return 0;
            default:
                printInvalidChoice();
                break;
        }
    }

    return 0;
}
