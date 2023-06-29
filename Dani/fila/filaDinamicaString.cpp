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
    // Aloca mem�ria para um novo n� da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado mem�ria, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Copia a string a ser inserida para o dado do novoNo
        strncpy(novoNo->dado, string, MAX_LENGTH);
        // Define o pr�ximo do novoNo como NULL
        novoNo->proximo = NULL;
        // Se a fila estiver vazia, o novoNo ser� tamb�m o in�cio da fila
        if (verificarVazia()) {
            f.inicio = novoNo;
        }
        else {
            // Se j� tiver elementos na fila, adiciona o novoNo ap�s o n� que est� no final da fila
            f.final->proximo = novoNo;
        }
        // Atualiza o final da fila para que seja o novoNo
        f.final = novoNo;
    }
    else {
        // Informa o usu�rio que n�o h� mais mem�ria dispon�vel
        printf("\nN�o � poss�vel adicionar na fila, pois n�o h� mais mem�ria dispon�vel.");
    }
}

void imprimir() {
    // Verifica se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara uma vari�vel ponteiro auxiliar para percorrer os n�s da fila
        No* aux;
        printf("\nOs elementos na fila s�o:\n");
        // Come�a a percorrer a fila do in�cio
        aux = f.inicio;
        // Enquanto n�o chegar ao fim
        while (aux != NULL) {
            // Imprime a string do n� apontado por aux
            printf("%s\n", aux->dado);
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
    }
}

char* remover() {
    // Verifica se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Cria vari�vel que vai apontar para o n� a ser removido
        No* aux;
        // Cria vari�vel para guardar a string do n� a ser removido
        char* dado = malloc(MAX_LENGTH * sizeof(char));
        // Aux aponta para o n� do in�cio da fila
        aux = f.inicio;
        // Copia a string do n� do in�cio da fila para dado
        strncpy(dado, aux->dado, MAX_LENGTH);
        // Atualiza o in�cio da fila
        f.inicio = aux->proximo;
        // Se o n� removido for o n� final da fila, atualiza o final da fila
        if (f.final == aux)
            f.final = NULL;
        // Libera a mem�ria ocupada pelo n� removido
        free(aux);
        // Retorna a string do n� removido
        return dado;
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("A fila est� vazia.");
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
        printf("\nDigite a op��o desejada: ");

        // L� a op��o desejada pelo usu�rio
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
            printf("\nOp��o inv�lida. Escolha um n�mero v�lido de op��o.");
        }

    } while (opcao != 5);
}

