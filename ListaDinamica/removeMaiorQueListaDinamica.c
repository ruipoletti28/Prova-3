#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Função para inserir um número na lista
void inserirNumero(No** lista, int novoNumero) {
    // Aloca memória para o novo nó
    No* novoNo = (No*) malloc(sizeof(No));

    // Define o valor do novo nó
    novoNo->valor = novoNumero;

    // O próximo nó do novo nó será o nó atual do início da lista
    novoNo->proximo = *lista;

    // O início da lista será o novo nó
    *lista = novoNo;
}

// Função para imprimir a lista
void imprimirLista(No* lista) {
    No* atual = lista;

    printf("Lista: ");

    // Percorre a lista e imprime os números
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

// Função para remover números maiores que um valor fornecido
void removerMaiores(No** lista, int valorLimite) {
    No* atual = *lista;
    No* anterior = NULL;

    // Percorre a lista
    while (atual != NULL) {
        // Verifica se o número é maior que o valor limite
        if (atual->valor > valorLimite) {
            // Verifica se o nó a ser removido é o primeiro da lista
            if (anterior == NULL) {
                *lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            No* noRemovido = atual;
            atual = atual->proximo;
            free(noRemovido);
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

// Função principal
int main() {
    No* lista = NULL; // Inicializa a lista como vazia

    int opcao, numero, valorLimite;

    while (1) {
        printf("\n1 - Inserir número\n");
        printf("2 - Imprimir lista\n");
        printf("3 - Remover números maiores que um valor\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número: ");
                scanf("%d", &numero);
                inserirNumero(&lista, numero);
                break;
            case 2:
                imprimirLista(lista);
                break;
            case 3:
                printf("Digite o valor limite: ");
                scanf("%d", &valorLimite);
                removerMaiores(&lista, valorLimite);
                printf("Números maiores que %d removidos.\n", valorLimite);
                break;
            case 4:
                // Libera a memória ocupada pela lista
                while (lista != NULL) {
                    No* noRemovido = lista;
                    lista = lista->proximo;
                    free(noRemovido);
                }
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
