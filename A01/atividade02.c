// Felipe Fernandes - GU3026965

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int *adicionar(int *vetor, int n, int elem);

int* gerarVetor(int menor, int maior, int quant); // Retorna um vetor de elementos aleatórios.
void ordenar(int *v, int n); // Ordena o vetor em ordem crescente.

void main(){
    setlocale(LC_ALL, "");
    srand((unsigned) time(NULL));

    int menor = 100; // Menor valor dos vetores.
    int maior = 199; // Maior valor dos vetores.
    int tamanho = 5; // Quantidade de elementos em cada vetor.

    int novo;

    // Gera o vetor:
    int *vetor = gerarVetor(menor, maior, tamanho);
    ordenar(vetor, tamanho);

    int i;

     // Mostra o vetor na tela:
    system("cls");
    printf("\n\n > Vetor: \n");

    for(i = 0; i < tamanho; i++){
            printf(" [%d]: %d  ", i, vetor[i]);
    }

    // Obtém do usuário o número a ser inserido
    printf("\n\n");
    printf(" > Informe o número a ser adicionado: ");
    scanf("%d", &novo);

    vetor = adicionar(vetor, tamanho, novo);
    tamanho++;
    // Mostra o vetor na tela:

    printf("\n\n > Vetor: \n");

    for(i = 0; i < tamanho; i++){
            printf(" [%d]: %d  ", i, vetor[i]);
    }

    printf("\n\n");

    free(vetor);
}

int *adicionar(int *vetor, int n, int elem){
    int i;
    int aux;

    n++;
    int *novoVetor = realloc(vetor, sizeof(int));
    free(vetor);

    for(i = 0; i < n; i++){
        if(elem <= novoVetor[i]){
                aux = novoVetor[i];
                novoVetor[i] = elem;
                elem = aux;
        }
    }
    return novoVetor;
}

int* gerarVetor(int menor, int maior, int quant){

    int *vetor = (int*) calloc(quant, sizeof(int));
    int i;

    for(i = 0; i < quant; i++){
        vetor[i] = rand() % (maior - menor) + menor;
    }
    return vetor;
}

void ordenar(int *v, int n){ // bubble sort
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

