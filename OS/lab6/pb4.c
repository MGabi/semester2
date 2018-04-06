#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"

void startNewProcess(int pid);

int main(){
    int pid, state;
    printf(" The parent: before the fork()\n");
    pid = fork();

    if ((pid = fork()) != 0) {
        wait(&state);
    }else{
        startNewProcess(pid);
    }

    state = WEXITSTATUS(state);
    printf("PID child = %d; terminated with the code %d = %x\n", pid, state, state);
    return 0;
}

void startNewProcess(int pid){
    int state;
    if (pid % 2 == 0) {
        if ((pid = fork()) != 0) {
            wait(&state);
        }else{
            pid = getpid();
            printf("Child PID: %d \n", pid);
            startNewProcess(pid);
        }
    }else{
        printf("Process %d terminated!\n", pid);
        exit(10);
    }

    exit(10);

}
