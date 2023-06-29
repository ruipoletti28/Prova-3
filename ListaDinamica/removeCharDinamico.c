#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct No {
    char caractere;
    struct No* proximo;
} No;

// Função para inserir um caractere no início da lista
void inserirCaractere(No** lista, char caractere) {
    // Aloca memória para o novo nó
    No* novoNo = (No*) malloc(sizeof(No));

    // Define o valor do caractere
    novoNo->caractere = caractere;

    // O próximo nó do novo nó será o nó atual do início da lista
    novoNo->proximo = *lista;

    // O início da lista será o novo nó
    *lista = novoNo;
}

// Função para imprimir os caracteres da lista
void imprimirLista(No* lista) {
    No* atual = lista;

    printf("Lista de Caracteres: ");

    // Percorre a lista e imprime os caracteres
    while (atual != NULL) {
        printf("%c ", atual->caractere);
        atual = atual->proximo;
    }

    printf("\n");
}

// Função para remover o primeiro caractere da lista
void removerCaractere(No** lista) {
    if (*lista == NULL) {
        printf("A lista está vazia. Não é possível remover.\n");
        return;
    }

    No* noRemovido = *lista;
    *lista = (*lista)->proximo;

    // Libera a memória do nó removido
    free(noRemovido);
}

// Função principal
int main() {
    No* lista = NULL; // Inicializa a lista como vazia

    // Inserção de caracteres na lista
    inserirCaractere(&lista, 'A');
    inserirCaractere(&lista, 'B');
    inserirCaractere(&lista, 'C');

    // Impressão da lista
    imprimirLista(lista);

    // Remoção de caracteres da lista
    removerCaractere(&lista);
    removerCaractere(&lista);

    // Impressão da lista após remoção
    imprimirLista(lista);

    // Libera a memória ocupada pela lista
    while (lista != NULL) {
        removerCaractere(&lista);
    }

    return 0;
}
