#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct No {
    int numero;
    struct No* proximo;
} No;

// Função para inserir um número na lista
void inserirNumero(No** lista, int novoNumero) {
    // Aloca memória para o novo nó
    No* novoNo = (No*) malloc(sizeof(No));

    // Atribui o valor do novo número ao nó
    novoNo->numero = novoNumero;

    // O próximo nó do novo nó será o nó atual do início da lista
    novoNo->proximo = *lista;

    // O início da lista será o novo nó
    *lista = novoNo;
}

// Função para imprimir a lista
void imprimirLista(No* lista) {
    No* atual = lista;

    printf("Lista:\n");

    // Percorre a lista e imprime os números
    while (atual != NULL) {
        printf("%d ", atual->numero);
        atual = atual->proximo;
    }

    printf("\n");
}

// Função para retornar o primeiro par de números
int primeiroPar(No* lista) {
    while (lista != NULL) {
        if (lista->numero % 2 == 0) {
            return lista->numero;
        }
        lista = lista->proximo;
    }

    return -1; // Retorna -1 se não encontrar nenhum número par na lista
}

// Função principal
int main() {
    No* lista = NULL; // Inicializa a lista como vazia

    int opcao, numero;

    do {
        printf("\nMenu:\n");
        printf("1 - Inserir número\n");
        printf("2 - Imprimir lista\n");
        printf("3 - Retornar primeiro par\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número a ser inserido: ");
                scanf("%d", &numero);
                inserirNumero(&lista, numero);
                break;
            case 2:
                imprimirLista(lista);
                break;
            case 3:
                if (lista != NULL) {
                    int primeiroParNumero = primeiroPar(lista);
                    if (primeiroParNumero != -1) {
                        printf("O primeiro número par da lista é: %d\n", primeiroParNumero);
                    } else {
                        printf("Não há números pares na lista.\n");
                    }
                } else {
                    printf("A lista está vazia.\n");
                }
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    // Libera a memória ocupada pela lista
    while (lista != NULL) {
        No* noRemovido = lista;
        lista = lista->proximo;
        free(noRemovido);
    }

    return 0;
}
