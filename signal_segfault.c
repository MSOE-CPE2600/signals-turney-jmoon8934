/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: 
 * Jeric Moon, CPE2600 111
 * 11/10/2025
 * Brief summary of modifications:
 * Included new signal handler method and added a signal check.
 * Added more includes 
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGSEGV  - prints a message and exits
 */
void handle_signal() {
    printf("Segfault detected!\n");
}


int main (int argc, char* argv[]) {
    // Register for a segfault signal
    signal(SIGSEGV, handle_signal);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}