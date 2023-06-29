#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    int identificador;
    char setorOrigem[50];
    float peso;
} Caixa;

typedef struct {
    int topo;
    Caixa itens[MAX];
} Pilha;

void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

int pilhaVazia(Pilha* pilha) {
    return (pilha->topo == -1);
}

int pilhaCheia(Pilha* pilha) {
    return (pilha->topo == MAX - 1);
}

void empilhar(Pilha* pilha, Caixa caixa) {
    if (pilhaCheia(pilha)) {
        printf("Pilha cheia. Impossível empilhar.\n");
        return;
    }

    pilha->topo++;
    pilha->itens[pilha->topo] = caixa;
}

Caixa desempilhar(Pilha* pilha) {
    Caixa caixaVazia = {-1, "", 0.0};

    if (pilhaVazia(pilha)) {
        printf("Pilha vazia. Impossível desempilhar.\n");
        return caixaVazia;
    }

    Caixa caixaDesempilhada = pilha->itens[pilha->topo];
    pilha->topo--;

    return caixaDesempilhada;
}

void imprimirPilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Elementos da pilha:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        Caixa caixa = pilha->itens[i];
        printf("Identificador: %d, Setor de origem: %s, Peso: %.2f\n", caixa.identificador, caixa.setorOrigem, caixa.peso);
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao;
    Caixa caixa;

    while (1) {
        printf("\n1 - Empilhar caixa\n");
        printf("2 - Desempilhar caixa\n");
        printf("3 - Imprimir pilha\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador da caixa: ");
                scanf("%d", &caixa.identificador);
                printf("Digite o setor de origem da caixa: ");
                scanf("%s", caixa.setorOrigem);
                printf("Digite o peso da caixa: ");
                scanf("%f", &caixa.peso);
                empilhar(&pilha, caixa);
                break;
            case 2:
                caixa = desempilhar(&pilha);
                if (caixa.identificador != -1) {
                    printf("Caixa desempilhada: Identificador: %d, Setor de origem: %s, Peso: %.2f\n", caixa.identificador, caixa.setorOrigem, caixa.peso);
                }
                break;
            case 3:
                imprimirPilha(&pilha);
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
