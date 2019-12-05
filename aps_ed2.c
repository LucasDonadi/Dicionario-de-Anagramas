#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aps_ed2.h"
#include <ctype.h>

int main(int argc, char *argv[ ]){
    int i;

    //quant de palavras = 261800
    ordena_palavra(argv[1], strlen(argv[1]));
    printf("\n Palavra ordenada:%s", argv[1]);


    /*FILE *fp1 = fopen ("br.txt", "r");
    if (fp1 == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        return 1;
    }
    char palavra_num[50];
    while(feof(fp1)==0){
        fgets(palavra_num, 50, fp1);
        cont++;
    }

    printf("\nnumero de palavras:%d", cont);

    fclose(fp1);*/ 

    FILE *fp = fopen ("br.txt", "r");
    if (fp == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        return 1;
    }

    Palavra a[30];

    for(i=0; i<30; i++){
        fgets(a[i].palavra, 50, fp);
        a[i].palavra[strlen(a[i].palavra)-1] = 0;
        printf("\nPalavra %s adicionada ao dicionario!", a[i].palavra);
        strcpy(a[i].palavra_ordenada, a[i].palavra);
        ordena_palavra(a[i].palavra_ordenada, strlen(a[i].palavra_ordenada));
        printf("\nPalavra do arquivo ordenada:%s", a[i].palavra_ordenada);
        a[i].cod_hash=func_hash(a[i].palavra_ordenada, strlen(a[i].palavra_ordenada));
        printf("\nCodigo Hash da palavra %s: %d\n", a[i].palavra, a[i].cod_hash);
    }

    //while(feof(fp)){

    //}

    fclose(fp);

return 0;
}
