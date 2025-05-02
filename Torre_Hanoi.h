#include <stdio.h>

typedef struct
{
    int elemento;
    struct No* prox;
}No;

typedef struct
{
    No *topo;
    int qntd;
}Pilha;