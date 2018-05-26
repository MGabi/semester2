//
// Created by Gabi on 3/6/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define False 0
#define True 1
void testAll();

typedef struct{
    int start;
    int len;
} Sequence;

Sequence getLongestSequence(int lenV, int v[]);
int* getPrimeFactors(int n);

int* relativePrimes(int n){
    int *v = malloc(100*sizeof(int));
    int j = 0;
    for (int i=0; i<100; i++)
        v[i] = 0;
    for (int i = 2; i < n; i++) {
        if (cmmdc(n, i) == 1)
            v[j++] = i;
    }

    return v;
}

void testA(){
    int *v = relativePrimes(6);
    assert(v[0] == 5);
    v = relativePrimes(7);
    assert(v[0] == 2);
    assert(v[1] == 3);
    assert(v[2] == 4);
    assert(v[3] == 5);
    assert(v[4] == 6);
}

void testB(){
    int n = 5;
    int v[5] = {121, 3, 154, 541, 123};
    Sequence s = getLongestSequence(n, v);
    assert(s.len == 1);
    assert(s.start = 2);
}

void testC(){
    int *v = getPrimeFactors(10);
    assert(v[2] == 1);
    assert(v[5] == 1);
}

void testAll(){
    testA();
    testB();
    testC();
}

int cmmdc(int a, int b){

    int r = a % b;
    while (r){
        a = b;
        b = r;
        r = a % b;
    }

    return b;

}

int sameDigits(int a, int b){
    int vA[10] = {0};
    int vB[10] = {0};

    while(a > 0){
        vA[a%10]=1;
        a /= 10;
    }

    while(b > 0){
        vB[b%10]=1;
        b /= 10;
    }

    for (int i = 0; i<10; i++){
        if (vA[i] != vB[i])
            return False;
    }

    return True;

}

Sequence getLongestSequence(int lenV, int v[]){
    int startS = 0;
    int lenS = 0;
    int start = -1;
    int len = 0;

    for (int i=0; i<lenV-1; i++){
        if(sameDigits(v[i], v[i+1])){
            if (start == -1) {
                start = i;
                len = 1;
            } else
                len ++;
        }else{
            if( len >= lenS ){
                startS = start;
                lenS = len;
            }
            len = 0;
            start = -1;
        }
    }

    if (sameDigits(v[lenV-2], v[lenV-1])){
        if(len+1 >= lenS){
            startS = start;
            lenS++;
        }
    }

    Sequence sequence;
    sequence.len = lenS;
    sequence.start = startS;

    return sequence;
}


int* getPrimeFactors(int n){
    int *v = malloc(100* sizeof(int));
    while (n%2 == 0)
    {
        v[2] = 1;
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            v[i] = 1;
            n = n/i;
        }
    }

    if (n > 2)
        v[n] = 1;

    return v;
}

int main(){

    testAll();
    char op = 'a';
    printf("a. Show all numbers which are relative primes to a number N\n");
    printf("b. Find the longest subsequence where all the numbers have the same digits\n");
    printf("c. Decomposite a number in it's prime factors\n");
    printf("Enter option: ");
    scanf("%c", &op);
    if (op == 'a') {

        //a
        int n;
        printf("N = ");
        scanf("%d", &n);

        int *v = relativePrimes(n);
        printf("Relative primes with %d:\n", n);
        for (int i=0; i<100; i++){
            if(v[i] != 0)
                printf("%d ", v[i]);
        }

    }else if( op == 'b'){
        //b
        int n = 5;
        int v[5] = {121, 3, 154, 541, 123};

        Sequence sequence = getLongestSequence(n, v);

        printf("StartS: %d, lenS: %d\n", sequence.start, sequence.len);

        for (int i=sequence.start; i<sequence.start + sequence.len + 1; i++){
            printf("%d ", v[i]);
        }
    }else if( op == 'c' ){
        int n = 0;
        printf("Enter a number to decomposite it in it's prime numbers: ");
        scanf("%d", &n);

        int *v = getPrimeFactors(n);
        for(int i=0; i<100; i++){
            if (v[i] == 1){
                printf("%d ", i);
            }
        }
    }
}


