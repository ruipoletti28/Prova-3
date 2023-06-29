#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void inserir(char* string);
void inicializar();
int verificarVazia();
void imprimir();
char* remover();

typedef struct no {
    char dado[MAX_LENGTH];
    struct no* proximo;
} No;

typedef struct fila {
    No* inicio;
    No* final;
} Fila;

Fila f;

void inicializar() {
    f.inicio = NULL;
    f.final = NULL;
}

int verificarVazia() {
    if (f.inicio == NULL)
        return 1;
    else
        return 0;
}

void inserir(char* string) {
    // Aloca memória para um novo nó da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado memória, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Copia a string a ser inserida para o dado do novoNo
        strncpy(novoNo->dado, string, MAX_LENGTH);
        // Define o próximo do novoNo como NULL
        novoNo->proximo = NULL;
        // Se a fila estiver vazia, o novoNo será também o início da fila
        if (verificarVazia()) {
            f.inicio = novoNo;
        }
        else {
            // Se já tiver elementos na fila, adiciona o novoNo após o nó que está no final da fila
            f.final->proximo = novoNo;
        }
        // Atualiza o final da fila para que seja o novoNo
        f.final = novoNo;
    }
    else {
        // Informa o usuário que não há mais memória disponível
        printf("\nNão é possível adicionar na fila, pois não há mais memória disponível.");
    }
}

void imprimir() {
    // Verifica se a fila não está vazia
    if (!verificarVazia()) {
        // Declara uma variável ponteiro auxiliar para percorrer os nós da fila
        No* aux;
        printf("\nOs elementos na fila são:\n");
        // Começa a percorrer a fila do início
        aux = f.inicio;
        // Enquanto não chegar ao fim
        while (aux != NULL) {
            // Imprime a string do nó apontado por aux
            printf("%s\n", aux->dado);
            // Vai para o próximo nó
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

char* remover() {
    // Verifica se a fila não está vazia
    if (!verificarVazia()) {
        // Cria variável que vai apontar para o nó a ser removido
        No* aux;
        // Cria variável para guardar a string do nó a ser removido
        char* dado = malloc(MAX_LENGTH * sizeof(char));
        // Aux aponta para o nó do início da fila
        aux = f.inicio;
        // Copia a string do nó do início da fila para dado
        strncpy(dado, aux->dado, MAX_LENGTH);
        // Atualiza o início da fila
        f.inicio = aux->proximo;
        // Se o nó removido for o nó final da fila, atualiza o final da fila
        if (f.final == aux)
            f.final = NULL;
        // Libera a memória ocupada pelo nó removido
        free(aux);
        // Retorna a string do nó removido
        return dado;
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("A fila está vazia.");
        return NULL;
    }
}

int main(int argc, char* argv[]) {
    char temp[MAX_LENGTH];
    int opcao;
    inicializar();

    do {
        // Exibe o menu
        printf("\n    MENU");
        printf("\n1. Inicializar");
        printf("\n2. Inserir");
        printf("\n3. Remover");
        printf("\n4. Imprimir");
        printf("\n5. Sair");
        printf("\nDigite a opção desejada: ");

        // Lê a opção desejada pelo usuário
        scanf("%d", &opcao);

        // Processa a funcionalidade
        switch (opcao) {
        case 1:
            inicializar();
            break;
        case 2:
            printf("Digite a string: ");
            scanf("%s", temp);
            inserir(temp);
            break;
        case 3:
            printf("\nString removida: %s", remover());
            break;
        case 4:
            imprimir();
            break;
        case 5:
            printf("Encerrando o programa...");
            break;
        default:
            printf("\nOpção inválida. Escolha um número válido de opção.");
        }

    } while (opcao != 5);
}

