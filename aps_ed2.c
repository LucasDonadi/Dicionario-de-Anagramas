#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aps_ed2.h"
#include <ctype.h>

int main(int argc, char *argv[ ]){
    int i;

    //ordena_palavra(argv[1], strlen(argv[1]));
    //printf("\n Palavra ordenada:%s", argv[1]);

    FILE *fp = fopen ("br.txt", "r");
    if (fp == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        return 1;
    }

    Palavra * aux;

    Lista_Palavras * dicionario=(Lista_Palavras*)calloc(100000, sizeof(Lista_Palavras));

    while(feof(fp)==0){
        aux=criar_palavra();
        fgets(aux->palavra, 50, fp);
        aux->palavra[strlen(aux->palavra)-1] = 0;
        strcpy(aux->palavra_ordenada, aux->palavra);
        ordena_palavra(aux->palavra_ordenada, strlen(aux->palavra_ordenada));
        aux->chave=func_hash(aux->palavra_ordenada, strlen(aux->palavra_ordenada));

        if(dicionario[aux->chave].cont<100){
            dicionario[aux->chave].chave=aux->chave;
            dicionario[aux->chave].vetor_palavra[cont].chave=chave=aux->chave;
            strcpy(dicionario[aux->chave].vetor_palavra[cont].palavra,aux->palavra);
            strcpy(dicionario[aux->chave].vetor_palavra[cont].palavra_ordenada,aux->palavra_ordenada);
            dicionario[aux->chave].cont++;
        }

        printf("\nPalavra '%s' adicionada ao dicionario!", dicionario[aux->chave].palavra);
        printf("\nPalavra do arquivo ordenada:%s", dicionario[aux->chave].palavra_ordenada);
        printf("\nCodigo Hash da palavra %s: %d\n", dicionario[aux->chave].palavra, dicionario[aux->chave].chave);
    }

    printf("\n\n Anagramas a partir da palavra: %s", argv[1]);
    aux->chave=func_hash(argv[1], strlen(argv[1]));

    for(i=0; i<dicionario[aux->chave].cont; i++){
        printf("\n%s", dicionario[aux->chave].vetor_palavra[i].palavra);
    }



    fclose(fp);

return 0;
}
