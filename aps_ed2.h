#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*void BubbleSort_string(char * word, int n){
    char aux;
    int i, j;

    printf("\n palavra inicial: %s", word);

    for (j=0; j<n-1; j++) {
        for (i=j+1; i<n-1; i++){
            if (strcmp(word[j], word[i]) > 0){
                strcpy(aux, word[j]);
                strcpy(word[j], word[i]);
                strcpy(word[i], aux);
            }
        }
    }
}*/

void ordena_palavra(char * word, int n){
    char aux[n];
    int i, j, cont=0;

    for(i=0; i<n-1;){
        for(j=i+1; j<n-1;){
            if(word[i]>=word[j] || i>n){
                aux[cont]=word[j];
                j++;
            }
            else if(word[j]>word[i] || j>n){
                aux[cont]=word[i];
                i++;
            }
            cont++;
        }
    }

    strcpy(aux, word);
}

/*void BubbleSort_2(char * word, int n){
char aux[n];
int i, j;

for(i=1;i<5;++i){
    for(j=4;j>=i;--j){
        if (strcmp(word[j-1],word[j])>0){
            aux=word[j-1];
            word[j-1]=word[j];
            word[j]=aux;
        }
    }
}*/
