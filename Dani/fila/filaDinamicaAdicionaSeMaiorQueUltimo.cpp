#include <stdio.h>
#include <stdlib.h>

void inserir(int numero);
void inicializar();
int verificarVazia();
void imprimir();
int remover();

typedef struct no {
    int dado;
    struct no* proximo;
} No;

typedef struct fila {
    No* inicio, * final;
} Fila;

Fila f;
int ultimoElemento = 0; // Variável para armazenar o último elemento inserido

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
    if (numero > ultimoElemento) {
        // Aloca memória para um novo nó da fila
        No* novoNo = (No*)malloc((sizeof(No)));
        // Se foi alocada memória, adiciona o novo nó no fim da fila
        if (novoNo != NULL) {
            // Guarda o número a ser inserido na variável dado do novo nó
            novoNo->dado = numero;
            // O novo nó será o último elemento da fila, logo não tem próximo
            novoNo->proximo = NULL;
            // Se a fila estiver vazia, o novo nó será também o início da fila
            if (verificarVazia()) {
                f.inicio = novoNo;
            } else {
                // Se já tiver elementos na fila, adiciona o novo nó após o nó que está no final da fila
                f.final->proximo = novoNo;
            }
            // Atualiza o final da fila para que seja o novo nó
            f.final = novoNo;
            // Atualiza o último elemento inserido
            ultimoElemento = numero;
        } else {
            // Informa o usuário que não há mais memória
            printf("\nNão é possível adicionar na fila pois não há mais memória disponível.");
        }
    } else {
        // Informa o usuário que o número não é maior que o último elemento inserido
        printf("\nO número inserido não é maior que o último elemento.");
    }
}

void imprimir() {
    // Verifica se a fila não está vazia
    if (!verificarVazia()) {
        // Declara um ponteiro auxiliar para percorrer os nós da fila
        No* aux;
        printf("\nOs elementos na fila são: ");
        // Começa a percorrer a fila do início
        aux = f.inicio;
        // Enquanto não chegar ao fim
        while (aux != NULL) {
            // Imprime o dado do nó apontado por aux
            printf(" %d", aux->dado);
            // Vai para o próximo nó
            aux = aux->proximo;
        }
    } else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

int remover() {
    // Verifica se a fila não está vazia
    if (!verificarVazia()) {
        // Cria uma variável que vai apontar para o nó a ser removido
        No* aux;
        // Cria uma variável para guardar o dado do nó a ser removido
        int dado;
        // Aux aponta para o nó do início da fila
        aux = f.inicio;
        // O dado irá guardar o elemento do início da fila
        dado = aux->dado;
        // Atualiza o início da fila
        f.inicio = aux->proximo;
        // Se o nó removido for o nó final da fila, atualiza o final da fila
        if (f.final == aux)
            f.final = NULL;
        // Libera a memória ocupada pelo nó removido
        free(aux);
        // Retorna o valor do nó removido
        return dado;
    } else {
        // Informa o usuário que a fila está vazia
        printf("A fila está vazia.");
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
        printf("\n5. Sair");
        printf("\nDigite a opção desejada: ");

        // Ler a opção desejada pelo usuário
        scanf("%d", &opcao);

        // Processar a funcionalidade
        switch (opcao) {
            case 1:
                inicializar();
                break;
            case 2:
                printf("Digite o número: ");
                scanf("%d", &temp);
                inserir(temp);
                break;
            case 3:
                temp = remover();
                printf("\nNúmero removido: %d", temp);
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

