/***************************************************************************
* Filename: recv_signal.c
* Author: Jeric Moon
* Date: 11/10/2025
* Desc: Simple program which sends generates a random value.b
* Program then sends a signal from one program to another, passing the value.
* Note: gcc -o "send_signal" send_signal.c
****************************************************************************/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    //use time for seed for srand f-n
    srand(time(NULL));
    int rand_val = rand();
    //print the random value
    printf("Random value is %d\n", rand_val);
    int pid;
    //Prompt user to enter in a valid PID, wait until they pass in a number.
    printf("Please enter in PID of process you want to send SIGUSR1 to: ");
    while(scanf("%d", &pid) != 1)
    {
        printf("Please enter in a valid PID: ");
    
    }
    printf("\n");
    //Declare & define sigval union to pass in the random value.
    union sigval value;
    value.sival_int = rand_val;
    if(sigqueue(pid, SIGUSR1, value) != 0)
    {
        printf("Error sending signal to pid %d\n", pid);
    }

    return 0;
}
