/***************************************************************************
* Filename: recv_signal.c
* Author: Jeric Moon
* Date: 11/10/2025
* Desc: Simple program which waits to recieve a signal sent from another one.
* Note: gcc -o "recv_signal" recv_signal.c
****************************************************************************/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_sigurs1(int sig, siginfo_t *info, void *ucontext);

int main() {

    // Register for the signal
    struct sigaction sa = {0};
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handle_sigurs1;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    printf("Waiting for signal!\n");
    // Infinite wait which calls the function do() with the argument "nothing"
    while(1)
    {
        //do(nothing);
    }
    return 0;
}

/*
* Method which purpose is to handle an SIGUSR1 signal using sigaction.
*/
void handle_sigurs1(int sig, siginfo_t *info, void *ucontext) {
    int value = info->si_value.sival_int;
    printf("Value of passed value sival_int is %d\n", value);
    exit(1);
}