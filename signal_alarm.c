/***************************************************************************
* Filename: signal_alarm.c
* Author: Jeric Moon
* Date: 11/10/2025 
* Desc: Provides a simple alarm signal method/example/
* Note: 
****************************************************************************/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void alarm_signal();

int main() {

    // Register for the signal
    signal(SIGALRM, alarm_signal);

    // Call an alarm signal
    printf("Sending 5 second alarm and starting 10 second sleep\n");
    alarm(5);
    sleep(10);
    printf("10 second sleep over\n");
    return 0;
}

/*
* Method which purpose is to handle an alarm signal.
*/
void alarm_signal() {
    printf("Alarm! Alarm! Alarm has executed.\n");
}