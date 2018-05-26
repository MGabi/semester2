#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_worker(void *str);

int main(int argc, char *argv[]){
    pthread_t threads[argc-1];

    for (int i=1; i<argc; i++){
        printf("Arg: %s \n", argv[i]);
        pthread_create(&threads[i-1], NULL, thread_worker, argv[i]);
    }
    for (int i=0; i<argc-1; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread_worker(void *str){
    printf("%s\n", (char*)str);
}
