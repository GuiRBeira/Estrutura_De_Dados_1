#include <stdio.h>
#include <stdbool.h>
#define N_MAX 5

typedef struct{
    char name[16];
    double price;
} Product;

typedef struct{
    Product array[N_MAX];
    int start;
    int end;
    int size;
} ProductList;

bool append(Product p, ProductList *pl){
    if(pl->size >= N_MAX){
        printf("Fila cheia.");
        return false;
    }
    pl->array[pl->end] = p;
    pl->end = (pl->end + 1) % N_MAX;
    pl->size++;
    return true;
}

void show_queue(ProductList *pl){
    printf("\nFila:\n");
    Product prod;
    int j = 0;
    for(int i = pl->start; j <pl->size; i = (i+1)%N_MAX){
        prod = pl->array[i];
        printf("\nproduto: %s\nR$: %.2f", prod.name, prod.price);
        j++;
    }
}

bool removeprod(Product *p, ProductList *pl){
    if(pl->size == 0){
        printf("Fila vazia.");
        return false;
    }
    *p = pl->array[pl->start];
    pl->start = (pl->start + 1) % N_MAX;
    pl->size--;
    return true;
}

int main(){
    ProductList prods;
    prods.start = 0;
    prods.end = 0;
    prods.size = 0;
    Product p1 = {"Esponja", 1.50};
    Product p2 = {"Escova", 4.50};
    append(p1, &prods);
    append(p2, &prods);
    show_queue(&prods);
    removeprod(&p1, &prods);
    show_queue(&prods);
    removeprod(&p2, &prods);
    show_queue(&prods);
    return 0;
}