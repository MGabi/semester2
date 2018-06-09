#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>


#define ITERATIONS 1000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condB = PTHREAD_COND_INITIALIZER;
pthread_cond_t condA = PTHREAD_COND_INITIALIZER;
int globalValue = 500;
void* workerLower(void* args);
void* workerAbove(void* args);


int main(int argc, char* argv[]){
	pthread_t threads[2];
	
	pthread_create(&threads[0], NULL, &workerLower, NULL);
	pthread_create(&threads[1], NULL, &workerAbove, NULL);

	//for(int i=0; i<2; i++){
	//	pthread_join(threads[i], NULL);
	//}

	srand(time(NULL));
	for(int i=0; i<ITERATIONS; i++){
		int num = rand()%40-20;
		printf("[main] %d\n", globalValue);
		pthread_mutex_lock(&mutex);
		globalValue += num;
		if(globalValue >= 700)
			pthread_cond_signal(&condA);
		else if(globalValue <= 300)
			pthread_cond_signal(&condB);
		pthread_mutex_unlock(&mutex);
		
	}
	pthread_cancel(threads[0]);
	pthread_cancel(threads[1]);
	return 0;
}

void* workerLower(void* args){
	while(1){
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&condB, &mutex);
		if(globalValue <= 300)
			printf("[  lower  ] ->  %d\n", globalValue); 
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void* workerAbove(void* args){
	while(1){
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&condA, &mutex);
		if(globalValue >= 700)
			printf("[  higher  ] -> %d\n", globalValue);
		pthread_mutex_unlock(&mutex);
	}
 	
	return NULL;
}
