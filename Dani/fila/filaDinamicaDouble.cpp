#include <stdio.h>
#include <stdlib.h>

void inserir(double numero);
void inicializar();
int verificarVazia();
void imprimir();
double remover();

typedef struct no {
    double dado;
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

void inserir(double numero) {
    // Aloca mem�ria para um novo n� da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado mem�ria, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Guarda o n�mero a ser inserido na fila no campo dado do novoNo
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
        // Informa o usu�rio que n�o h� mais mem�ria dispon�vel
        printf("\nN�o � poss�vel adicionar na fila, pois n�o h� mais mem�ria dispon�vel.");
    }
}

void imprimir() {
    // Verifica se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara uma vari�vel ponteiro auxiliar para percorrer os n�s da fila
        No* aux;
        printf("\nOs elementos na fila s�o: ");
        // Come�a a percorrer a fila do in�cio
        aux = f.inicio;
        // Enquanto n�o chegar ao fim
        while (aux != NULL) {
            // Imprime o dado do n� apontado por aux
            printf("%.2f ", aux->dado);
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
    }
}

double remover() {
    // Verifica se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Cria vari�vel que vai apontar para o n� a ser removido
        No* aux;
        // Cria vari�vel para guardar o dado do n� a ser removido
        double dado;
        // Aux aponta para o n� do in�cio da fila
        aux = f.inicio;
        // Dado ir� guardar o elemento do in�cio da fila
        dado = aux->dado;
        // Atualiza o in�cio da fila
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
        return 0.0;
    }
}

int main(int argc, char* argv[]) {
    double temp;
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
            printf("Digite o n�mero: ");
            scanf("%lf", &temp);
            inserir(temp);
            break;
        case 3:
            printf("\nN�mero removido: %.2f", remover());
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

