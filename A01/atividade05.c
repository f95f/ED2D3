#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int* gerarVetor(int menor, int maior, int quant); // Retorna um vetor de elementos aleatórios.
void selectionSort(int *v, int n); // Ordena o vetor em ordem crescente.

void main(){
    setlocale(LC_ALL, "");
    srand((unsigned) time(NULL));

    int menor = 0; // Menor valor dos vetores.
    int maior = 99; // Maior valor dos vetores.
    int tamanho = 10; // Quantidade de elementos em cada vetor.

    // Gera o vetor:
    int *vetor = gerarVetor(menor, maior, tamanho);

    // Mostra o vetor na tela:
    int i;

    printf("\n\n > Vetor Desordenado: \n");

    for(i = 0; i < tamanho; i++){
            printf(" [%d]: %d  ", i, vetor[i]);
    }

    selectionSort(vetor, tamanho);

    printf("\n\n > Vetor Ordenado pelo método Selection Sort: \n");

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

void selectionSort(int *v, int n){
    int i, j, menor, troca;
    for(i = 0; i < n - 1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

