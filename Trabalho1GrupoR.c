#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef nopilha nopilha;

struct nopilha{
   int k;
   nopilha *prox;
};

typedef struct{
   nopilha *topo;
   int tamanho;
} pilha_dinamica;

void push(int x, pilha_dinamica *p){
   nopilha *novo = (nopilha *)malloc(sizeof(nopilha));
   novo->k = x;
   novo->prox = p->topo;
   p->topo = novo;
   p->tamanho++;
}

bool pop(int *x, pilha_dinamica *p){

   if(p->tamanho == 0){
       return false;
   }
   nopilha *aux= p->topo;
   *x = aux->k;
   p->topo = aux->prox;
   p->tamanho--;
   free(aux);
   return true;
}

int colchetes_balanceados(const char *exp){
    pilha_dinamica p = {NULL,0};
    char c;
    //vai entrar uma string nessa funcao, logo se eu quiser percorrer todo o tamanho de uma string
    // de tamanho desconhecido, podemos percorrer os elementos da string exp[i] ate o fim \0, ou
    // percorrer os elementos de exp com i < strlen()
    for(int i = 0; exp[i] != '\0'; i++){
        c = exp[i];
        //se for o comeco de um colchete:
        if(c == '(' || c == '[' || c == '{'){
            push(c, &p); /*ou seja se a string comeca com um colchete aberto, ele podera ser fechado no decorrer dela
            por isto adicionamos a pilha, agora caso ele ja encontre um colchete de fechamento e seja o primeiro elemtento da string,
            podemos retornar 0.*/
        } else if((p.tamanho == 0) && (c == ')' || c == ']' || c == '}')){
            return 0;
        }
    }
}