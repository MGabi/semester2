//
// Created by mgabi on 09.05.2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

/**
 * se citeste un numar de la tastatura
 * creeaza un proces fiu
 * trimite fiului numarul citit
 * fiul genereaza atatea numere aleatorii cat este valoarea numerica primita
 * de la parinte si trimite aceste nr parintelui care afiseaza.
 */
int main(){
    int p2c[2];
    int c2p[2];

    pipe(p2c);
    pipe(c2p);

    printf("\n[ P%d ]", getpid());
    int nr = -1;
    printf("Enter a number: ");
    scanf("%d", &nr);

    if (nr <= 50 || nr % 2 != 0){
        printf("Bad input!\n");
        exit(0);
    }

    write(p2c[1], &nr, sizeof(int));

    if (fork() == 0){
        //Process A
        int received;
        while (1) {
            read(p2c[0], &received, sizeof(int));
            printf("[ P%d ] - number is %d\n", getpid(), received);
            if (received < 5){
                printf("[ P%d ] - Exit, number is: %d\n", getpid(), received);
                received = 0;
                write(c2p[1], &received, sizeof(int));
                break;
            }
            received /= 2;
            write(c2p[1], &received, sizeof(int));
        }
        exit(0);
    }

    while (1){
        int fromA;
        read(c2p[0], &fromA, sizeof(int));
        printf("[ P%d ] - number is %d\n", getpid(), fromA);
        if (fromA < 5){
            printf("[ P%d ] - Exit, number is: %d\n", getpid(), fromA);
            break;
        }

        if (fromA % 2 != 0){
            fromA ++;
        }
        write(p2c[1], &fromA, sizeof(int));
    }


    wait(0);
    wait(0);

    close(p2c[0]);
    close(p2c[1]);
    close(c2p[0]);
    close(c2p[1]);
    exit(0);
}

