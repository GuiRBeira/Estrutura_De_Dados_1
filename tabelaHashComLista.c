#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 11
#define A 0.618

typedef struct Produto {
    unsigned int id;
    char *sabor;
    float valor;
    struct Produto *next;
} Produto;

typedef struct {
    Produto *cardapio[SIZE];
    unsigned int q_elements;
} TabelaHash;

void init(TabelaHash *tabela) {
    for (int i = 0; i < SIZE; i++) {
        tabela->cardapio[i] = NULL;
    }
    tabela->q_elements = 0;
}

int funcaoHash(unsigned int id) {
    return (int)(SIZE * ((id * A) - (int)(id * A)));
}

bool inserirElemento(TabelaHash *tabela, Produto *produto) {
    int posicao = funcaoHash(produto->id);
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro de alocacao de memoria\n");
        return false;
    }
    *novoProduto = *produto;
    novoProduto->sabor = strdup(produto->sabor); // Copiar a string para evitar problemas com ponteiros
    novoProduto->next = tabela->cardapio[posicao];
    tabela->cardapio[posicao] = novoProduto;
    tabela->q_elements++;
    return true;
}

void imprimeTabela(TabelaHash *tabela) {
    printf("Cardapio pizzaria\n");
    for (int i = 0; i < SIZE; i++) {
        Produto *produto = tabela->cardapio[i];
        if (produto != NULL) {
            while (produto != NULL) {
                printf("Posicao: %d\n", i);
                printf("ID: %d\n", produto->id);
                printf("Sabor: %s\n", produto->sabor);
                printf("Preco: %.2f\n", produto->valor);
                printf("------------------------------\n");
                produto = produto->next;
            }
        }
    }
}

Produto* buscaElemento(TabelaHash *tabela, unsigned int id) {
    int posicao = funcaoHash(id);
    Produto *produto = tabela->cardapio[posicao];
    while (produto != NULL) {
        if (produto->id == id) {
            return produto;
        }
        produto = produto->next;
    }
    return NULL;
}

int main() {
    TabelaHash tabela;
    init(&tabela);
    inserirElemento(&tabela, &(Produto){86031, "Bacon", 23.00, NULL});
    inserirElemento(&tabela, &(Produto){12011, "Marguerita", 23.00, NULL});
    inserirElemento(&tabela, &(Produto){15155, "Cogumelo", 30.00, NULL});
    inserirElemento(&tabela, &(Produto){22132, "Frango", 30.00, NULL});
    inserirElemento(&tabela, &(Produto){18138, "Camarao", 48.00, NULL});
    inserirElemento(&tabela, &(Produto){13133, "Calabresa", 25.00, NULL});
    inserirElemento(&tabela, &(Produto){13121, "Palmito", 35.00, NULL});
    inserirElemento(&tabela, &(Produto){11210, "Picanha", 45.00, NULL});
    imprimeTabela(&tabela);

    Produto* p = buscaElemento(&tabela, 13121);
    if (p != NULL) {
        printf("Elemento encontrado:\n");
        printf("ID: %d\n", p->id);
        printf("Sabor: %s\n", p->sabor);
        printf("Preco: %.2f\n", p->valor);
    } else {
        printf("Elemento nao encontrado..\n");
    }

    return EXIT_SUCCESS;
}
