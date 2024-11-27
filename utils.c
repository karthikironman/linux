#include <stdio.h>
#include "utils.h"

void clearScreen() {
    printf("\033[2J\033[1;1H");
}

void pauseProgram() {
    printf("Press Enter to continue...");
    getchar();
}
