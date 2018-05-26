#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

#define N_THREADS 5

//3) Sa se scrie un program care citeste un numar natural "N" de la tastatura si creeaza 5 thread-uri. Fiecare thread va incrementa o variabila globala "g" si va calcula g! si va aduna rezultatul la o alta variabila globala "sumaFactorial". Threadurile se vor opri cand variabila "g" va depasi variabila "N".

void *worker(void *args);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int sumaFactorial;
int N = -1;
int g = 1;

int main(){
    printf("Enter a number: ");
    scanf("%d", &N);
    printf("%d\n", N);


    pthread_t threads[N_THREADS];

    for(int i=0; i<N_THREADS; i++){
        int res = pthread_create(&threads[i], NULL, worker, NULL);
        printf("res: %d", res);
    }

    for(int i=0; i<N_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("g: %d", g);
    return 0;
}

void *worker(void *args){

    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    long fact = g;
    g++;
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);


}
