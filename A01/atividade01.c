
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int buscaLinear(int *vetor, int n, int elem);
int buscaOrdenada(int *vetor, int n, int elem);
int buscaBinaria(int *vetor, int n, int elem);

int* vetorDesordenado(int menor, int maior, int quant); // Retorna um vetor de elementos aleatórios.
void ordenar(int *v, int n); // Ordena o vetor em ordem crescente.

void main(){
    setlocale(LC_ALL, "");
    srand((unsigned) time(NULL));

    int menor = 100; // Menor valor dos vetores.
    int maior = 199; // Maior valor dos vetores.
    int tamanho = 10; // Quantidade de elementos em cada vetor.

    int busca;
    int resposta;

    // Gera os vetores:
    int *vetorDes = vetorDesordenado(menor, maior, tamanho);
    int *vetorOrd = vetorDesordenado(menor, maior, tamanho);
    ordenar(vetorOrd, tamanho);

    // Mostra os vetores na tela:
    int i;

    printf("\n\n > Vetor Desordenado: \n");

    for(i = 0; i < tamanho; i++){
            printf(" [%d]: %d  ", i, vetorDes[i]);
    }

    printf("\n\n > Vetor Ordenado: \n");

    for(i = 0; i < tamanho; i++){
            printf(" [%d]: %d  ", i, vetorOrd[i]);
    }

    // Obtém do usuário o número a ser buscado:
    printf("\n\n");
    printf(" > Informe o número a ser buscado: ");
    scanf("%d", &busca);

    // Pesquisa e apresenta os resultados na tela:
    printf("\n\n");
    printf(" > Busca linear: ");
    resposta = buscaLinear(vetorDes, tamanho, busca);
    resposta == -1? printf("Valor não encontrado.") : printf("Valor encontrado no índice %d do vetor desordenado.", resposta);

    printf("\n\n");
    printf(" > Busca Ordenada: ");
    resposta = buscaOrdenada(vetorOrd, tamanho, busca);
    resposta == -1? printf("Valor não encontrado.") : printf("Valor encontrado no índice %d do vetor ordenado.", resposta);

    printf("\n\n");
    printf(" > Busca Binária: ");
    resposta = buscaBinaria(vetorOrd, tamanho, busca);
    resposta == -1? printf("Valor não encontrado.") : printf("Valor encontrado no índice %d do vetor ordenado.", resposta);

    printf("\n\n");
    free(vetorOrd);
    free(vetorDes);
}

int buscaLinear(int *vetor, int n, int elem){
    int i;
    for(i = 0; i < n; i++){
        if(elem == vetor[i]){
            return i;
        }
    }
    return -1; // Não encontrado.
}

int buscaOrdenada(int *vetor, int n, int elem){
    int i;
    for(i = 0; i < n; i++){
        if(elem == vetor[i]){
            return i;
        }
        else if(elem < vetor[i]){
            return -1; // Não encontrado.
        }
    }
    return -1; // Não encontrado.
}

int buscaBinaria(int *vetor, int n, int elem){
    int i, inicio, meio, fim;
    inicio = 0;
    fim = n -1;

    while(inicio <= fim){
            meio = (inicio + fim)/2;
            if(elem < vetor[meio]){     // Busca na metade esquerda.
                fim = meio -1;             // Selecionando a metade esquerda, excluindo o meio.
            }
            else if(elem > vetor[meio]){   // Busca na metade direita.
                inicio = meio +1;               // Selecionando a metade direita, excluindo o meio.
            }
            else{
                return meio;
            }
    }
    return -1; // Não encontrado.
}

int* vetorDesordenado(int menor, int maior, int quant){

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

