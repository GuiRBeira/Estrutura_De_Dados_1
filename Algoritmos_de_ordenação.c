
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definindo uma nó de lista simplesmente encadeada
typedef struct no_simples no_simples;
struct no_simples{
    int idade;
    char nome[30];
    no_simples *prox;
};

// lista
typedef struct lista lista;
struct lista{
    int tamanho;
    no_simples *primeiro;
    no_simples *ultimo;
};

void adiciona_elemento(int idade, char nome[], lista *p){
    no_simples *novo = (no_simples *) malloc(sizeof(no_simples));

    if (novo == NULL){
        return;
    }
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (p->tamanho == 0){
        p->primeiro = novo;
        p->ultimo = novo;
    }
    else{
        p->ultimo->prox = novo;
        p->ultimo = novo;
    }
    p->tamanho++;
}

void imprime_lista(lista *p){
    printf("\n lista %d: ", p->tamanho);
    for(no_simples *x=p->primeiro; x != NULL; x = x->prox){
        //printf("nome: %s, idade: %d\n", x->nome, x->idade);
        printf("%d ", x->idade);
    }
}

void bubble_sort(lista *p){
    no_simples *x, *y, *ant;
    for (int i=0; i<p->tamanho; i++){
        x=p->primeiro;
        while(x->prox != NULL){
            if(x->idade > x->prox->idade){
                y = x->prox;
                x->prox = y->prox;
                y->prox = x;
                if (x == p->primeiro){
                    p->primeiro = y;
                }
                else{
                    ant->prox = y;
                }
                if (p->ultimo == y){
                    p->ultimo = x;
                }
                ant = y;
            }
            else{
                ant = x;
                x = x->prox;
            }
        }
        imprime_lista(p);

    }
}

void insertion_sort(lista *p, lista *q){

    for(no_simples *x=p->primeiro; x != NULL; x = x->prox){

        no_simples *novo = (no_simples *) malloc(sizeof(no_simples));

        if (novo == NULL){
            return;
        }
        novo->idade = x->idade;
        strcpy(novo->nome, x->nome);
        novo->prox = NULL;
        if (q->tamanho == 0){
            q->primeiro = novo;
            q->ultimo = novo;
        }
        else if(x->idade < q->primeiro->idade){
            novo->prox = q->primeiro;
            q->primeiro = novo;
        } else {
            no_simples *y = p->primeiro;
            while(y->prox == NULL && y->prox->idade < x->idade){
                y = y->prox;
            }
            novo->prox = x->prox;
            y->prox = novo;

        }
        q->tamanho++;

    }

}

int main(){
    // criar lista e adiciona nós
    lista lst = {0, NULL, NULL};

    adiciona_elemento(25, "paulo", &lst);
    adiciona_elemento(23, "ana", &lst);
    adiciona_elemento(27, "julia", &lst);
    adiciona_elemento(22, "fer", &lst);
    adiciona_elemento(19, "bia", &lst);

    imprime_lista(&lst);

    bubble_sort(&lst);
    imprime_lista(&lst);
    lista lll = {0, NULL, NULL};
    insertion_sort(&lst, &lll);    
    imprime_lista(&lll);
    printf("\nFim\n");
    return 1;
}