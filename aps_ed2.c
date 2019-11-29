#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aps_ed2.h"
#include <ctype.h>

int main(int argc, char *argv[ ]){
        
    ordena_palavra(argv[1], strlen(argv[1]));
    printf("\n Palavra ordenada:%s", argv[1]);

    FILE *fp = fopen ("br.txt", "r");
    if (fp == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        return 1;
    }

    Palavra a1;

    fgets(a1.palavra, 50, fp);
   
    printf("\n palavra do arquivo:%s", a1.palavra);

    //while(feof(fp)){

    //}

    fclose (fp);

return 0;
}
