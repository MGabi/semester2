#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int pid, state;
    printf(" The parent: before the fork()\n");

    if ((pid = fork()) != 0){
        wait(&state);
    }else{
        int pid;
        printf("The child: begins the execution \n");
        pid=getpid();
        printf("The son: %d terminates\n", pid);
        exit(10);
    }
    printf("The parent: after fork()\n");
    state = WEXITSTATUS(state);
    printf("PID child=%d; terminated with the code %d=%x\n", pid, state, state);
    return 0;
}
