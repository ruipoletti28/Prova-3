#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    double valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

void enfileirar(Fila* fila, double novoNumero) {
    No* novoNo = (No*)malloc(sizeof(No));

    novoNo->valor = novoNumero;
    novoNo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

double desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia. Impossível desenfileirar.\n");
        return 0.0;
    }

    double valorDesenfileirado = fila->inicio->valor;

    No* noRemovido = fila->inicio;

    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(noRemovido);

    return valorDesenfileirado;
}

void imprimirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    No* atual = fila->inicio;

    printf("Elementos da fila: ");
    while (atual != NULL) {
        printf("%.2f ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    double numero;

    while (1) {
        printf("\n1 - Enfileirar número\n");
        printf("2 - Desenfileirar número\n");
        printf("3 - Imprimir fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número: ");
                scanf("%lf", &numero);
                enfileirar(&fila, numero);
                break;
            case 2:
                numero = desenfileirar(&fila);
                printf("Número desenfileirado: %.2f\n", numero);
                break;
            case 3:
                imprimirFila(&fila);
                break;
            case 4:
                while (!filaVazia(&fila)) {
                    desenfileirar(&fila);
                }
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
