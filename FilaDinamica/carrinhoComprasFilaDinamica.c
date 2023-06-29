#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    int quantidadeItens;
    double valorItens;
} CarrinhoCompra;

typedef struct No {
    CarrinhoCompra carrinho;
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

void enfileirar(Fila* fila, CarrinhoCompra novoCarrinho) {
    No* novoNo = (No*)malloc(sizeof(No));

    novoNo->carrinho = novoCarrinho;
    novoNo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

CarrinhoCompra desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        CarrinhoCompra carrinhoVazio = {0, 0, 0.0};
        printf("Fila vazia. Impossível desenfileirar.\n");
        return carrinhoVazio;
    }

    CarrinhoCompra carrinhoDesenfileirado = fila->inicio->carrinho;

    No* noRemovido = fila->inicio;

    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(noRemovido);

    return carrinhoDesenfileirado;
}

void imprimirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    No* atual = fila->inicio;

    printf("Carrinhos de compra na fila:\n");
    while (atual != NULL) {
        printf("Código: %d | Quantidade de itens: %d | Valor dos itens: %.2f\n",
               atual->carrinho.codigo, atual->carrinho.quantidadeItens, atual->carrinho.valorItens);
        atual = atual->proximo;
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    CarrinhoCompra carrinho;

    while (1) {
        printf("\n1 - Enfileirar carrinho de compra\n");
        printf("2 - Desenfileirar carrinho de compra\n");
        printf("3 - Imprimir fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o código do carrinho: ");
                scanf("%d", &carrinho.codigo);
                printf("Digite a quantidade de itens do carrinho: ");
                scanf("%d", &carrinho.quantidadeItens);
                printf("Digite o valor dos itens do carrinho: ");
                scanf("%lf", &carrinho.valorItens);
                enfileirar(&fila, carrinho);
                break;
            case 2:
                carrinho = desenfileirar(&fila);
                printf("Carrinho desenfileirado:\n");
                printf("Código: %d | Quantidade de itens: %d | Valor dos itens: %.2f\n",
                       carrinho.codigo, carrinho.quantidadeItens, carrinho.valorItens);
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
