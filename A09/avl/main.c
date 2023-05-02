#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){

    int x; //retornoz

    avlTree *raiz;

    raiz = criar_avlTree();

    if(vazia_avlTree(raiz)){
        printf("\n > Árvore vazia!\n");
    }
    else{
        printf("\n > Árvore possui elementos!\n");
    }
/*
    x = inserir_avlTree(raiz, 80);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, 5);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, 125);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, 5200);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, 33133);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, 52);
*/
    for(int i = 1; i < 11; i++){

        x = inserir_avlTree(raiz, i);
        (x)? (printf("  - Elemento %d inserido com sucesso!\n", i)) : (printf("Erro ao inserir %d!\n", i));

    }

    if(vazia_avlTree(raiz)){
        printf("\n > Árvore vazia!\n");
    }
    else{
        printf("\n > Árvore possui elementos!\n");
    }

    x = altura_avlTree(raiz);
    printf(" \n > Altura da árvore: %d \n", x);

    x = totalNO_avlTree(raiz);
    printf(" \n > Total de nós: %d \n", x);

    printf("\n -----------------------------------------------------------------\n");

    //Percorrendo:
    printf("\n > Percorrendo a árvore - pré-ordem:\n");
    preOrdem_avlTree(raiz);

    printf("\n > Percorrendo a árvore - em ordem:\n");
    emOrdem_avlTree(raiz);

    printf("\n > Percorrendo a árvore - pós-ordem:\n");
    posOrdem_avlTree(raiz);

    printf("\n -----------------------------------------------------------------\n");

    //Consultando
    printf("\n > Busca na árvore binária: 110\n");
    if(consulta_avlTree(raiz, 110)){
        printf("\n -- Elemento encontrado!\n.");
    }
    else{
        printf("\n -- Elemento não encontrado.\n");
    }

    printf("\n > Busca na árvore binária: 140\n");
    if(consulta_avlTree(raiz, 140)){
        printf("\n -- Elemento encontrado!\n");
    }
    else{
        printf("\n -- Elemento não encontrado.\n");
    }

    printf("\n -----------------------------------------------------------------\n");

    // Destruindo a árvore
    liberar_avlTree(raiz);
    printf(" > A árvore foi destruída.\n\n");

    return 0;
}



