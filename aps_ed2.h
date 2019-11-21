#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void BubbleSort_string(char * word, int n){ 
    char aux[n]; 
  
    for (int j=0; j<n-1; j++) { 
        for (int i=j+1; i<n; i++){ 
            if (strcmp(word[j], word[i]) > 0){ 
                strcpy(aux, word[j]); 
                strcpy(word[j], word[i]); 
                strcpy(word[i], aux); 
            } 
        } 
    } 
} 