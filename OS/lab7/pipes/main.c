#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

ssize_t readWrapper(int fd, char *buf, int size);
/**
 * un proces parinte ii trimite unui fiu prin pipe
 * continutul unui fisier al carui nume il primeste
 * ca argument (parintele)
 * fiul cripteaza continutul primit cu operatia XOR 0xBC
 * si ii trimite inapoi parintelui prin pipe continutul criptat
 * parintele va scrie rezultatul intr un fisier nume.crypt
 * @return
 */
int main(int nr, const char ** argv){

    int p2c[2];
    int c2p[2];

    pipe(p2c);
    pipe(c2p);
    /**
     * read - p2c[0]
     * write - p2c[1]
     */
    //int pid = fork();

    char * filename = malloc(sizeof(argv[0]));
    strcpy(filename, argv[1]);
    printf("%s", filename);
    FILE* file = fopen(filename, "r+");
    if (file == NULL)
        exit(0);

    /*if (pid == 0){
        *//**
         * Inside of child code
         *//*

        close(p2c[1]);
        close(c2p[0]);
        long size = -1;
        read(p2c[0], &size, sizeof(size));
        if (size > 0) {
            char *content = malloc((size_t) size);
            read(p2c[0], content, (size_t)size);
            printf("%s", content);
            //write(c2p[1], &x[0], sizeof(int));
        }
        exit(0);
    } else{
        *//**
         * Inside of parent code
         *//*
        fseek(file, 0, SEEK_END);
        long fsize = ftell(file);
        fseek(file, 0, SEEK_SET);
        char * buffer = malloc((size_t)fsize + 1);
        fread(buffer, (size_t)fsize, 1, file);
        fclose(file);
        buffer[fsize] = '\0';

        write(p2c[1], &fsize, sizeof(fsize));
        write(p2c[1], buffer, sizeof(int));
        wait(0);
//        read(c2p[0], &a, sizeof(int));
//        printf("%d", a);
    }*/
}

ssize_t readWrapper(int fd, char *buf, int size){
    int n = 0;
    while (n < size){
        ssize_t x = read(fd, (char*)((size_t) buf + n), (size_t) (size - n));
        if (x < 0)
            return x;
        n += x;
    }

    return n;
}