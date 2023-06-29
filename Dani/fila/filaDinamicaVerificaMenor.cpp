#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Biblioteca necessária para usar a constante INT_MAX

void inserir(int numero);
void inicializar();
int verificarVazia();
void imprimir();
int remover();
int encontrarMenor(); // Nova função adicionada

typedef struct no {
    int dado;
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

void inserir(int numero) {
    // Aloca memória para um novo nó da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado memória, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Guarda o número a inserir na fila no campo dado do novoNo
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
        // Senão, informa o usuário que não há mais memória disponível
        printf("\nNão é possível adicionar na fila, pois não há mais memória disponível.");
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
        // Enquanto não chegar no fim
        while (aux != NULL) {
            // Imprimir o dado do nó apontado por aux
            printf("%d ", aux->dado);
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
        // aux aponta para o nó do início da fila
        aux = f.inicio;
        // dado irá guardar o elemento do início da fila
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
        // Retorna um valor inválido para indicar que não foi possível remover
        return INT_MIN;
    }
}

int encontrarMenor() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Inicializa a variável menor com o maior valor possível
        int menor = INT_MAX;
        // Declara uma variável ponteiro auxiliar para percorrer os nós da fila
        No* aux;
        // Começa a percorrer a fila do início
        aux = f.inicio;
        // Enquanto não chegar ao fim
        while (aux != NULL) {
            // Verifica se o dado do nó atual é menor que o valor atualmente armazenado em menor
            if (aux->dado < menor) {
                // Atualiza o valor de menor
                menor = aux->dado;
            }
            // Vai para o próximo nó
            aux = aux->proximo;
        }
        // Retorna o menor número encontrado
        return menor;
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("A fila está vazia.");
        // Retorna um valor inválido para indicar que não foi possível encontrar o menor número
        return INT_MIN;
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
        printf("\n5. Encontrar menor número");
        printf("\n6. Sair");
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
            if (temp != INT_MIN)
                printf("\nNúmero removido: %d", temp);
            break;
        case 4:
            imprimir();
            break;
        case 5:
            temp = encontrarMenor();
            if (temp != INT_MIN)
                printf("\nMenor número encontrado na fila: %d", temp);
            break;
        case 6:
            printf("Encerrando o programa...");
            break;
        default:
            printf("\nOpção inválida. Escolha um número válido de opção.");
        }

    } while (opcao != 6);
}

