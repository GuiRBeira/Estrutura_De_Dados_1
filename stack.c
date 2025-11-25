#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int k;
    struct stack *prox;
}stack;

typedef struct{
    stack *top;
    unsigned short int size;
}stack_dinamic;

void push(int x, stack_dinamic *p){
    stack *new = (stack *)malloc(sizeof(stack));
    new->k = x;
    new->prox = p->top;
    p->top = new;
    p->size++;
}

bool pop(int *x, stack_dinamic *p){
    if(p->size == 0){
        return false;
    }
    stack *aux = p->top;
    *x = aux->k;
    p->top = aux->prox;
    p->size--;
    free(aux);
    return true;
}

int main(){
    stack_dinamic sd = {NULL,0};
    int com, valor;
    do{
        printf("Insira o comando desejado:\n 0 - push\n 1 - pop\n -1 - fechar programa");
        scanf("%d", &com);
        switch (com){
            case (0):
                printf("Insira o valor para adicionar: ");
                scanf("%d", &valor);
                push(valor, &sd);

            case (1):
                if(pop(&valor, &sd)){
                    printf("Elemento excluído com sucesso!\nValor excluído %d\nTamanho da pilha: %u\nTopo da pilha: %d", valor, sd.size, sd.top);
                }else{
                    printf("A pilha está vazia");
                }
            
            case (-1):
                break;

            default:
                printf("Comando invalido");
            }
    } while(com == -1);
    return 0;
}