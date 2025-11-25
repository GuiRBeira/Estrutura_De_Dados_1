#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore binária de busca (BST)
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        // Cria um novo nó se a árvore estiver vazia
        return createNode(data);
    }

    // Se o dado for menor que o valor do nó atual, insere à esquerda
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    // Se o dado for maior que o valor do nó atual, insere à direita
    else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Função para imprimir a árvore em ordem (in-order traversal)
void imprimirArvore(Node* root) {
    if (root == NULL) {
        return;
    }
    // Imprimir subárvore esquerda
    imprimirArvore(root->left);
    // Imprimir o nó atual
    printf("%d ", root->data);
    // Imprimir subárvore direita
    imprimirArvore(root->right);
}

int main() {
    // Array de dados
    int data[] = {4, 2, 5, 1, 6, 3, 7};
    int n = sizeof(data) / sizeof(data[0]);

    // Criando a árvore binária de busca (BST)
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertNode(root, data[i]);
    }

    // Imprimindo a árvore
    printf("Árvore em ordem: ");
    imprimirArvore(root);
    printf("\n");

    return 0;
}
