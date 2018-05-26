//
// Created by mgabi on 25.04.2018.
//
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DATA_TRANSFER "/tmp/data_transfer.fifo"
#define BUFFER 50


int main(int argc, char * argv[]){
    char in[BUFFER];
    char * path = "/tmp/data_transfer";
    int rez = mkfifo(path, 0666);
    printf("%d\n", rez);
    printf("channel used : %s\n", path);

    int in_fd = open(path, O_RDWR);

    /*if(in_fd == -1){
        perror("opening error");
        exit(-1);
    }*/

    /*char * name = malloc(20* sizeof(char));
    printf("Filename: \n");
    scanf("%s", name);
    char * key = malloc(sizeof(char));
    printf("Crypting key: \n");
    scanf("%c", key);

    printf("%s %s", name, key);*/



}

