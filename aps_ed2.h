#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct palavra{
    char palavra[50];
    char palavra_ordenada[50];
}Palavra;

void ordena_palavra(char * palavra, int n){
    char aux;
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(palavra[j]>palavra[j+1]){
                aux=palavra[j+1];
                palavra[j+1]=palavra[j];
                palavra[j]=aux;
            }
        }
    }
}
