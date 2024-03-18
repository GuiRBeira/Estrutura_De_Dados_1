#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// tipo do nó (cada elemento) da pilha dinâmica
typedef struct{
    int k;                  // um dado qqr
    struct nopilha *prox;   // ponteiro para o próximo elemento
} nopilha;

// tipo pilha dinâmica:
typedef struct{
    nopilha *topo;          // topo da pilha
    int tamanho;            // numero de elementos da pilha
} pilha_dinamica;

// adiciona elemento à pilha
void push(int x, pilha_dinamica *p){
    
    // cria e preenche novo elemento
    nopilha *novo = (nopilha *)malloc(sizeof(nopilha));
    novo->k = x;
    novo->prox = p->topo;

    // atualiza pilha
    p->topo = novo;
    p->tamanho++;
}

// remove elemento do topo da pilha
bool pop(int *x, pilha_dinamica *p){
    if (p->tamanho <= 0){
        return false;
    }

    // salva referência para o primeiro elemento e salva dado de retorno
    nopilha *aux = p->topo;
    *x = aux->k;

    // atualiza pilha:
    p->topo = aux->prox;    // topo aponta para segundo elemento da pilha
    p->tamanho--;           // decrementa número de elementos

    // libera memória e retorna
    free(aux);
    return true;
}

void dec2bin(int dec, pilha_dinamica *p){
    printf("decimal: %d\n", dec);
    int resultado = 0;
   
    while(dec != 0){
        resultado = dec % 2; 
        push(resultado, p);
        resultado = 0;
        dec /=2;
    }
    
    printf("\n\nconvertido: ");
    int b;
    while(p->topo > NULL){
        pop(&b, p);
        printf("%d",b);
    }
    printf("\n");
}


int main(){
    // cria pilha
    pilha_dinamica pd = {NULL, 0};
    int x;
    printf("digite um numero: ");
    scanf("%d", &x);

    dec2bin(x, &pd);


    // adiciona elemento à pilha
    //push(5, &pd);

    //remove elemento
    //int i;
    //pop(&i, &pd);

    // mostra elemento removido e informações da pilha
    //printf("valor: %d, tamanho: %d, topo: %p\n", i, pd.tamanho, pd.topo);
    //return 0;
}