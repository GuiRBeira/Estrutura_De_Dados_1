#include <stdio.h>

#define MAX 100

struct aluno {
   int idade;
   char nome[30];
};

struct pilha_t {
   int qtd;
   struct aluno dados[MAX];
};

typedef struct pilha_t Pilha;

// adiciona elemento à pilha
int push(Pilha p, struct aluno al) {
    // se não pode adicionar retorna zero
    if (p == NULL || p->qtd >= MAX) {
        return 0;
    }

    // copia o dado para o array e atualiza qtd
    p->dados[p->qtd] = al;
    p->qtd++;
    return 1;
}

// lê elemento do topo da pilha
int top(Pilha p, struct aluno *al) {
    // se não pode ler retorna zero
    if (p == NULL  p->qtd <= 0) {
        return 0;
    }

    // copia o dado para a variável
    al = p->dados[p->qtd - 1];
    return 1;
}

// lê e remove o elemento do topo da pilha
int pop(Pilha p, struct aluno *al) {
    // se não pode ler retorna zero
    if (p == NULL  p->qtd <= 0) {
        return 0;
    }

    // copia o dado para a variável e atualiza qtd
    *al = p->dados[p->qtd - 1];
    p->qtd--;
    return 1;
}

int main() {
    // cria uma pilha estática
    Pilha minha_pilha;
    minha_pilha.qtd = 0;

    // cria uma struct do tipo aluno
    struct aluno a0 = {25, "ze"};

    // adiciona 3 elementos
    printf("Adicionando: %d\n", a0.idade);
    push(&minha_pilha, a0);
    a0.idade = 20;
    printf("Adicionando: %d\n", a0.idade);
    push(&minha_pilha, a0);
    a0.idade = 15;
    printf("Adicionando: %d\n", a0.idade);
    push(&minha_pilha, a0);

    // remove 3 elementos
    pop(&minha_pilha, &a0);
    printf("Removido: %d\n", a0.idade);
    pop(&minha_pilha, &a0);
    printf("Removido: %d\n", a0.idade);
    pop(&minha_pilha, &a0);
    printf("Removido: %d\n", a0.idade);

    return 0;
}