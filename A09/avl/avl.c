
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct NO{

    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;

};

avlTree *criar_avlTree(){

    avlTree *raiz = (avlTree*) malloc(sizeof(avlTree));

    if(raiz != NULL){
        *raiz = NULL;
    }

    return raiz;
}

int fatorBalanceamento_NO(struct NO * no){

    return labs(altura_no(no -> esq) - altura_no(no -> dir));

}

int altura_no(struct NO *no){

    if(no == NULL){
        return -1;
    }
    else{
        return no -> altura;
    }

}

int maior(int x, int y){

    if(x > y){
        return(x);
    }
    else{
        return(y);
    }
}

void liberar_avlTree(avlTree *raiz){

    if(raiz == NULL){
        return;
    }

    libera_NO(*raiz);
    free(raiz);
}

void libera_NO(struct NO *no){

    if(no == NULL){
        return;
    }

    libera_NO(no -> esq);
    libera_NO(no -> dir);

    free(no);

    no = NULL;
}

int vazia_avlTree(avlTree *raiz){

    if(raiz == NULL) { return 1;}
    if(*raiz == NULL){ return 1;}

    return 0;
}

int altura_avlTree(avlTree *raiz){

    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){ return 0;}

    int alt_esq = altura_avlTree(&((*raiz) -> esq));
    int alt_dir = altura_avlTree(&((*raiz) -> dir));

    if(alt_esq > alt_dir){

        return(alt_esq + 1);
    }
    else{

        return(alt_dir + 1);
    }

}

int totalNO_avlTree(avlTree *raiz){

    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){return 0;}

    int alt_esq = totalNO_avlTree(&((*raiz) -> esq));
    int alt_dir = totalNO_avlTree(&((*raiz) -> dir));

    return(alt_esq + alt_dir + 1);

}

// Percorrendo a árvore
// - Pré-ordem

void preOrdem_avlTree(avlTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){

        printf(" -- %d\n", ((*raiz) -> info));
        preOrdem_avlTree(&((*raiz) -> esq));
        preOrdem_avlTree(&((*raiz) -> dir));

    }

}

// Em ordem
void emOrdem_avlTree(avlTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){
        emOrdem_avlTree(&((*raiz) -> esq));
        printf(" -- %d\n", (*raiz) -> info);
        emOrdem_avlTree(&((*raiz) -> dir));
    }

}

// Pós-ordem
void posOrdem_avlTree(avlTree *raiz){

    if(raiz == NULL){ return; }

    if(*raiz != NULL){

        posOrdem_avlTree(&((*raiz) -> esq));
        posOrdem_avlTree(&((*raiz) -> dir));
        printf(" -- %d\n", (*raiz) -> info);

    }

}

//consultando ----------------------------------------------------------------
int consulta_avlTree(avlTree *raiz, int valor){

    if(raiz == NULL){ return 0;}

    struct NO *atual = *raiz;

    while(atual != NULL){

        if(valor == atual -> info){
            return 1;
        }

        if(valor > atual -> info){
            atual = atual -> dir;
        }
        else{
            atual = atual -> esq;
        }
    }

    return 0;
}

// - Rotações

void rotacaoLL(avlTree *raiz){

    struct NO *no;

    no = (*raiz) -> esq;

    (*raiz) -> esq = no -> dir;
    no -> dir = *raiz;

    (*raiz) -> altura = maior(altura_no((*raiz) -> esq), altura_no((*raiz) -> dir)) +1;
    no -> altura = maior(altura_no(no -> esq), (*raiz) -> altura) +1; // ---------------------correto?
    *raiz = no;

}

void rotacaoRR(avlTree *raiz){

    struct NO *no;

    no = (*raiz) -> dir;

    (*raiz) -> dir = no -> esq;
    no -> esq = *raiz;

    (*raiz) -> altura = maior(altura_no((*raiz) -> esq), altura_no((*raiz) -> dir)) +1;
    no -> altura = maior(altura_no(no -> dir), (*raiz) -> altura) +1;
    *raiz = no;

}

