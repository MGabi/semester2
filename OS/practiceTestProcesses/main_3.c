#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * se citeste un numar de la tastatura
 * creeaza un proces fiu
 * trimite fiului numarul citit
 * fiul genereaza atatea numere aleatorii cat este valoarea numerica primita
 * de la parinte si trimite aceste nr parintelui care afiseaza.
 */
int main(){
    int a2b[2], b2c[2], c2a[2];

    pipe(a2b);
    pipe(b2c);
    pipe(c2a);
    int nr;
    printf("Enter a number: ");
    scanf("%d", &nr);
    if (fork() == 0){
        close(a2b[0]);
        close(b2c[0]);
        close(b2c[1]);
        close(c2a[1]);

        printf("The number is %d\n", nr);
        printf("prc [ %d ]\n\n", getpid());
        write(a2b[1], &nr, sizeof(int));
        while (1){
            read(c2a[0], &nr, sizeof(int));

            if (nr <= 0) {
                nr = -1;
                write(a2b[1], &nr, sizeof(int));
                break;
            }
            nr -= 1;
            printf("The number is %d\n", nr);
            printf("prc [ %d ]\n\n", getpid());
            write(a2b[1], &nr, sizeof(int));
        }

        close(c2a[0]);
        close(a2b[1]);
        exit(0);
    }
    if (fork() == 0){
        close(a2b[1]);
        close(b2c[0]);
        close(c2a[0]);
        close(c2a[1]);

        while (1) {
            read(a2b[0], &nr, sizeof(int));
            if (nr <= 0) {
                nr = -1;
                write(b2c[1], &nr, sizeof(int));
                break;
            }
            nr -= 1;
            printf("The number is %d\n", nr);
            printf("prc [ %d ]\n\n", getpid());
            write(b2c[1], &nr, sizeof(int));
        }

        close(b2c[1]);
        close(a2b[0]);
        exit(0);
    }
    if (fork() == 0){
        close(a2b[0]);
        close(a2b[1]);
        close(b2c[1]);
        close(c2a[0]);

        while (1) {
            read(b2c[0], &nr, sizeof(int));
            if (nr <= 0){
                nr = -1;
                write(c2a[1], &nr, sizeof(int));
                break;
            }
            nr -= 1;
            printf("The number is %d\n", nr);
            printf("prc [ %d ]\n\n", getpid());
            write(c2a[1], &nr, sizeof(int));
        }

        close(b2c[0]);
        close(c2a[1]);
        exit(0);
    }


    int stat = -1;
    wait(&stat);
    printf("Child finished with PID: %d\n", stat);

    wait(&stat);
    printf("Child finished with PID: %d\n", stat);

    wait(&stat);
    printf("Child finished with PID: %d\n", stat);

    close(a2b[0]);
    close(a2b[1]);
    close(b2c[0]);
    close(b2c[1]);
    close(c2a[0]);
    close(c2a[1]);
    exit(0);
}