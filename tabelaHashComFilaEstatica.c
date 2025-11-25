#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 5 // Tamanho da fila estática
#define TABLE_SIZE 10 // Tamanho da tabela de hash
#define A ((sqrt(5) - 1) / 2)

typedef struct {
    int key;
    // Outros campos, se necessário
} Element;

typedef struct {
    Element elements[SIZE]; // Fila estática de elementos
    int count; // Contador de elementos na fila estática
} StaticQueue;

typedef struct {
    StaticQueue table[TABLE_SIZE]; // Tabela de hash
    unsigned int q_elements;
} HashTable;

int hashFunction(int key, int attempt) {
    return (int)(TABLE_SIZE * fmod((key + attempt * attempt) * A, 1));
}

void insertElement(HashTable* ht, int key) {
    int attempt = 0;
    int index;
    
    do {
        index = hashFunction(key, attempt);
        
        if (ht->table[index].count < SIZE) {
            // Inserir na fila estática se houver espaço
            ht->table[index].elements[ht->table[index].count].key = key;
            ht->table[index].count++;
            return;
        } else {
            // Aplicar sondagem quadrática para encontrar novo índice
            attempt++;
        }
    } while (attempt < TABLE_SIZE); // Evitar loops infinitos
    
    // Tratar caso de tabela cheia
    printf("Tabela de hash cheia, não foi possível inserir elemento.\n");
}

void printHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Índice %d:", i);
        for (int j = 0; j < ht->table[i].count; j++) {
            printf(" %d", ht->table[i].elements[j].key);
        }
        printf("\n");
    }
}

int main() {
    HashTable ht;

    // Inicialização da tabela de hash
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht.table[i].count = 0; // Inicializa contadores das filas estáticas
    }
    insertElement(&ht, 10);
    insertElement(&ht, 20);
    insertElement(&ht, 30);
    insertElement(&ht, 5);
    insertElement(&ht, 15);
    insertElement(&ht, 25);
    insertElement(&ht, 35);
    insertElement(&ht, 40);
    insertElement(&ht, 50);
    printHashTable(&ht);

    return 0;
}
