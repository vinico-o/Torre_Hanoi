#include "Torre_Hanoi.h"
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