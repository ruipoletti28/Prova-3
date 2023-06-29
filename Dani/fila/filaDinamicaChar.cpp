#include <stdio.h>
#include <stdlib.h>

void inserir(char caractere);
void inicializar();
int verificarVazia();
void imprimir();
char remover();

typedef struct no {
    char dado;
    struct no *proximo;
} No;

typedef struct fila {
    No *inicio, *final;
} Fila;

Fila f;

void inicializar(){
    f.inicio = NULL;
    f.final = NULL;
}

int verificarVazia(){
    if(f.inicio == NULL)
        return 1;
    else return 0;
}

void inserir(char caractere){
    // Aloca memória para um novo nó da fila
    No *novoNo = (No*) malloc(sizeof(No));
    // Se foi alocado memória, adiciona o novoNo no fim da fila
    if(novoNo != NULL) {
        // Guarda o caractere a inserir na fila na variável dado do novoNo
        novoNo->dado = caractere;
        // O novoNo será o último elemento da fila, logo não tem próximo
        novoNo->proximo = NULL;
        // Se a fila estiver vazia, o novoNo será também o início da fila
        if(verificarVazia()) {
            f.inicio = novoNo;
        } else {
            // Se já tiver elementos na fila, adiciona o novoNo após o nó que está no final da fila
            f.final->proximo = novoNo;
        }
        // Atualiza o final da fila para que seja o novoNo
        f.final = novoNo;
    } else {
        // Senão informa o usuário que não há mais memória
        printf("\nNão é possível adicionar na fila, pois não há mais memória disponível.");
    }
}

void imprimir(){
    // Verifica se a fila não está vazia
    if(!verificarVazia()) {
        // Declara uma variável ponteiro auxiliar para percorrer os nós da fila
        No *aux;
        printf("\nOs elementos na fila são: ");
        // Começa a percorrer a fila do início
        aux = f.inicio;
        // Enquanto não chegar no fim
        while(aux != NULL) {
            // Imprime o dado do nó apontado por aux
            printf(" %c", aux->dado);
            // Vai para o próximo nó
            aux = aux->proximo;
        }
    } else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

char remover() {
    // Verifica se a fila não está vazia
    if(!verificarVazia()) {
        // Cria variável que vai apontar para o nó a ser removido
        No *aux;
        // Cria variável para guardar o dado do nó a ser removido
        char dado;
        // Aux aponta para o nó do início da fila
        aux = f.inicio;
        // Dado irá guardar o elemento do início da fila
        dado = aux->dado;
        // Atualiza o início da fila
        f.inicio = aux->proximo;
        // Se o nó removido for o nó final da fila, atualiza o final da fila
        if(f.final == aux)
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

int main(int argc, char *argv[]) {
    char temp;
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
        switch(opcao) {
            case 1:
                inicializar();
                break;
            case 2:
                printf("Digite o caractere: ");
                scanf(" %c", &temp);
                inserir(temp);
                break;
            case 3:
                temp = remover();
                printf("\nCaractere removido: %c", temp);
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

    } while(opcao != 5);
}

