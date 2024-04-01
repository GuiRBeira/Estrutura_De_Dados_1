#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct simple_link simple_link;

struct simple_link{
    int age;
    char name[20];
    simple_link *next;
};

typedef struct double_link double_link;

struct double_link{
    int age;
    char nome[30];
    double_link *prev;
    double_link *next;
};

void encadeamento_simples(simple_link *a, simple_link *b, simple_link *c){
    a->next = b;
    b->next = c;
    c->next = a;
}

void encadeamento_duplo(double_link *a, double_link *b, double_link *c){
    a->next = b;
    b->next = c;
    c->next = NULL;
    a->prev = NULL;
    b->prev = a;
    c->prev = b;    
}

int main(){
    simple_link s1 = {11, "Pessoa 1", NULL};
    simple_link s2 = {22, "Pessoa 2", NULL};
    simple_link s3 = {33, "Pessoa 3", NULL};
    encadeamento_simples(&s1, &s2, &s3);
    printf("Encadeamento Simples\n");
    printf("1: s1.next: %p\n", s1.next);
    printf("2: s2.next: %p\n", s2.next);
    printf("3: s3.next: %p\n", s3.next);
    double_link p1 = {11, "Pessoa 1", NULL, NULL};
    double_link p2 = {22, "Pessoa 2", NULL, NULL};
    double_link p3 = {33, "Pessoa 3", NULL, NULL};
    encadeamento_duplo(&p1, &p2, &p3);
    printf("Encadeamento Duplo\n");
    printf("1: p1.next: %p\n", p1.next);
    printf("2: p2.next: %p\n", p2.next);
    printf("3: p3.next: %p\n", p3.next);
    printf("1: p1.prev: %p\n", p1.prev);
    printf("2: p2.prev: %p\n", p2.prev);
    printf("3: p3.prev: %p\n", p3.prev);
    return 0;
}