void rotacaoLR(avlTree *raiz){

    rotacaoRR(&(*raiz) -> esq);
    rotacaoLL(raiz);

}

void rotacaoRL(avlTree *raiz){

    rotacaoLL(&(*raiz) -> dir);
    rotacaoRR(raiz);

}

//inserções
int inserir_avlTree(avlTree *raiz, int valor){

    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof (struct NO));

        if(novo == NULL){return 0;}

        novo -> info = valor;
        novo -> altura = 0;
        novo -> esq = NULL;
        novo -> dir = NULL;

        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;

    if(valor < atual -> info){

        if((res = inserir_avlTree(&(atual -> esq), valor)) == 1){

            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor < (*raiz) -> esq -> info){
                    rotacaoLL(raiz);
                }
                else{
                    rotacaoLR(raiz);
                }
            }
        }
    }
    else{

        if(valor > atual -> info){

            if((res = inserir_avlTree(&(atual -> dir), valor)) == 1){

                if(fatorBalanceamento_NO(atual) >= 2){

                    if((*raiz) -> dir -> info < valor){

                        rotacaoRR(raiz);
                    }
                    else{

                        rotacaoRL(raiz);
                    }
                }
            }
        }
        else{
            printf("Valor Duplicado!\n");
            return 0;
        }
    }
    atual -> altura = maior(altura_no(atual -> esq), altura_no(atual -> dir)) + 1;
    return res;
}

int remover_avlTree(avlTree *raiz, int valor){

    if(*raiz == NULL){ return 0;}

    int res;
    if(valor < (*raiz) -> info){

        if((res = remover_avlTree(&(*raiz) -> esq, valor)) == 1){

            if(fatorBalanceamento_NO(*raiz) >= 2){

                if(altura_no((*raiz) -> dir -> esq) <= altura_no((*raiz) -> dir -> dir)){

                    rotacaoRR(raiz);
                }
                else{
                    rotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz) -> info > valor){

        if((res = remover_avlTree(&(*raiz) -> esq, valor)) == 1){

            if(fatorBalanceamento_NO(*raiz) >= 2){

                if(altura_no((*raiz) -> esq -> dir) <= altura_no((*raiz) -> esq -> esq)){

                    rotacaoLL(raiz);

                }
                else{

                    rotacaoLR(raiz);
                }
            }
        }
    }

    if((*raiz) -> info == valor){

        if(((*raiz) -> esq == NULL) || (*raiz) -> dir == NULL){

            struct NO *no_velho = (*raiz);
            if((*raiz) -> esq != NULL){

                *raiz = (*raiz) -> esq;

            }
            else{

                *raiz = (*raiz) -> dir;

            }
            free(no_velho);
        }
        else{

            struct NO *temp = procurarMenor((*raiz) -> dir);
            (*raiz) -> info = temp -> info;

            remover_avlTree((*raiz) -> dir, (*raiz) -> info);
            if(fatorBalanceamento_NO(*raiz) >= 2){

                if(altura_no((*raiz) -> esq -> dir) <= altura_no((*raiz) -> esq -> esq)){

                    rotacaoLL(raiz);

                }
                else{

                    rotacaoLR(raiz);
                }

            }

        }
        if(*raiz != NULL){

            (*raiz) -> altura = maior(altura_no((*raiz) -> esq), altura_no((*raiz) -> dir)) + 1;

        }
        return 1;
    }
    if(*raiz != NULL){

        (*raiz) -> altura = maior(altura_no((*raiz) -> esq), altura_no((*raiz) -> dir)) + 1;

    }
    return res;

}

struct NO *procurarMenor(struct NO *atual){

    struct NO *no1 = atual;
    struct NO *no2 = atual -> esq;

    while(no2 != NULL){

        no1 = no2;
        no2 = no2 -> esq;

    }

    return no1;

}


