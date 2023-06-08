#include <stdio.h>
#include <stdlib.h>
#include "arvoreRN.h"

int main(){

    int x; //retorno

    arvoreLLRB *raiz;

    raiz = criar_arvoreLLRB();

    if(vazia_arvoreLLRB(raiz)){
        printf("\n > �rvore vazia!\n");
    }
    else{
        printf("\n > �rvore possui elementos!\n");
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
        printf("\n > �rvore vazia!\n");
    }
    else{
        printf("\n > �rvore possui elementos!\n");
    }

    x = altura_arvoreLLRB(raiz);
    printf(" \n > Altura da �rvore: %d \n", x);

    x = totalNO_arvoreLLRB(raiz);
    printf(" \n > Total de n�s: %d \n", x);

    printf("\n -----------------------------------------------------------------\n");

    //Percorrendo:
    printf("\n > Percorrendo a �rvore - pr�-ordem:\n");
    preOrdem_arvoreLLRB(raiz);

    printf("\n > Percorrendo a �rvore - em ordem:\n");
    emOrdem_arvoreLLRB(raiz);

    printf("\n > Percorrendo a �rvore - p�s-ordem:\n");
    posOrdem_arvoreLLRB(raiz);

    printf("\n -----------------------------------------------------------------\n");

    //Removendo
    printf("\n (removendo o item 100...)\n");
    x = remove_arvoreLLRB(raiz, 100);

    printf("\n > Percorrendo a �rvore - em ordem - p�s exclus�o:\n");
    emOrdem_arvoreLLRB(raiz);
    printf("\n -----------------------------------------------------------------\n");


    //Consultando
    printf("\n > Busca na �rvore bin�ria: 110\n");
    if(consulta_arvoreLLRB(raiz, 110)){
        printf("\n -- Elemento encontrado!\n.");
    }
    else{
        printf("\n -- Elemento n�o encontrado.\n");
    }

    printf("\n > Busca na �rvore bin�ria: 140\n");
    if(consulta_arvoreLLRB(raiz, 140)){
        printf("\n -- Elemento encontrado!\n");
    }
    else{
        printf("\n -- Elemento n�o encontrado.\n");
    }

    printf("\n -----------------------------------------------------------------\n");

    // Destruindo a �rvore
    liberar_arvoreLLRB(raiz);
    printf(" > A �rvore foi destru�da.\n\n");

    return 0;
}
