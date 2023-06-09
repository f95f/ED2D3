typedef struct NO *avlTree;

avlTree *criar_avlTree();

void liberar_avlTree(avlTree *raiz);

int vazia_avlTree(avlTree *raiz);

int altura_avlTree(avlTree *raiz);

int totalNO_avlTree(avlTree *raiz);

// Percorrendo a árvore
    // - Pré-ordem
void preOrdem_avlTree(avlTree *raiz);

// Percorrendo a árvore
    // - Em ordem
void emOrdem_avlTree(avlTree *raiz);

// Percorrendo a árvore
    // - Pós-ordem
void posOrdem_avlTree(avlTree *raiz);

//consulta
int consulta_avlTree(avlTree *raiz, int valor);

//inserindo

int inserir_avlTree(avlTree *raiz, int valor);

//removendo
int remover_avlTree(avlTree *raiz, int valor);
