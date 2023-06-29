#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Biblioteca necess�ria para usar a constante INT_MAX

void inserir(int numero);
void inicializar();
int verificarVazia();
void imprimir();
int remover();
int encontrarMenor(); // Nova fun��o adicionada

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
    // Aloca mem�ria para um novo n� da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado mem�ria, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Guarda o n�mero a inserir na fila no campo dado do novoNo
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
        // Sen�o, informa o usu�rio que n�o h� mais mem�ria dispon�vel
        printf("\nN�o � poss�vel adicionar na fila, pois n�o h� mais mem�ria dispon�vel.");
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
        // Enquanto n�o chegar no fim
        while (aux != NULL) {
            // Imprimir o dado do n� apontado por aux
            printf("%d ", aux->dado);
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
        // aux aponta para o n� do in�cio da fila
        aux = f.inicio;
        // dado ir� guardar o elemento do in�cio da fila
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
        // Retorna um valor inv�lido para indicar que n�o foi poss�vel remover
        return INT_MIN;
    }
}

int encontrarMenor() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Inicializa a vari�vel menor com o maior valor poss�vel
        int menor = INT_MAX;
        // Declara uma vari�vel ponteiro auxiliar para percorrer os n�s da fila
        No* aux;
        // Come�a a percorrer a fila do in�cio
        aux = f.inicio;
        // Enquanto n�o chegar ao fim
        while (aux != NULL) {
            // Verifica se o dado do n� atual � menor que o valor atualmente armazenado em menor
            if (aux->dado < menor) {
                // Atualiza o valor de menor
                menor = aux->dado;
            }
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
        // Retorna o menor n�mero encontrado
        return menor;
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("A fila est� vazia.");
        // Retorna um valor inv�lido para indicar que n�o foi poss�vel encontrar o menor n�mero
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
        printf("\n5. Encontrar menor n�mero");
        printf("\n6. Sair");
        printf("\nDigite a op��o desejada: ");

        // Ler a op��o desejada pelo usu�rio
        scanf("%d", &opcao);

        // Processar a funcionalidade
        switch (opcao) {
        case 1:
            inicializar();
            break;
        case 2:
            printf("Digite o n�mero: ");
            scanf("%d", &temp);
            inserir(temp);
            break;
        case 3:
            temp = remover();
            if (temp != INT_MIN)
                printf("\nN�mero removido: %d", temp);
            break;
        case 4:
            imprimir();
            break;
        case 5:
            temp = encontrarMenor();
            if (temp != INT_MIN)
                printf("\nMenor n�mero encontrado na fila: %d", temp);
            break;
        case 6:
            printf("Encerrando o programa...");
            break;
        default:
            printf("\nOp��o inv�lida. Escolha um n�mero v�lido de op��o.");
        }

    } while (opcao != 6);
}

