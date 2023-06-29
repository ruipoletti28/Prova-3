#include <stdio.h>
#include <stdlib.h>

void inserir(int numero);
void inicializar();
int verificarVazia();
void imprimir();
int remover();
void encontrarMenor();
void encontrarMaior();
void encontrarPares();

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
    No* novoNo = (No*)malloc((sizeof(No)));
    // Se foi alocada memória, adiciona o novoNo no fim da fila
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
        // Enquanto não chegar no fim
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
        return INT_MIN; // Retorna o menor valor possível para indicar que a fila está vazia
    }
}

void encontrarMenor() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Declara uma variável para armazenar o menor valor encontrado
        int menor = f.inicio->dado;
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio->proximo;
        // Percorre a fila a partir do segundo nó
        while (aux != NULL) {
            // Se o dado do nó atual for menor que o menor valor encontrado até agora
            if (aux->dado < menor) {
                // Atualiza o menor valor
                menor = aux->dado;
            }
            // Vai para o próximo nó
            aux = aux->proximo;
        }
        // Imprime o menor valor encontrado
        printf("\nMenor número: %d", menor);
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

void encontrarMaior() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Declara uma variável para armazenar o maior valor encontrado
        int maior = f.inicio->dado;
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio->proximo;
        // Percorre a fila a partir do segundo nó
        while (aux != NULL) {
            // Se o dado do nó atual for maior que o maior valor encontrado até agora
            if (aux->dado > maior) {
                // Atualiza o maior valor
                maior = aux->dado;
            }
            // Vai para o próximo nó
            aux = aux->proximo;
        }
        // Imprime o maior valor encontrado
        printf("\nMaior número: %d", maior);
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

void encontrarPares() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio;
        printf("\nNúmeros pares na fila: ");
        // Percorre a fila
        while (aux != NULL) {
            // Se o dado do nó atual for par
            if (aux->dado % 2 == 0) {
                // Imprime o número par
                printf("%d ", aux->dado);
            }
            // Vai para o próximo nó
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
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
        printf("\n5. Encontrar Menor");
        printf("\n6. Encontrar Maior");
        printf("\n7. Encontrar Pares");
        printf("\n8. Sair");
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
            encontrarMenor();
            break;
        case 6:
            encontrarMaior();
            break;
        case 7:
            encontrarPares();
            break;
        case 8:
            printf("Encerrando o programa...");
            break;
        default:
            printf("\nOpção inválida. Escolha um número válido de opção.");
        }

    } while (opcao != 8);
}

