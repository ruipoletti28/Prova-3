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
    // Aloca mem�ria para um novo n� da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado mem�ria, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Guarda o n�mero a inserir na fila na vari�vel dado do novoNo
        novoNo->dado = numero;
        // O novoNo ser� o �ltimo elemento da fila, logo n�o tem pr�ximo
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
        // Sen�o informa o usu�rio que n�o h� mais mem�ria
        printf("\nN�o � poss�vel adicionar na fila pois n�o h� mais mem�ria dispon�vel.");
    }
}

void imprimir() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara uma vari�vel ponteiro auxiliar para percorrer os n�s da fila
        No* aux;
        printf("\nOs elementos na fila s�o: ");
        // Come�a a percorrer a fila do in�cio
        aux = f.inicio;
        // Enquanto n�o chegar ao fim
        while (aux != NULL) {
            // Imprimir o dado do n� apontado por aux
            printf(" %d", aux->dado);
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
    }
}

int remover() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Cria vari�vel que vai apontar para o n� a ser removido
        No* aux;
        // Cria vari�vel para guardar o dado do n� a ser removido
        int dado;
        // Aux aponta para o n� do in�cio da fila
        aux = f.inicio;
        // Dado ir� guardar o elemento do in�cio da fila
        dado = aux->dado;
        // Atualizar o in�cio da fila
        f.inicio = aux->proximo;
        // Se o n� removido for o n� final da fila, atualiza o final da fila
        if (f.final == aux)
            f.final = NULL;
        // Libera a mem�ria ocupada pelo n� removido
        free(aux);
        // Retorna o valor do n� removido
        return dado;
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("A fila est� vazia.");
        return INT_MIN; // Retorna um valor inv�lido para indicar que n�o h� elementos na fila
    }
}

int encontrarMenor() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara uma vari�vel ponteiro auxiliar para percorrer os n�s da fila
        No* aux;
        // Inicializa o menor com o maior valor poss�vel
        int menor = INT_MAX;
        // Come�a a percorrer a fila do in�cio
        aux = f.inicio;
        // Enquanto n�o chegar ao fim
        while (aux != NULL) {
            // Se o dado do n� atual for menor que o menor atual, atualiza o menor
            if (aux->dado < menor) {
                menor = aux->dado;
            }
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
        // Retorna o menor encontrado
        return menor;
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("A fila est� vazia.");
        return INT_MIN; // Retorna um valor inv�lido para indicar que n�o h� elementos na fila
    }
}

int encontrarMaior() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara uma vari�vel ponteiro auxiliar para percorrer os n�s da fila
        No* aux;
        // Inicializa o maior com o menor valor poss�vel
        int maior = INT_MIN;
        // Come�a a percorrer a fila do in�cio
        aux = f.inicio;
        // Enquanto n�o chegar ao fim
        while (aux != NULL) {
            // Se o dado do n� atual for maior que o maior atual, atualiza o maior
            if (aux->dado > maior) {
                maior = aux->dado;
            }
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
        // Retorna o maior encontrado
        return maior;
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("A fila est� vazia.");
        return INT_MIN; // Retorna um valor inv�lido para indicar que n�o h� elementos na fila
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

        // Ler a op��o desejada pelo usu�rio
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

