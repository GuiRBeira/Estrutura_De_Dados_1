#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct grafo {
    bool digrafo;
    int n_vertices;
    bool **matriz_adj; 
} Grafo;

void inicializar(Grafo *grafo, int n_vertices, bool digrafo);
void destroi(Grafo *grafo);
void insereAresta(Grafo *grafo, int origem, int destino);
void imprimeMatrizAdjacencia(Grafo *grafo);
int main(){
    Grafo grafo;
    inicializar(&grafo, 5, true); 
    insereAresta(&grafo, 0, 4); // Saída, Chegada (para grafos não dirigidos, a chegada e saída são intercambiáveis)
    insereAresta(&grafo, 0, 1);
    insereAresta(&grafo, 1, 2);
    insereAresta(&grafo, 1, 3);
    insereAresta(&grafo, 1, 4);
    insereAresta(&grafo, 2, 3);
    insereAresta(&grafo, 3, 4);
    imprimeMatrizAdjacencia(&grafo);
    destroi(&grafo);
    return EXIT_SUCCESS;
}

void inicializar(Grafo *grafo, int n_vertices, bool digrafo){
    grafo->digrafo = digrafo;
    grafo->n_vertices = n_vertices;
    grafo->matriz_adj = (bool **)malloc(sizeof(bool *) * n_vertices);
    for(int i = 0; i < n_vertices; i++){
        grafo->matriz_adj[i] = (bool *)malloc(sizeof(bool) * n_vertices);
        for(int j = 0; j < n_vertices; j++){
            grafo->matriz_adj[i][j] = false;
        }
    }
}

void destroi(Grafo *grafo){
    for(int i = 0; i < grafo->n_vertices; i++){
        free(grafo->matriz_adj[i]);
    }
    free(grafo->matriz_adj);
}

void insereAresta(Grafo *grafo, int origem, int destino){
    if(origem >= grafo->n_vertices || destino >= grafo->n_vertices){
        printf("Aresta inserida não é válida!\n");
        return;
    } 
    grafo->matriz_adj[origem][destino] = true;
    if (grafo->digrafo) {
        grafo->matriz_adj[destino][origem] = true;
    }
}

void imprimeMatrizAdjacencia(Grafo *grafo) {
    printf("Matriz de Adjacência:\n");
    printf("   ");
    for (int i = 0; i < grafo->n_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < grafo->n_vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < grafo->n_vertices; j++) {
            printf("%d ", grafo->matriz_adj[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}
