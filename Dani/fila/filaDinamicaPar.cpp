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
    // Aloca mem�ria para um novo n� da fila
    No* novoNo = (No*)malloc((sizeof(No)));
    // Se foi alocada mem�ria, adiciona o novoNo no fim da fila
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
        // Enquanto n�o chegar no fim
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
        return INT_MIN; // Retorna o menor valor poss�vel para indicar que a fila est� vazia
    }
}

void encontrarMenor() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara uma vari�vel para armazenar o menor valor encontrado
        int menor = f.inicio->dado;
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio->proximo;
        // Percorre a fila a partir do segundo n�
        while (aux != NULL) {
            // Se o dado do n� atual for menor que o menor valor encontrado at� agora
            if (aux->dado < menor) {
                // Atualiza o menor valor
                menor = aux->dado;
            }
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
        // Imprime o menor valor encontrado
        printf("\nMenor n�mero: %d", menor);
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
    }
}

void encontrarMaior() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara uma vari�vel para armazenar o maior valor encontrado
        int maior = f.inicio->dado;
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio->proximo;
        // Percorre a fila a partir do segundo n�
        while (aux != NULL) {
            // Se o dado do n� atual for maior que o maior valor encontrado at� agora
            if (aux->dado > maior) {
                // Atualiza o maior valor
                maior = aux->dado;
            }
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
        // Imprime o maior valor encontrado
        printf("\nMaior n�mero: %d", maior);
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
    }
}

void encontrarPares() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio;
        printf("\nN�meros pares na fila: ");
        // Percorre a fila
        while (aux != NULL) {
            // Se o dado do n� atual for par
            if (aux->dado % 2 == 0) {
                // Imprime o n�mero par
                printf("%d ", aux->dado);
            }
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
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
            printf("\nN�mero removido: %d", temp);
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
            printf("\nOp��o inv�lida. Escolha um n�mero v�lido de op��o.");
        }

    } while (opcao != 8);
}

