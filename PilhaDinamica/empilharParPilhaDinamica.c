#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int topo;
    int itens[MAX];
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

void empilhar(Pilha* pilha, int valor) {
    if (pilhaCheia(pilha)) {
        printf("Pilha cheia. Impossível empilhar.\n");
        return;
    }

    if (valor % 2 == 0) {
        pilha->topo++;
        pilha->itens[pilha->topo] = valor;
    } else {
        printf("Número ímpar. Não pode ser empilhado.\n");
    }
}

int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia. Impossível desempilhar.\n");
        return -1;
    }

    int valorDesempilhado = pilha->itens[pilha->topo];
    pilha->topo--;

    return valorDesempilhado;
}

void imprimirPilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Elementos da pilha:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d\n", pilha->itens[i]);
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao;
    int valor;

    while (1) {
        printf("\n1 - Empilhar número par\n");
        printf("2 - Desempilhar número\n");
        printf("3 - Imprimir pilha\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número: ");
                scanf("%d", &valor);
                empilhar(&pilha, valor);
                break;
            case 2:
                valor = desempilhar(&pilha);
                if (valor != -1) {
                    printf("Número desempilhado: %d\n", valor);
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
