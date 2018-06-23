#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n = 0;
pthread_mutex_t a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t b = PTHREAD_MUTEX_INITIALIZER;
void* fa(void* p);
void* fb(void* p);

int main(int argc, char *argv[]){
    pthread_t th[2];
    pthread_create(&th[0], NULL, fa, NULL);
    pthread_create(&th[1], NULL, fb, NULL);

    pthread_join(th[0], NULL);
    pthread_join(th[1], NULL);
    printf("%d", n);
    return 0;
}

void* fa(void* p){
    pthread_mutex_lock(&a);
    n++;
    pthread_mutex_unlock(&a);
    return NULL;
}


void* fb(void* p){
    pthread_mutex_lock(&a);
    n++;
    pthread_mutex_unlock(&a);
    return NULL;
}
