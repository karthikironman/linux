#include <stdio.h>
#include "menu.h"
#include "utils.h"

int main() {
    int choice;

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
