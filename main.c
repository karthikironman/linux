#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
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

// Function to print system information
void printSystemInfo() {
    struct sysinfo sys_info;
    sysinfo (&sys_info);

    // Print total RAM
    printf("Total RAM: %lu MB\n", sys_info.totalram / (1024 * 1024));

    // Print free RAM
    printf("Free RAM: %lu MB\n", sys_info.freeram / (1024 * 1024));

    // Print total swap space
    printf("Total Swap Space: %lu MB\n", sys_info.totalswap / (1024 * 1024));

    // Print free swap space
    printf("Free Swap Space: %lu MB\n", sys_info.freeswap / (1024 * 1024));
}

// Function to print IP address
void printIpAddress() {
    int sock;
    struct ifreq ifr;
    char ip[INET_ADDRSTRLEN];

    // Create a socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return;
    }

    // Get IP address of the first network interface
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ);
    if (ioctl(sock, SIOCGIFADDR, &ifr) < 0) {
        perror("ioctl");
        close(sock);
        return;
    }

    // Convert IP address to string
    inet_ntop(AF_INET, &((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr, ip, INET_ADDRSTRLEN);
    printf("IP Address: %s\n", ip);

    // Close the socket
    close(sock);
}

int main() {
    int choice;

    printf("Architecture Information:\n");
    printArchitectureInfo();

    printf("\nSystem Information:\n");
    printSystemInfo();

    printf("\nIP Address:\n");
    printIpAddress();

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