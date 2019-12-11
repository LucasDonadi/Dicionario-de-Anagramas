//Aluno: Lucas Henrique Malaquias da Silva Donadi  RA:1711598
//codigo nao esta funcionando, estou enviando tudo que consegui fazer

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aps_ed2.h"
#include <ctype.h>

int main(int argc, char *argv[ ]){
    int i=0, j=0, cont;
    char palavradigitada[50];

    strcpy(argv[1],tolower_string(argv[1], strlen(argv[1])));

    strcpy(palavradigitada, argv[1]);

    ordena_palavra(argv[1], strlen(argv[1]));
    printf("\nPalavra ordenada:%s", argv[1]);

    FILE *fp = fopen ("br.txt", "r");
    if (fp == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        return 1;
    }

    Palavra * aux;

    Lista_Palavras *dicionario=(Lista_Palavras*)calloc(100000, sizeof(Lista_Palavras));

    for(i=0; i<100000; i++){
        dicionario[i].cont=0; //setando os contadores de posicao do vetor de palavras para 0
    }

    while(feof(fp)!=1){
        aux=criar_palavra();
        fgets(aux->palavra, 50, fp);
        aux->palavra[strlen(aux->palavra)-1] = 0;
        strcpy(aux->palavra,tolower_string(aux->palavra, strlen(aux->palavra)));
        strcpy(aux->palavra_ordenada, aux->palavra);
        ordena_palavra(aux->palavra_ordenada, strlen(aux->palavra_ordenada));
        aux->chave=criar_chave(aux->palavra_ordenada, strlen(aux->palavra_ordenada));

        /*printf("\nPalavra '%s' adicionada ao dicionario!", aux->palavra); //nessa parte eu imprimo tudo q passa pelo aux(chega ate a ultima palavra do arquivo)
        printf("\nPalavra do arquivo ordenada:%s", aux->palavra_ordenada);
        printf("\nChave da palavra %s: %ld\n", aux->palavra, aux->chave);*/  
        
        cont=dicionario[aux->chave].cont;   //aqui tento passar para o dicionario todas as palavras
        dicionario[aux->chave].chave=aux->chave; //aux->chave serve para escolher a posicao do dicionario em q a palavra sera inserida
        dicionario[aux->chave].vetor_palavra[cont].chave=aux->chave; //cont serve para escolher a posicao em q palavra sera inserida no vetor de palavras dentro do dicionario
        strcpy(dicionario[aux->chave].vetor_palavra[cont].palavra,aux->palavra);
        strcpy(dicionario[aux->chave].vetor_palavra[cont].palavra_ordenada,aux->palavra_ordenada);
        dicionario[aux->chave].cont++;
        printf("\nPalavra '%s' adicionada ao dicionario!", dicionario[aux->chave].vetor_palavra[cont].palavra);
        printf("\nPalavra do arquivo ordenada:%s", dicionario[aux->chave].vetor_palavra[cont].palavra_ordenada);
        printf("\nChave palavra %s: %ld\n", dicionario[aux->chave].vetor_palavra[cont].palavra, dicionario[aux->chave].vetor_palavra[cont].chave);
    }

    printf("\n\nAnagramas a partir da palavra %s:\n", palavradigitada);
    aux->chave=criar_chave(argv[1], strlen(argv[1]));

    for(i=0; i<dicionario[aux->chave].cont; i++){  //impressao das palavras que tem a mesma chave e portanto sao anagramas
        printf("%s\n", dicionario[aux->chave].vetor_palavra[i].palavra);
    }

    fclose(fp);

return 0;
}
