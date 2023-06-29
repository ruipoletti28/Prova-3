#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para utilizar INT_MIN e INT_MAX

void inserir(int numero);
void inicializar();
int verificarVazia();
void imprimir();
int remover();
int encontrarMenor();
int encontrarMaior();

typedef struct no {
    int dado;
    struct no* proximo;
} No;

typedef struct fila {
    No* inicio, * final;
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

void inserir(int numero) {
    // Aloca memória para um novo nó da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado memória, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Guarda o número a inserir na fila na variável dado do novoNo
        novoNo->dado = numero;
        // O novoNo será o último elemento da fila, logo não tem próximo
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
        // Senão informa o usuário que não há mais memória
        printf("\nNão é possível adicionar na fila pois não há mais memória disponível.");
    }
}

void imprimir() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Declara uma variável ponteiro auxiliar para percorrer os nós da fila
        No* aux;
        printf("\nOs elementos na fila são: ");
        // Começa a percorrer a fila do início
        aux = f.inicio;
        // Enquanto não chegar ao fim
        while (aux != NULL) {
            // Imprimir o dado do nó apontado por aux
            printf(" %d", aux->dado);
            // Vai para o próximo nó
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

int remover() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Cria variável que vai apontar para o nó a ser removido
        No* aux;
        // Cria variável para guardar o dado do nó a ser removido
        int dado;
        // Aux aponta para o nó do início da fila
        aux = f.inicio;
        // Dado irá guardar o elemento do início da fila
        dado = aux->dado;
        // Atualizar o início da fila
        f.inicio = aux->proximo;
        // Se o nó removido for o nó final da fila, atualiza o final da fila
        if (f.final == aux)
            f.final = NULL;
        // Libera a memória ocupada pelo nó removido
        free(aux);
        // Retorna o valor do nó removido
        return dado;
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("A fila está vazia.");
        return INT_MIN; // Retorna um valor inválido para indicar que não há elementos na fila
    }
}

int encontrarMenor() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Declara uma variável ponteiro auxiliar para percorrer os nós da fila
        No* aux;
        // Inicializa o menor com o maior valor possível
        int menor = INT_MAX;
        // Começa a percorrer a fila do início
        aux = f.inicio;
        // Enquanto não chegar ao fim
        while (aux != NULL) {
            // Se o dado do nó atual for menor que o menor atual, atualiza o menor
            if (aux->dado < menor) {
                menor = aux->dado;
            }
            // Vai para o próximo nó
            aux = aux->proximo;
        }
        // Retorna o menor encontrado
        return menor;
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("A fila está vazia.");
        return INT_MIN; // Retorna um valor inválido para indicar que não há elementos na fila
    }
}

int encontrarMaior() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Declara uma variável ponteiro auxiliar para percorrer os nós da fila
        No* aux;
        // Inicializa o maior com o menor valor possível
        int maior = INT_MIN;
        // Começa a percorrer a fila do início
        aux = f.inicio;
        // Enquanto não chegar ao fim
        while (aux != NULL) {
            // Se o dado do nó atual for maior que o maior atual, atualiza o maior
            if (aux->dado > maior) {
                maior = aux->dado;
            }
            // Vai para o próximo nó
            aux = aux->proximo;
        }
        // Retorna o maior encontrado
        return maior;
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("A fila está vazia.");
        return INT_MIN; // Retorna um valor inválido para indicar que não há elementos na fila
    }
}

int main(int argc, char* argv[]) {
    int temp;
    int opcao;
    inicializar();

    do {
        // Exibir o menu
        printf("\n    MENU");
        printf("\n1. Inicializar");
        printf("\n2. Inserir");
        printf("\n3. Remover");
        printf("\n4. Imprimir");
        printf("\n5. Encontrar menor");
        printf("\n6. Encontrar maior");
        printf("\n7. Sair");
        printf("\nDigite a opcao desejada: ");

        // Ler a opção desejada pelo usuário
        scanf("%d", &opcao);

        // Processar a funcionalidade
        switch (opcao) {
            case 1:
                inicializar();
                break;
            case 2:
                printf("Digite o numero: ");
                scanf("%d", &temp);
                inserir(temp);
                break;
            case 3:
                temp = remover();
                if (temp != INT_MIN) {
                    printf("\nNumero removido: %d", temp);
                }
                break;
            case 4:
                imprimir();
                break;
            case 5:
                temp = encontrarMenor();
                if (temp != INT_MIN) {
                    printf("\nMenor numero: %d", temp);
                }
                break;
            case 6:
                temp = encontrarMaior();
                if (temp != INT_MIN) {
                    printf("\nMaior numero: %d", temp);
                }
                break;
            case 7:
                printf("Encerrando o programa...");
                break;
            default:
                printf("\nOpcao invalida. Escolha um numero valido de opcao.");
        }

    } while (opcao != 7);
}

