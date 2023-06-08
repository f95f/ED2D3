#include <stdio.h>
#include <stdlib.h>
#include "arvoreRN.h"

int main(){

    int x; //retorno

    arvoreLLRB *raiz;

    raiz = criar_arvoreLLRB();

    if(vazia_arvoreLLRB(raiz)){
        printf("\n > Árvore vazia!\n");
    }
    else{
        printf("\n > Árvore possui elementos!\n");
    }

    //Inserindo
    printf("\n (inserindo elementos...)\n");
    x = insere_arvoreLLRB(raiz, 150);
    x = insere_arvoreLLRB(raiz, 110);
    x = insere_arvoreLLRB(raiz, 100);
    x = insere_arvoreLLRB(raiz, 130);
    x = insere_arvoreLLRB(raiz, 120);
    x = insere_arvoreLLRB(raiz, 150);
    x = insere_arvoreLLRB(raiz, 160);


    if(vazia_arvoreLLRB(raiz)){
        printf("\n > Árvore vazia!\n");
    }
    else{
        printf("\n > Árvore possui elementos!\n");
    }

    x = altura_arvoreLLRB(raiz);
    printf(" \n > Altura da árvore: %d \n", x);

    x = totalNO_arvoreLLRB(raiz);
    printf(" \n > Total de nós: %d \n", x);

    printf("\n -----------------------------------------------------------------\n");

    //Percorrendo:
    printf("\n > Percorrendo a árvore - pré-ordem:\n");
    preOrdem_arvoreLLRB(raiz);

    printf("\n > Percorrendo a árvore - em ordem:\n");
    emOrdem_arvoreLLRB(raiz);

    printf("\n > Percorrendo a árvore - pós-ordem:\n");
    posOrdem_arvoreLLRB(raiz);

    printf("\n -----------------------------------------------------------------\n");

    //Removendo
    printf("\n (removendo o item 100...)\n");
    x = remove_arvoreLLRB(raiz, 100);

    printf("\n > Percorrendo a árvore - em ordem - pós exclusão:\n");
    emOrdem_arvoreLLRB(raiz);
    printf("\n -----------------------------------------------------------------\n");


    //Consultando
    printf("\n > Busca na árvore binária: 110\n");
    if(consulta_arvoreLLRB(raiz, 110)){
        printf("\n -- Elemento encontrado!\n.");
    }
    else{
        printf("\n -- Elemento não encontrado.\n");
    }

    printf("\n > Busca na árvore binária: 140\n");
    if(consulta_arvoreLLRB(raiz, 140)){
        printf("\n -- Elemento encontrado!\n");
    }
    else{
        printf("\n -- Elemento não encontrado.\n");
    }

    printf("\n -----------------------------------------------------------------\n");

    // Destruindo a árvore
    liberar_arvoreLLRB(raiz);
    printf(" > A árvore foi destruída.\n\n");

    return 0;
}
