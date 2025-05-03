#include <stdio.h>
#include "Torre_Hanoi.c"
#define MAX 3

int main() {
    
    Pilha pilha[MAX];

    InicializarPilha(&pilha[0]);
    InicializarPilha(&pilha[1]);
    InicializarPilha(&pilha[2]);

    Empilhar(&pilha[0], VERMELHO);
    Empilhar(&pilha[0], VERDE);
    Empilhar(&pilha[0], AZUL);

    Menu(pilha);

    return 0;
}