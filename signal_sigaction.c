/***************************************************************************
* Filename: signal_sigaction.c
* Author: Jeric Moon
* Date: 11/10/2025 
* Desc: Provides a simple sigaction method/example
* Note: To send the SIGUSR1 command from terminal, kill -SIGUSR1 <PID>. 
*   CTRL+Z stops the program, bg sends it to the background.
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
    sigaction(SIGUSR1, &sa, NULL);

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
    int sender_pid = info->si_pid;
    printf("Process ID of SIGUSR1 sender is: %d\n", sender_pid);
}