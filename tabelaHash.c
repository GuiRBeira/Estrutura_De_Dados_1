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
    for(posicao; posicao < SIZE; (++posicao)%SIZE){
        if(c->cardapio[posicao].id == -1){
            return posicao;
        }
    }
}

bool inserirElemento(TabelaHash *c, Produto e){
    if(c->q_elements == SIZE){
        printf("Lista cheia");
        return false;
    } else {
        int posicao = funcaoHash(c, e.id); 
        c->q_elements++;       
    }
    
}

int main(){
    TabelaHash tabela;
    inicializaTabelaHash(&tabela);
    inserirElemento(&tabela, (Produto){86031, "Bacon", 23.00});
    inserirElemento(&tabela, (Produto){12011, "Marguerita", 23.00});
    inserirElemento(&tabela, (Produto){15155, "Cogumelo", 30.00});
    inserirElemento(&tabela, (Produto){22132, "Frango", 30.00});
    inserirElemento(&tabela, (Produto){18138, "Camarao", 48.00});
    inserirElemento(&tabela, (Produto){13133, "Calabresa", 25.00});
    inserirElemento(&tabela, (Produto){03121, "Palmito", 35.00});
    inserirElemento(&tabela, (Produto){11210, "Picanha", 45.00});
    return EXIT_SUCCESS;
}