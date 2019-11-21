#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aps_ed2.h"

int main(int argc, char *argv[ ]){

    BubbleSort_string(argv[1], strlen(argv));

    printf("\n Palavra ordenada:%s", argv[1]);


return 0;    
}