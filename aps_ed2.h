#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct palavra{
    char palavra[50];
    char palavra_ordenada[50];
    long int chave;
}Palavra;

typedef struct lista_palavras{
    Palavra vetor_palavra[100];
    long int chave;
    int cont;
}Lista_Palavras;

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

long int func_hash(char * palavra, int n){
    int i;
    long int cod_hash=0;
    
    for(i=0; i<n; i++){
        cod_hash=cod_hash+(palavra[i]*(i+1)*(i+1));
    }

return cod_hash;
}

Palavra * criar_palavra(){
    Palavra * novo=(Palavra*)malloc(sizeof(Palavra));
return novo;    
}

char * tolower_string(char * str, int n){
    int i;
    
    for(i=0; i<n; i++){
        str[i]=tolower(str[i]);
    }

return str;
}
