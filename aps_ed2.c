#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aps_ed2.h"
#include <ctype.h>

int main(int argc, char *argv[ ]){

    printf("\n Palavra ordenada:%s", argv[1]);
    
    ordena_palavra(argv[1], strlen(argv[1]));

    printf("\n Palavra ordenada:%s", argv[1]);


return 0;
}
