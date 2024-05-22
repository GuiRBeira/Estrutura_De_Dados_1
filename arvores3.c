#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definindo uma nó de lista simplesmente
typedef struct no_simples no_simples;
struct no_simples{
    int chave;
    no_simples *direita;
    no_simples *esquerda;
};


bool busca_elemento(int chave, no_simples *raiz){
    // cria um ponteiro para percorrer a lista
    if(raiz == NULL){
        return false;
    }
    if(raiz->chave == chave){
        return true;
    }

    /*
    * enquanto a chave buscada for menor do que a chave apontada
    * por aux e tiver filho esquerdo, ou chave maior e tiver 
    * filho direito pula para o filho.
    */
    if(chave < raiz->chave){
        return busca_elemento(chave, raiz->esquerda);
    }
    else{
        return busca_elemento(chave, raiz->direita);
    }
}

// função para criar um novo nó
no_simples* cria_no(int chave){
    no_simples *novo = (no_simples *) malloc(sizeof(no_simples));

    if (novo == NULL){
        return NULL;
    }
    novo->chave = chave;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// adiciona novo elemento à árvore (forma iterativa)
bool adiciona_elemento(int chave,  no_simples **praiz){
    if(busca_elemento(chave, *praiz)){
        printf("nó existente: %d\n", chave);
        return false;
    }

    // cria novo nó:
    no_simples *novo = cria_no(chave);

    if (*praiz == NULL){
        *praiz = novo;
        return true;
    }

    // percorre toda a árvore até achar o pai do novo nó.
    no_simples *aux = *praiz;
    while((chave < aux->chave && aux->esquerda != NULL) ||
    (chave > aux->chave && aux->direita != NULL)){
        if (chave > aux->chave){
            aux = aux->direita;
        }
        else{
            aux = aux->esquerda;
        }
    }

    // adiciona novo nó ao pai
    if (chave > aux->chave){
        aux->direita = novo;
    }
    else{
        aux->esquerda = novo;
    }
    return true;

}

// função para adicionar elemento de forma recursiva
bool adiciona_elemento_rec(int chave, no_simples **praiz){

    // quando o ponteiro for null, adiciona o elemento.
    if (*praiz == NULL){
        no_simples *novo = cria_no(chave);
        *praiz = novo;
        return true;
    }

    // se chave já existe retorna falso
    if (chave == (*praiz)->chave){
        printf("chave já existe\n");
        return false;
    }
    // se chave a adicionar menor do que a chave apontada:
    // chama a função adiciona passando o filho esq como raiz
    else if(chave < (*praiz)->chave){
        adiciona_elemento(chave, &((*praiz)->esquerda));
    }
    // caso contrário adiciona na sub-árvore da direita
    else{
        adiciona_elemento(chave, &((*praiz)->direita));
    }

    return true;
}

void imprime_em_ordem(no_simples **praiz){
    if (*praiz == NULL){
        return;
    }

    // processa árvore da esquerda, imprime e processa a da direita
    imprime_em_ordem(&((*praiz)->esquerda));
    printf("%d ", (*praiz)->chave);
    imprime_em_ordem(&((*praiz)->direita));
}

int conta_elementos(no_simples **praiz){

    // testa se null
    if (*praiz == NULL){
        return 0;
    }

    // caso contrário soma elementos das sub-árvores
    int tot = 0;
    tot = tot + conta_elementos(&((*praiz)->esquerda));
    tot = tot + conta_elementos(&((*praiz)->direita));
    tot = tot + 1;
    //printf("\n el:%d %d", (*praiz)->chave, tot);

    return tot;
}

int conta_folha(no_simples *raiz){

    // testa se null
    if (raiz == NULL){
        return 0;
    }

    // testa se folha
    if (raiz->direita==NULL && raiz->esquerda==NULL){
        return 1;
    }

    // caso contrário soma folhas das sub-árvores
    int tot = conta_folha(raiz->esquerda);
    tot = tot + conta_folha(raiz->direita);
    printf("\n# %d %d", raiz->chave, tot);

    return tot;
}

int altura_arvore(no_simples *raiz){
    // testa se null
    if (raiz == NULL){
        return 0;
    }

    //testa se folha
    if (raiz->esquerda == NULL && raiz->direita){
        return 0;
    }

    //retorna a maior altura mais 1
    int c = raiz->chave;
    int alt_esq = altura_arvore(raiz->esquerda);
    int alt_dir = altura_arvore(raiz->direita)

    return (alt_esq > alt_dir)? alt_esq : alt_dir;
}



int main(){
    no_simples *raiz = NULL;

    int elementos[7] = {20, 12, 40, 7, 25, 60, 30};

    for (int i=0; i<7; i++){
        //adiciona_elemento(elementos[i], &raiz);
        adiciona_elemento_rec(elementos[i], &raiz);
    }

    // busca alguns elementos:
    printf("busca 25: %d\n", busca_elemento(25, raiz));
    printf("busca 10: %d\n", busca_elemento(10, raiz));

    printf("\n\nimprime em ordem: ");
    imprime_em_ordem(&raiz);

    printf("\nnum el: %d", conta_elementos(&raiz));
    printf("\nfolhas: %d", conta_folha(raiz));
    printf("\nFim\n");
}
