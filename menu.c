#include <stdio.h>
#include "menu.h"
#include "utils.h"

void displayMenu() {
    clearScreen();
    printf("-------------------------------\n");
    printf("         Hello World           \n");
    printf("-------------------------------\n");
    printf("1. Print Hello World           \n");
    printf("2. Print BeagleBone Message    \n");
    printf("3. Exit                        \n");
    printf("-------------------------------\n");
    printf("Choose an option: ");
}

void printHelloWorld() {
    clearScreen();
    printf("Hello, World!\n");
    pauseProgram();
}

void printBeagleBoneMessage() {
    clearScreen();
    printf("Hello from BeagleBone!\n");
    pauseProgram();
}

void exitProgram() {
    clearScreen();
    printf("Exiting...\n");
}

void printInvalidChoice() {
    clearScreen();
    printf("Invalid choice. Please choose again.\n");
    pauseProgram();
}
