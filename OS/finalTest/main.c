#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

//7. Sa se scrie un program care primeste un fisier "F" si un numar natural "K" in linia de comanda. Creeaza 2 threaduri care genereaza numere random in intervalul (0, dim_fisier) in variabila globala "nrOrdine". Creeaza alte 5 threaduri care la un interval de 2 secunde verifica valoarea variabilei globale "nrOrdine" si inlocuieste caracterul de pe pozitia "nrOrdine" din fisier cu carcterul "X" dupa care incrementeaza variabila gobala "nrInlocuiri". Toate threadurile isi incheie executia cand s-au realizat "K" inlocuiri. Threadul principal deschide fisierul iar celalte threaduri folosesc descriptorul obtinut de threadul principal.
int dim_fis = 0;
int nrOrdine = -1;
int nrInlocuiri = 0;
int k;
char* content;
int done = 0;

void* generateNumbers(void* args);
void* replaceWorker(void* args);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char* args[]){
	char* fisier = args[1];
	k = *(args[2]) - '0';
	srand(time(NULL));
	FILE* f = fopen(fisier, "r");
	
	char* c = malloc(sizeof(char));
	while(fread(c, 1, 1, f) != 0){
		dim_fis += 1;
	}
	close((size_t)f);
	if(dim_fis == 0){
		perror("The file is empty!");
		return 0;
	}
	f = fopen(fisier, "r+");
	content = malloc(dim_fis*sizeof(char));
	for(int i=0; i<dim_fis; i++){
		fread(c, 1, 1, f);
		strcat(content, c);
	}
	close((size_t)f);
	
	f = fopen(fisier, "r+");
	
	pthread_t genThreads[2];
	for(int i=0; i<2; i++){
		pthread_create(&genThreads[i], NULL, &generateNumbers, NULL);
	}

	pthread_t replacers[5];
	for(int i=0; i<5; i++){
		pthread_create(&replacers[i], NULL, &replaceWorker, f); 
	}
	for(int i=0; i<5; i++){
		pthread_join(replacers[i], NULL);
	}
	return 0;
}

void* replaceWorker(void* args){
	FILE* f = (FILE*) args;
	do{
		sleep(2);
		pthread_mutex_lock(&mutex);
		int pos = nrOrdine-1;
		content[pos] = 'X';
		nrInlocuiri ++;
		pthread_mutex_unlock(&mutex);
	}while(nrInlocuiri < k);

	pthread_mutex_lock(&mutex);
	if(done == 0){
		done = 1;
		fwrite(content, 1, dim_fis, f);
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void* generateNumbers(void* args){
	while(1){
		int num = rand();	
		if(num != 0)
			num = num%dim_fis;
		nrOrdine = num;
		if(nrInlocuiri == k)
			return NULL;
	}
	return NULL;
}
