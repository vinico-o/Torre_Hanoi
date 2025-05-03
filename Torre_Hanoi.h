#include <stdio.h>
#include <stdbool.h>

typedef enum Cores
{
    AZUL,
    VERDE,
    VERMELHO
} Cores;

typedef struct No
{
    Cores cor;
    struct No* prox;
}No;

typedef struct
{
    No *topo;
    int qntd;
}Pilha;

void InicializarPilha(Pilha *pilha);
bool Vazia(Pilha *pilha);
void Imprimir(Pilha *pilha);
void ImprimirTorre(Pilha pilha[]);
void Menu(Pilha pilha[]);
void Empilhar(Pilha *pilha, Cores disco);
void Desempilhar(Pilha *pilha, Cores* cor);
void TrocarPinos (Pilha* origem, Pilha* destino);