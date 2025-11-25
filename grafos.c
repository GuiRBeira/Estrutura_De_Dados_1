#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool digrafo;
    int n_vertices;
    int **matriz_adj; // Alteração para suportar pesos inteiros
} Grafo;

typedef struct {
    int items[100];
    int front;
    int rear;
} Queue;

void inicializar(Grafo *grafo, int n_vertices, bool digrafo);
void destroi(Grafo *grafo);
void insereAresta(Grafo *grafo, int origem, int destino, int peso);
void imprimeMatrizAdjacencia(Grafo *grafo);
bool DFSUtil(Grafo *grafo, int v, bool *visitado, int target);
bool DFS(Grafo *grafo, int start, int target);
Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
bool isEmpty(Queue* q);
void BFS(Grafo *grafo, int start);

int main(){
    Grafo grafo;
    inicializar(&grafo, 5, false);
    insereAresta(&grafo, 0, 4, 10); // Exemplo de aresta com peso 10
    insereAresta(&grafo, 0, 1, 5);  // Exemplo de aresta com peso 5
    insereAresta(&grafo, 1, 2, 3);  // Exemplo de aresta com peso 3
    insereAresta(&grafo, 1, 3, 7);  // Exemplo de aresta com peso 7
    insereAresta(&grafo, 1, 4, 8);  // Exemplo de aresta com peso 8
    insereAresta(&grafo, 2, 3, 1);  // Exemplo de aresta com peso 1
    insereAresta(&grafo, 3, 4, 4);  // Exemplo de aresta com peso 4
    imprimeMatrizAdjacencia(&grafo);
    bool found = DFS(&grafo, 0, 1);
    
    if (found) {
        printf("Vertice %d encontrado.\n", 1);
    } else {
        printf("Vertice %d não encontrado.\n", 1);
    }
    BFS(&grafo, 4);
    destroi(&grafo);
    return EXIT_SUCCESS;
}

void inicializar(Grafo *grafo, int n_vertices, bool digrafo){
    grafo->digrafo = digrafo;
    grafo->n_vertices = n_vertices;
    grafo->matriz_adj = (int **)malloc(sizeof(int *) * n_vertices);
    for(int i = 0; i < n_vertices; i++){
        grafo->matriz_adj[i] = (int *)malloc(sizeof(int) * n_vertices);
        for(int j = 0; j < n_vertices; j++){
            grafo->matriz_adj[i][j] = 0; // Inicializa com 0 para indicar ausência de cone+xão
        }
    }
}

void destroi(Grafo *grafo){
    for(int i = 0; i < grafo->n_vertices; i++){
        free(grafo->matriz_adj[i]);
    }
    free(grafo->matriz_adj);
}

void insereAresta(Grafo *grafo, int origem, int destino, int peso){
    if(origem >= grafo->n_vertices || destino >= grafo->n_vertices){
        printf("Aresta inserida não é válida!\n");
        return;
    }
    grafo->matriz_adj[origem][destino] = peso;
    if (!grafo->digrafo) {
        grafo->matriz_adj[destino][origem] = peso;
    }
}

void imprimeMatrizAdjacencia(Grafo *grafo) {
    printf("Matriz de Adjacencia:\n");
    printf("   ");
    for (int i = 0; i < grafo->n_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < grafo->n_vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < grafo->n_vertices; j++) {
            printf("%d ", grafo->matriz_adj[i][j]);
        }
        printf("\n");
    }
}

bool DFSUtil(Grafo *grafo, int v, bool *visitado, int target) {
    visitado[v] = true;
    printf("Visitando o vertice %d\n", v);
    if (v == target) {
        return true;
    }
    for (int i = 0; i < grafo->n_vertices; i++) {
        if (grafo->matriz_adj[v][i] != -1 && !visitado[i]) {
            if (DFSUtil(grafo, i, visitado, target)) {
                return true;
            }
        }
    }
    return false;
}

bool DFS(Grafo *grafo, int start, int target) {
    bool *visitado = (bool *)malloc(grafo->n_vertices * sizeof(bool));
    for (int i = 0; i < grafo->n_vertices; i++) {
        visitado[i] = false;
    }
    bool found = DFSUtil(grafo, start, visitado, target);
    free(visitado);
    return found;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == 100 - 1) {
        printf("\nQueue is Full!!");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

void BFS(Grafo *grafo, int start) {
    Queue* q = createQueue();
    bool* visitado = (bool*)malloc(sizeof(bool) * grafo->n_vertices);
    for (int i = 0; i < grafo->n_vertices; i++) {
        visitado[i] = false;
    }
    visitado[start] = true;
    enqueue(q, start);
    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("Visitando o vertice %d\n", v);     
        for (int i = 0; i < grafo->n_vertices; i++) {
            if (grafo->matriz_adj[v][i] != -1 && !visitado[i]) {
                visitado[i] = true;
                enqueue(q, i);
            }
        }
    }   
    free(visitado);
    free(q);
}