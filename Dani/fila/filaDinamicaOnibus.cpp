#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir(char placa[11], int passageiros, double carga);
void inicializar();
int verificarVazia();
void imprimir();
void remover();

typedef struct {
    char placa[11];
    int passageiros;
    double carga;
} Onibus;

typedef struct no {
    Onibus dado;
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

void inserir(char placa[11], int passageiros, double carga) {
    // Aloca mem�ria para um novo n� da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado mem�ria, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Copia os dados do �nibus para o campo dado do novoNo
        strncpy(novoNo->dado.placa, placa, 10);
        novoNo->dado.placa[10] = '\0';
        novoNo->dado.passageiros = passageiros;
        novoNo->dado.carga = carga;
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
        printf("\nOs �nibus na fila s�o:\n");
        // Come�a a percorrer a fila do in�cio
        aux = f.inicio;
        // Enquanto n�o chegar ao fim
        while (aux != NULL) {
            // Imprime os dados do �nibus apontado por aux
            printf("Placa: %s, Passageiros: %d, Carga: %.2f\n", aux->dado.placa, aux->dado.passageiros, aux->dado.carga);
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
    }
}

void remover() {
    // Verifica se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Cria vari�vel que vai apontar para o n� a ser removido
        No* aux;
        // aux aponta para o n� do in�cio da fila
        aux = f.inicio;
        // Atualiza o in�cio da fila
        f.inicio = aux->proximo;
        // Se o n� removido for o n� final da fila, atualiza o final da fila
        if (f.final == aux)
            f.final = NULL;
        // Libera a mem�ria ocupada pelo n� removido
        free(aux);
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("A fila est� vazia.");
    }
}

int main(int argc, char* argv[]) {
    char placa[11];
    int passageiros;
    double carga;
    int opcao;
    inicializar();

    do {
        // Exibe o menu
        printf("\n    MENU");
        printf("\n1. Inicializar");
        printf("\n2. Inserir �nibus");
        printf("\n3. Remover �nibus");
        printf("\n4. Imprimir �nibus");
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
            printf("Digite a placa do �nibus: ");
            scanf("%s", placa);
            printf("Digite a quantidade de passageiros: ");
            scanf("%d", &passageiros);
            printf("Digite a carga do �nibus: ");
            scanf("%lf", &carga);
            inserir(placa, passageiros, carga);
            break;
        case 3:
            remover();
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

