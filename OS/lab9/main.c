#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stdatomic.h>

/*
 * A) Sa se afiseze cate numere prime sunt in intervalul 1-2,000,000,000.

- in prima varianta se implementeaza iterativ
- se masoara timpul de executie
- se incearca cu 2, 4, 8 threaduri, fiecare prelucrand un subinterval, si se va determina care varianta este mai rapida

Note: Pentru masurarea timpul de executie se poate folosi o secventa similara cu:

time_t t1 = time(NULL);
time_t t2 = time(NULL);

double x = difftime(t2, t1);

printf("%.0f", x);*/

#define THREADS 8
#define MAX_PRIMES 200000000

int size = MAX_PRIMES / THREADS;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int global_c = 0;
int currentNumber = 2;

void *firstNPrimesGlobal(void *ptr);
void *firstNPrimes(void *ptr);
bool isPrime(int number);

void testIsPrime();

/**
 * An interval used for finding primes
 * in range [start, end]
 */
typedef struct{
    int start;
    int end;
} Interval;

int main() {
    testIsPrime();
    pthread_t threads[THREADS];

    Interval * interval = malloc(sizeof(Interval));
    interval->start = 0;
    interval->end = interval->start + size;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    //Creating THREADS threads
    for(int i=0; i<THREADS; i++){
//        pthread_create(&threads[i], NULL, &firstNPrimes, interval);
        pthread_create(&threads[i], NULL, &firstNPrimesGlobal, NULL);
    }

    //making main() to wait untill all threads are done
    for(int i=0; i<THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    double x = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    x /= (float)1000000;
    printf("Time: %.3lf s\n", x);
    printf("Primes counted: %d\n", global_c);

    free(interval);
}

void testIsPrime() {
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(!isPrime(6));
    assert(isPrime(7));
    assert(!isPrime(6));
    assert(!isPrime(100));
    assert(isPrime(101));
}

void *firstNPrimesGlobal(void *ptr){

    while (1) {
        int number = 0;
        pthread_mutex_lock(&mutex);
        number = currentNumber + 1;
        currentNumber++;
        pthread_mutex_unlock(&mutex);
//        number = atomic_fetch_add(&currentNumber, 1);

        if (number >= MAX_PRIMES)
            break;

        if (isPrime(number)) {
            pthread_mutex_lock(&mutex);
            global_c += 1;
            pthread_mutex_unlock(&mutex);
//            atomic_fetch_and(&global_c, 1);
        }
    }
}

/**
 * Worker function for every thread
 * @param ptr : pointer to the interval in which the
 *      current thread needs to find prime numbers
 * @return nothing
 */
void *firstNPrimes(void *ptr){
    Interval interval;
    interval.start = ((Interval*)ptr)->start;
    interval.end = ((Interval*)ptr)->end;

    ((Interval*)ptr)->start += size;
    ((Interval*)ptr)->end += size;
    int c = 0;

    for (int i = interval.start; i <= interval.end; i++) {
        if (isPrime(i))
            c++;
    }

    printf("%d numere prime in intervalul %d - %d\n", c, interval.start, interval.end);

    /*
     * Lock the access of other threads to the variables used
     * inside the lock/unlock events
     */
    pthread_mutex_lock(&mutex);
    global_c += c;
    pthread_mutex_unlock(&mutex);
}

bool isPrime(int number){
    if (number % 2 == 0)
        return false;

    for(int i=3; i*i<=number; i += 2){
        if(number % i == 0)
            return false;
    }

    return true;
}