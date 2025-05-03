#include "Torre_Hanoi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void InicializarPilha(Pilha *pilha)
{
    pilha->topo = NULL;
    pilha->qntd = 0;
}

bool Vazia(Pilha *pilha)
{
    if(pilha->qntd == 0)
    {
        return true;
    }

    return false;
}

void Imprimir(Pilha *pilha)
{
    for(No* ptr = pilha->topo; ptr != NULL; ptr = ptr->prox)
    {
        printf("%d", ptr->cor);
        printf("\n");
    }

    printf("\n");
}

void Empilhar (Pilha *pilha, Cores disco)
{
    No* novo = malloc(sizeof(No));
    if(novo == NULL)
    {
        printf("Erro ao alocar na memoria!\n");
        return;
    }

    if(!Vazia(pilha) && disco > pilha->topo->cor)
    {
        printf("Nao e possivel colocar um disco maior que o do topo!\n");
        free(novo);
        return;
    }
    
    novo->cor = disco;
    novo->prox = pilha->topo;
    pilha->qntd++;
    pilha->topo = novo;   
    
}

void Desempilhar(Pilha *pilha, Cores* cor)
{
    No* temp;
    temp = pilha->topo;

    if(Vazia(pilha))
    {
        printf("Impossivel de desempilhar pilha Vazia!\n");
        return;
    }

    *cor = pilha->topo->cor;
    pilha->topo = pilha->topo->prox;
    temp->prox = NULL;
    free(temp);
    pilha->qntd--;

    return;
}