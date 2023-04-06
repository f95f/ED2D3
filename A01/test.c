#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand((unsigned) time(NULL));

    int menor = 100, maior = 200, quant = 10;

    int *vetor = (int*) calloc(quant, sizeof(int));
    int parte = (maior - menor) / quant;
    int max = parte;
    int min = 0;
    int i;

    for(i = 0; i < quant; i++){
        vetor[i] = (rand() + min) % max + min - menor;
        printf("vetor: %d, max: %d, min: %d\n", vetor[i], max, min);
        max += parte;
        min += parte;
    }

   /* for(i = 0; i < quant; i++){
        printf("%d\n", vetor[i]);
    }*/

}
