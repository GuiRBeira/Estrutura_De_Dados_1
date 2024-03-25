#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// tipo do nó (cada elemento) da fila dinâmica
typedef struct NodeQueue NodeQueue;

struct NodeQueue{
    int key;                  // um dado qqr
    NodeQueue *next;   // ponteiro para o próximo elemento
};

// tipo fila dinâmica:
typedef struct{
    NodeQueue *begin;         // inicio da fila
    NodeQueue *last;        // fim da fila
    int size;            // numero de elementos da fila
} DinamicQueue;

void append(int a, DinamicQueue *queue){
    NodeQueue *element = (NodeQueue *)malloc(sizeof(NodeQueue));
    if(element == NULL){
        write(1, "Erro ao alocar memória", 24);
        exit(1);
    }
    //preencher elemento
    element->key = a;
    element->next = NULL;

    //fila vazia
    if(queue->size == 0){
        queue->begin = element;
        queue->last = element;
    } else {
        NodeQueue *aux = queue->last;
        aux->next = element;
        queue->last = element; 
    }
    queue->size++;
}

void remover(int *x, DinamicQueue *queue){
    if(queue->size == 0){
        write(1, "A fila ta vazia", 16);
        return;
    }
    //criar um nó auxiliar
    NodeQueue *aux = queue->begin;
    //copiar o valor de retorno
    *x = aux->key;
    //atualizar o ponteiro "begin"

    //liberar a memoria do elemento removido
    queue->begin = aux->next;
    free(aux);
    queue->size--;
}

int main(){
    DinamicQueue queue = {NULL,NULL,0};
    append(8, &queue);
    append(10, &queue);
    append(12, &queue);
    append(-1, &queue);
    append(-5, &queue);
    int removed;
    printf("%d\n", queue.begin->key);
    printf("%d\n", queue.last->key);
    remover(&removed, &queue);
    printf("%d\n", queue.size);
    return 0;
}