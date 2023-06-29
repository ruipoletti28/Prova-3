#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    struct no* proximo;
    struct no* anterior;
    struct item* item;
} No;

typedef struct {
    char nome[51];
    int quantidade;
    float valor;
} Item;

typedef struct {
    No* inicio;
} Lista;

void inicializar(Lista* lista) {
    lista->inicio = NULL;
}

int verificarVazia(Lista* lista) {
    return (lista->inicio == NULL);
}

void inserir(Lista* lista, Item item, int posicao) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->item = (Item*)malloc(sizeof(Item));
    *novoNo->item = item;

    if (verificarVazia(lista) || posicao == 1) {
        novoNo->proximo = lista->inicio;
        if (lista->inicio != NULL) {
            lista->inicio->anterior = novoNo;
        }
        lista->inicio = novoNo;
        novoNo->anterior = NULL;
    } else {
        No* auxiliar = lista->inicio;
        int posicaoAtual = 1;

        while (posicaoAtual < posicao - 1 && auxiliar->proximo != NULL) {
            auxiliar = auxiliar->proximo;
            posicaoAtual++;
        }

        novoNo->proximo = auxiliar->proximo;
        if (auxiliar->proximo != NULL) {
            auxiliar->proximo->anterior = novoNo;
        }
        auxiliar->proximo = novoNo;
        novoNo->anterior = auxiliar;
    }
}

void remover(Lista* lista, int posicao) {
    if (verificarVazia(lista)) {
        printf("\nA lista esta vazia. Nao ha itens para remover.");
        return;
    }

    No* auxiliar = lista->inicio;
    int posicaoAtual = 1;

    while (posicaoAtual < posicao && auxiliar != NULL) {
        auxiliar = auxiliar->proximo;
        posicaoAtual++;
    }

    if (auxiliar != NULL) {
        if (auxiliar->anterior != NULL) {
            auxiliar->anterior->proximo = auxiliar->proximo;
        } else {
            lista->inicio = auxiliar->proximo;
        }

        if (auxiliar->proximo != NULL) {
            auxiliar->proximo->anterior = auxiliar->anterior;
        }

        free(auxiliar->item);
        free(auxiliar);

        printf("\nItem removido com sucesso da posicao %d.", posicao);
    } else {
        printf("\nPosicao invalida.");
    }
}

void imprimir(Lista* lista) {
    if (verificarVazia(lista)) {
        printf("\nA lista esta vazia. Nao ha itens para exibir.");
        return;
    }

    No* auxiliar = lista->inicio;
    int posicao = 1;

    printf("\nItens da lista:\n");

    while (auxiliar != NULL) {
        printf("Posicao: %d\n", posicao);
        printf("Nome: %s\n", auxiliar->item->nome);
        printf("Quantidade: %d\n", auxiliar->item->quantidade);
        printf("Valor: %.2f\n", auxiliar->item->valor);
        printf("---------------------------\n");

        auxiliar = auxiliar->proximo;
        posicao++;
    }
}

void inserirValor(Lista* lista, float valor, int posicao) {
    if (verificarVazia(lista)) {
        printf("\nA lista esta vazia. Nao ha itens para atribuir valor.");
        return;
    }

    No* auxiliar = lista->inicio;
    int posicaoAtual = 1;

    while (posicaoAtual < posicao && auxiliar != NULL) {
        auxiliar = auxiliar->proximo;
        posicaoAtual++;
    }

    if (auxiliar != NULL) {
        auxiliar->item->valor = valor;
        printf("\nValor %.2f atribuido ao item da posicao %d.", valor, posicao);
    } else {
        printf("\nPosicao invalida.");
    }
}

void exibirMaiorValor(Lista* lista) {
    if (verificarVazia(lista)) {
        printf("\nA lista esta vazia. Nao ha itens para exibir o maior valor.");
        return;
    }

    No* auxiliar = lista->inicio;
    float maiorValor = auxiliar->item->valor;

    while (auxiliar != NULL) {
        if (auxiliar->item->valor > maiorValor) {
            maiorValor = auxiliar->item->valor;
        }
        auxiliar = auxiliar->proximo;
    }

    printf("\nO maior valor da lista: %.2f", maiorValor);
}

void exibirMenorValor(Lista* lista) {
    if (verificarVazia(lista)) {
        printf("\nA lista esta vazia. Nao ha itens para exibir o menor valor.");
        return;
    }

    No* auxiliar = lista->inicio;
    float menorValor = auxiliar->item->valor;

    while (auxiliar != NULL) {
        if (auxiliar->item->valor < menorValor) {
            menorValor = auxiliar->item->valor;
        }
        auxiliar = auxiliar->proximo;
    }

    printf("\nO menor valor da lista: %.2f", menorValor);
}

int main() {
    Lista lista;
    inicializar(&lista);

    int opcao;
    Item item;
    int posicao;

    do {
        printf("\n\n MENU");
        printf("\n1. Inicializar lista");
        printf("\n2. Inserir item");
        printf("\n3. Remover item");
        printf("\n4. Exibir itens");
        printf("\n5. Inserir valor a um item");
        printf("\n6. Exibir maior valor");
        printf("\n7. Exibir menor valor");
        printf("\n8. Sair");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                inicializar(&lista);
                printf("\nLista inicializada com sucesso.");
                break;
            }
            case 2: {
                printf("\nDigite o nome do item: ");
                getchar();  // Limpa o buffer do teclado
                fgets(item.nome, 51, stdin);
                item.nome[strcspn(item.nome, "\n")] = '\0';  // Remove o caractere de nova linha (\n) lido pelo fgets
                printf("Digite a quantidade do item: ");
                scanf("%d", &item.quantidade);
                printf("Digite o valor do item: ");
                scanf("%f", &item.valor);
                printf("Digite a posicao para inserir o item: ");
                scanf("%d", &posicao);
                inserir(&lista, item, posicao);
                break;
            }
            case 3: {
                printf("\nDigite a posicao para remover o item: ");
                scanf("%d", &posicao);
                remover(&lista, posicao);
                break;
            }
            case 4: {
                imprimir(&lista);
                break;
            }
            case 5: {
                float valor;
                printf("\nDigite o valor a ser atribuido: ");
                scanf("%f", &valor);
                printf("Digite a posicao do item: ");
                scanf("%d", &posicao);
                inserirValor(&lista, valor, posicao);
                break;
            }
            case 6: {
                exibirMaiorValor(&lista);
                break;
            }
            case 7: {
                exibirMenorValor(&lista);
                break;
            }
            case 8: {
                printf("\nEncerrando o programa...");
                break;
            }
            default: {
                printf("\nOpcao invalida. Digite um numero de 1 a 8.");
            }
        }
    } while (opcao != 8);

    return 0;
}

