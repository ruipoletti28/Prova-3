#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da fila
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Definição da estrutura da fila
typedef struct {
    No* inicio;
    No* fim;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

// Função para enfileirar um número
void enfileirar(Fila* fila, int novoNumero) {
    // Aloca memória para o novo nó
    No* novoNo = (No*) malloc(sizeof(No));

    // Define o valor do novo nó
    novoNo->valor = novoNumero;
    novoNo->proximo = NULL;

    // Se a fila estiver vazia, o novo nó será tanto o início quanto o fim da fila
    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        // O novo nó será o próximo do nó atual do fim da fila
        fila->fim->proximo = novoNo;
        // O novo nó passa a ser o novo fim da fila
        fila->fim = novoNo;
    }
}

// Função para desenfileirar um número
int desenfileirar(Fila* fila) {
    // Verifica se a fila está vazia
    if (filaVazia(fila)) {
        printf("Fila vazia. Impossível desenfileirar.\n");
        return -1; // Retorna um valor inválido
    }

    // Obtém o valor do nó do início da fila
    int valorDesenfileirado = fila->inicio->valor;

    // Armazena o nó atual do início da fila para liberar a memória posteriormente
    No* noRemovido = fila->inicio;

    // Move o início da fila para o próximo nó
    fila->inicio = fila->inicio->proximo;

    // Verifica se o nó removido era o único nó da fila
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    // Libera a memória ocupada pelo nó removido
    free(noRemovido);

    // Retorna o valor desenfileirado
    return valorDesenfileirado;
}

// Função para calcular a soma dos números na fila
int calcularSoma(Fila* fila) {
    No* atual = fila->inicio;
    int soma = 0;

    // Percorre a fila e acumula a soma dos números
    while (atual != NULL) {
        soma += atual->valor;
        atual = atual->proximo;
    }

    return soma;
}

// Função principal
int main() {
    Fila fila;
    inicializarFila(&fila); // Inicializa a fila

    int opcao, numero;

    while (1) {
        printf("\n1 - Enfileirar número\n");
        printf("2 - Desenfileirar número\n");
        printf("3 - Calcular soma dos números\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número: ");
                scanf("%d", &numero);
                enfileirar(&fila, numero);
                break;
            case 2:
                numero = desenfileirar(&fila);
                if (numero != -1) {
                    printf("Número desenfileirado: %d\n", numero);
                }
                break;
            case 3:
                printf("Soma dos números: %d\n", calcularSoma(&fila));
                break;
            case 4:
                // Libera a memória ocupada pela fila
                while (!filaVazia(&fila)) {
                    desenfileirar(&fila);
                }
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
