#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 11
#define A 0.618

typedef struct{
    int id;
    char sabor[20];
    float valor;
}Produto;

typedef struct{
    Produto cardapio[SIZE];
    int q_elements;
}TabelaHash;

void inicializaTabelaHash(TabelaHash *c){
    for(int i = 0; i < SIZE; i++){
        c->cardapio[i].id = -1;
    }
    c->q_elements = 0;
}

int funcaoHash(TabelaHash *c, int id){
    //metodo da multiplicacao
    int posicao = (int)(SIZE*((id*A)-(int)(id*A)));
    do{
        if(c->cardapio[posicao].id == -1) return posicao;
        ++posicao; posicao%=SIZE;
    }while(true);
}

bool inserirElemento(TabelaHash *c, Produto e){
    if(c->q_elements == SIZE){
        printf("Lista cheia");
        return false;
    } else {
        int posicao = funcaoHash(c, e.id); 
        c->cardapio[posicao] = e;
        c->q_elements++;
        return true;
    }
}

void imprimeTabela(TabelaHash *c){
    printf("Cardapio pizzaria\n");
    for(int i = 0; i < SIZE; i++){
        if(c->cardapio[i].id != -1){
            printf("Posicao: %d\nID: %d\n", i, c->cardapio[i].id);
            printf("Sabor: %s\n", c->cardapio[i].sabor);
            printf("Preço: %.2f\n",c->cardapio[i].valor);
            printf("------------------------------\n");
        }
    }
    printf("Fim\n");
}

int buscaElemento(TabelaHash *c, int id);

int main(){
    TabelaHash tabela;

    inicializaTabelaHash(&tabela);
    inserirElemento(&tabela, (Produto){86031, "Bacon", 23.00});
    inserirElemento(&tabela, (Produto){12011, "Marguerita", 23.00});
    inserirElemento(&tabela, (Produto){15155, "Cogumelo", 30.00});
    inserirElemento(&tabela, (Produto){22132, "Frango", 30.00});
    inserirElemento(&tabela, (Produto){18138, "Camarao", 48.00});
    inserirElemento(&tabela, (Produto){13133, "Calabresa", 25.00});
    inserirElemento(&tabela, (Produto){13121, "Palmito", 35.00});
    inserirElemento(&tabela, (Produto){11210, "Picanha", 45.00});
    imprimeTabela(&tabela);
    
    int pos = buscaElemento(&tabela, 13121);
    if(pos >= 0){
        printf("Posicao: %d\nID: %d\n", pos, tabela.cardapio[pos].id);
        printf("Sabor: %s\n", tabela.cardapio[pos].sabor);
        printf("Preço: %.2f\n",tabela.cardapio[pos].valor);
        printf("------------------------------\n");
    } else {
        printf("Elemento não encontrado..\n");
    }
    return EXIT_SUCCESS;
}

int buscaElemento(TabelaHash *c, int id){
    int posicao = (int)(SIZE*((id*A)-(int)(id*A)));
    if(c->cardapio[posicao].id == id) return posicao;
    int i = 0;
    do{
        ++posicao;
        posicao%=SIZE;
        if(c->cardapio[posicao].id == id) return posicao;
        else if (c->cardapio[posicao].id == -1) return -1;
        i++;
    }while (i <= SIZE);
}