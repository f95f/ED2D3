#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

int main(){

    printf("a");
    int x; //retorno
    system("pause");
    binTree *raiz;

    raiz = criar_binTree();

    if(vazia_binTree(raiz)){
        printf("\n > Árvore vazia!\n");
    }
    else{
        printf("\n > Árvore possui elementos!\n");
    }

    //Inserindo
    printf("\n (inserindo elementos...)\n");
    x = inserir_binTree(raiz, 150);
    x = inserir_binTree(raiz, 110);
    x = inserir_binTree(raiz, 100);
    x = inserir_binTree(raiz, 130);
    x = inserir_binTree(raiz, 120);
    x = inserir_binTree(raiz, 150);
    x = inserir_binTree(raiz, 160);


    if(vazia_binTree(raiz)){
        printf("\n > Árvore vazia!\n");
    }
    else{
        printf("\n > Árvore possui elementos!\n");
    }

    x = altura_binTree(raiz);
    printf(" \n > Altura da árvore: %d \n", x);

    x = totalNO_binTree(raiz);
    printf(" \n > Total de nós: %d \n", x);

    printf("\n -----------------------------------------------------------------\n");

    //Percorrendo:
    printf("\n > Percorrendo a árvore - pré-ordem:\n");
    preOrdem_binTree(raiz);

    printf("\n > Percorrendo a árvore - em ordem:\n");
    emOrdem_binTree(raiz);

    printf("\n > Percorrendo a árvore - pós-ordem:\n");
    posOrdem_binTree(raiz);

    printf("\n -----------------------------------------------------------------\n");

    //Removendo
    printf("\n (removendo o item 100...)\n");
    x = remove_binTree(raiz, 100);

    printf("\n > Percorrendo a árvore - em ordem - pós exclusão:\n");
    emOrdem_binTree(raiz);

    printf("\n -----------------------------------------------------------------\n");

    //Consultando
    printf("\n > Busca na árvore binária: 110\n");
    if(consulta_binTree(raiz, 110)){
        printf("\n -- Elemento encontrado!\n.");
    }
    else{
        printf("\n -- Elemento não encontrado.\n");
    }

    printf("\n > Busca na árvore binária: 140\n");
    if(consulta_binTree(raiz, 140)){
        printf("\n -- Elemento encontrado!\n");
    }
    else{
        printf("\n -- Elemento não encontrado.\n");
    }

    printf("\n -----------------------------------------------------------------\n");

    // Destruindo a árvore
    liberar_binTree(raiz);
    printf(" > A árvore foi destruída.\n\n");

    return 0;
}
