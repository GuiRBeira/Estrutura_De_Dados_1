#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerdo;
    struct No* direito;
} No;

void imprimirFilhos(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    int esq = -1, dir = -1;

    if (raiz->esquerdo != NULL) {
        esq = raiz->esquerdo->valor;
    }
    if (raiz->direito != NULL) {
        dir = raiz->direito->valor;
    }

    printf("%d %d %d\n", raiz->valor, esq, dir);
}

// função para criar um nó (desconsiderar)
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

int main() {
    No* raiz = criarNo(5);
    No* esq = criarNo(7);
    No* dir = criarNo(9);
    raiz->esquerdo = esq;
    raiz->direito = dir;
    imprimirFilhos(raiz);
    return 0;
}
