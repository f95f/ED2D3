#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int* gerarVetor(int menor, int maior, int quant); // Retorna um vetor de elementos aleatórios.
void insertionSort(int *v, int n); // Ordena o vetor em ordem crescente.

void main(){
    setlocale(LC_ALL, "");
    srand((unsigned) time(NULL));

    int menor = 200; // Menor valor dos vetores.
    int maior = 499; // Maior valor dos vetores.
    int tamanho = 10; // Quantidade de elementos em cada vetor.

    // Gera o vetor:
    int *vetor = gerarVetor(menor, maior, tamanho);

    // Mostra o vetor na tela:
    int i;

    printf("\n\n > Vetor Desordenado: \n");

    for(i = 0; i < tamanho; i++){
            printf(" [%d]: %d  ", i, vetor[i]);
    }

    insertionSort(vetor, tamanho);

    printf("\n\n > Vetor Ordenado pelo método Insertion Sort: \n");

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

void insertionSort(int *v, int n){
    int i, j, aux;

    for(i = 1; i < n; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j -1]); j--){
            v[j] = v[j -1];
        }
        v[j] = aux;
    }
}
