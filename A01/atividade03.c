#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int* gerarVetor(int menor, int maior, int quant); // Retorna um vetor de elementos aleatórios.
void bubbleSort(int *v, int n); // Ordena o vetor em ordem crescente.

void main(){
    setlocale(LC_ALL, "");
    srand((unsigned) time(NULL));

    int menor = 100; // Menor valor dos vetores.
    int maior = 199; // Maior valor dos vetores.
    int tamanho = 10; // Quantidade de elementos em cada vetor.

    // Gera o vetor:
    int *vetor = gerarVetor(menor, maior, tamanho);

    // Mostra o vetor na tela:
    int i;

    printf("\n\n > Vetor Desordenado: \n");

    for(i = 0; i < tamanho; i++){
            printf(" [%d]: %d  ", i, vetor[i]);
    }

    bubbleSort(vetor, tamanho);

    printf("\n\n > Vetor Ordenado pelo método Bubble Sort: \n");

    for(i = 0; i < tamanho; i++){
            printf(" [%d]: %d  ", i, vetor[i]);
    }

    printf("\n\n");
    free(vetor);
}

int* gerarVetor(int menor, int maior, int quant){

    int *vetor = (int*) calloc(quant, sizeof(int));
    int i;

    for(i = 0; i < quant; i++){
        vetor[i] = rand() % (maior - menor) + menor;
    }
    return vetor;
}

void bubbleSort(int *v, int n){
    int i, continua, aux, fim = n;
    do{
        continua = 0;
        for(i = 0; i < fim -1; i++){
            if(v[i] > v[i +1]){
                aux = v[i];
                v[i] = v[i +1];
                v[i +1] = aux;

                continua = i;
            }
        }
        fim--;
    }
    while(continua != 0);
}

