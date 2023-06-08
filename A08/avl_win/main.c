#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");
    int x; //retornoz

    avlTree *raiz;

    raiz = criar_avlTree();

    if(vazia_avlTree(raiz)){
        printf("\n > Árvore vazia!\n");
    }
    else{
        printf("\n > Árvore possui elementos!\n");
    }

        Pessoa pessoas[6];

        // Initializing the first person
        pessoas[0].codigo = 1;
        pessoas[0].nome = strdup("John Doe");
        pessoas[0].idade = 30;
        pessoas[0].empresa = strdup("ABC Corp");
        pessoas[0].departamento = strdup("HR");
        pessoas[0].salario = 5000.0;

        // Initializing the second person
        pessoas[1].codigo = 2;
        pessoas[1].nome = strdup("Jane Smith");
        pessoas[1].idade = 35;
        pessoas[1].empresa = strdup("XYZ Company");
        pessoas[1].departamento = strdup("Marketing");
        pessoas[1].salario = 6000.0;

        // Initializing the third person
        pessoas[2].codigo = 3;
        pessoas[2].nome = strdup("Michael Johnson");
        pessoas[2].idade = 42;
        pessoas[2].empresa = strdup("ACME Corporation");
        pessoas[2].departamento = strdup("Engineering");
        pessoas[2].salario = 8000.0;

        // Initializing the fourth person
        pessoas[3].codigo = 4;
        pessoas[3].nome = strdup("Emily Davis");
        pessoas[3].idade = 28;
        pessoas[3].empresa = strdup("Tech Solutions");
        pessoas[3].departamento = strdup("IT");
        pessoas[3].salario = 5500.0;

        // Initializing the fifth person
        pessoas[4].codigo = 5;
        pessoas[4].nome = strdup("David Brown");
        pessoas[4].idade = 37;
        pessoas[4].empresa = strdup("Global Corp");
        pessoas[4].departamento = strdup("Sales");
        pessoas[4].salario = 7000.0;

        // Initializing the sixth person
        pessoas[5].codigo = 6;
        pessoas[5].nome = strdup("Sophia Wilson");
        pessoas[5].idade = 31;
        pessoas[5].empresa = strdup("Big Co.");
        pessoas[5].departamento = strdup("Finance");
        pessoas[5].salario = 6500.0;


    x = inserir_avlTree(raiz, pessoas[0]);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, pessoas[1]);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, pessoas[2]);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, pessoas[3]);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, pessoas[4]);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));
    x = inserir_avlTree(raiz, pessoas[5]);
    (x)? (printf("  -Elemento inserido com sucesso!\n")) : (printf("Erro ao inserir!\n"));

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

    int i = 0;
    printf("\n > Busca na árvore binária: %d\n", i);
    if(consulta_avlTree(raiz, i-1)){
        printf("Person %d\n", i);
        printf("Code: %d\n", pessoas[i].codigo);
        printf("Name: %s\n", pessoas[i].nome);
        printf("Age: %d\n", pessoas[i].idade);
        printf("Company: %s\n", pessoas[i].empresa);
        printf("Department: %s\n", pessoas[i].departamento);
        printf("Salary: %.2f\n", pessoas[i].salario);
        printf("\n");
    }
    else{
        printf("\n -- Elemento não encontrado.\n");
    }

    i = 5;
    printf("\n > Busca na árvore binária: %d\n", i);
    if(consulta_avlTree(raiz, i)){
        printf("Person %d\n", i);
        printf("Code: %d\n", pessoas[i].codigo);
        printf("Name: %s\n", pessoas[i].nome);
        printf("Age: %d\n", pessoas[i].idade);
        printf("Company: %s\n", pessoas[i].empresa);
        printf("Department: %s\n", pessoas[i].departamento);
        printf("Salary: %.2f\n", pessoas[i].salario);
        printf("\n");
    }
    else{
        printf("\n -- Elemento não encontrado.\n");
    }

     i = 7;
    printf("\n > Busca na árvore binária: %d\n", i);
    if(consulta_avlTree(raiz, i)){
        printf("Person %d\n", i);
        printf("Code: %d\n", pessoas[i].codigo);
        printf("Name: %s\n", pessoas[i].nome);
        printf("Age: %d\n", pessoas[i].idade);
        printf("Company: %s\n", pessoas[i].empresa);
        printf("Department: %s\n", pessoas[i].departamento);
        printf("Salary: %.2f\n", pessoas[i].salario);
        printf("\n");
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



