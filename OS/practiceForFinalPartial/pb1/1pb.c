#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
//Creati un program C care primeste ca si argumente nume de fisiere text si
//le prelucreaza simultan folosind thread-uri. Programul transforma fisierele
//text astfel incat toate cuvintele din fisiere sa inceapa cu litera
//mare. Fisierele noi obtinute (cele ce contin cuvintele cu prima litera
//capitalizata) vor primi acelasi nume ca si fisierele sursa dar la sfarsit se
//adauga terminatia N. Se va crea un thread pentru prelucrarea fiecarui fisier.

void* processFile(void *args);

int main(int argc, char *args[]){
	pthread_t threads[argc-1];
	for(int i=1; i<argc; i++){
		//FILE *f = fopen(args[i], "r+");
		pthread_create(&threads[i-1], NULL, &processFile, args[i]);
	}
	for(int i=0; i<argc-1; i++){
		pthread_join(threads[i], NULL);
	}
	return 0;
}

void* processFile(void *args){
	char *fileName = (char*) args;

	FILE* f = fopen(fileName, "r+");
	char * newFile = malloc(sizeof(fileName)+sizeof(char));
	for(int i=0; i<strlen(fileName); i++){
		newFile[i] = fileName[i];
	}
	newFile[strlen(newFile)] = 'N';
	newFile[strlen(newFile)+1] = '\0';
	FILE* fout = fopen(newFile, "w+");

	char* word = malloc(10*sizeof(char));
	while(fscanf(f, "%s", word) != EOF){
		if(word[0] <= 'z' && word[0] >= 'a'){
			word[0] -= 32;
		}
		fprintf(fout, "%s", word);
		fprintf(fout, "%s", " ");
	}
	fclose(f);
	return NULL;
}
