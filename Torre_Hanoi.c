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
    //por conta do metodo de insercao, a impressao sera feita ao contrario, para melhor visualizacao da torre
    if(Vazia(pilha))
    {
        printf("Vazia");
        return;
    }

    Cores elementos[3];
    int i = 0;

    for(No* ptr = pilha->topo; ptr != NULL; ptr = ptr->prox, i++)
    {
        elementos[i] = ptr->cor;
    }

    while(i > 0)
    {
        printf("%d ", elementos[i - 1]);
        i--;
    }
}

void ImprimirTorre(Pilha pilha[])
{
    printf("\n");
    for(int i = 0; i < 7; i++)
    {
        printf("| ");
        switch (i)
        {
            case 1:
                Imprimir(&pilha[0]);
                break;
            case 3:
                Imprimir(&pilha[1]);
                break;
            case 5:
                Imprimir(&pilha[2]);
                break;
        }
        printf("\n");
    }

    printf("\n");
}

void Menu(Pilha pilha[])
{
    int tamanho = pilha[0].qntd;
    int opcao1, opcao2;

    ImprimirTorre(pilha);

    do
    {
        printf("Digite a Torre de Origem: ");
        scanf("%d", &opcao1);
        printf("Digite a Torre de Destino: ");
        scanf("%d", &opcao2);

        TrocarPinos(&pilha[opcao1], &pilha[opcao2]);
        ImprimirTorre(pilha);

    } while (pilha[2].qntd != tamanho);

    printf("Desafio Solucionado!\n");
    
}

void Empilhar(Pilha *pilha, Cores disco)
{
    No* novo = malloc(sizeof(No));
    if(novo == NULL)
    {
        printf("Erro ao alocar na memoria!\n");
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

void TrocarPinos (Pilha* origem, Pilha* destino)
{
    Cores cor;
    Desempilhar(origem, &cor);
    if(!Vazia(destino) && cor > destino->topo->cor)
    {
        Empilhar(origem, cor);
        printf("Nao e possivel colocar um disco maior que o do topo!\n");
        return;
    }
    Empilhar(destino, cor);
}