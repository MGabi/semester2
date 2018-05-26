
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
    int a2b[2], b2a[2];
    pipe(a2b);
    pipe(b2a);

    if (fork() == 0){
        close(a2b[0]);
        close(b2a[1]);
        printf("CHILD [ %d ] started\n", getpid());
        int number;
        while (1){
            printf("Enter a number: ");
            scanf("%d", &number);
            write(a2b[1], &number, sizeof(int));
            if (number == -1)
                break;
        }
        int sum;
        read(b2a[0], &sum, sizeof(int));
        printf("The sum of numbers is %d \n", sum);
        close(a2b[1]);
        close(b2a[0]);
        exit(0);
    }

    if (fork() == 0){
        close(a2b[1]);
        close(b2a[0]);
        printf("CHILD [ %d ] started\n", getpid());
        int sum = 0;
        int nr;
        while (1) {
            read(a2b[0], &nr, sizeof(int));
            if (nr == -1) {
                write(b2a[1], &sum, sizeof(int));
                break;
            }
            sum += nr;
        }
        close(a2b[0]);
        close(b2a[1]);
        exit(0);
    }


    int stat = -1;
    wait(&stat);
    printf("Child finished with PID: %d\n", stat);
    wait(&stat);
    printf("Child finished with PID: %d\n", stat);

    close(a2b[0]);
    close(a2b[1]);
    close(b2a[0]);
    close(b2a[1]);
    exit(0);
}