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
        printf("%d", ptr->elemento);
        printf("\n");
    }
}

void Empilhar (Pilha *pilha, Cores disco)
{
    No* novo = malloc(sizeof(No));
    if(novo == NULL)
    {
        printf("Erro ao alocar na memoria!\n");
        return;
    }

    if(Vazia(pilha))
    {
        novo->elemento = disco;
        novo->prox = NULL;
        pilha->topo = novo;
        pilha->qntd++;
    }
    else
    {
        if(disco > pilha->topo->elemento)
        {
            printf("Nao e possivel colocar um disco maior que o do topo!\n");
            return;
        }
        else
        {
            novo->elemento = disco;
            novo->prox = NULL;
            pilha->qntd++;
            pilha->topo->prox = novo;
            pilha->topo = novo;
        }
    }
}