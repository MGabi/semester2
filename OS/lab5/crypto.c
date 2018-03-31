#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
        char * numeFisier = malloc(10*sizeof(char));
        printf("Introduceti nume fisier: ");
        scanf("%s", numeFisier);
        printf("Introduceti cheie criptare: ");
        char * cheie = malloc(sizeof(char));
        scanf("%s", cheie);

        printf("%s %s", numeFisier, cheie);
        char * out = malloc(sizeof(numeFisier)+1);
        for(int i=0; i<sizeof(numeFisier); i++){
		char temp = numeFisier[i] ^ cheie[0];
                out[i] = temp;
        }
        out[sizeof(numeFisier)] = '\0';
        printf("Cypt: %s", out);
        return 0;
}

