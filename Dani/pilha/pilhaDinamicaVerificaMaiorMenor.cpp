#include <stdio.h>
#include <stdlib.h>

void push(int numero);
int pop();
void imprimir();
int verificarVazia();
void inicializar();
int obterMaior();
int obterMenor();

typedef struct no {
    int dado;
    struct no* anterior;
} No;

typedef struct pilha {
    No* topo;
    int maior;
    int menor;
} Pilha;

Pilha p;

void inicializar() {
    p.topo = NULL;
    p.maior = INT_MIN;  // Valor inicial para o maior elemento
    p.menor = INT_MAX;  // Valor inicial para o menor elemento
}

int verificarVazia() {
    if (p.topo == NULL)
        return 1;
    else
        return 0;
}

void push(int numero) {
    // Aloca mem�ria para um novo n� da pilha
    No* novoNoh = (No*)malloc(sizeof(No));
    // Se foi alocada mem�ria, adiciona o novoNo no topo da pilha
    if (novoNoh != NULL) {
        // Guarda o elemento a ser inserido na pilha no membro dado do novoNo
        novoNoh->dado = numero;
        // O pr�ximo elemento do novoNo ser� o elemento que est� no topo
        novoNoh->anterior = p.topo;
        // Atualiza o topo da pilha
        p.topo = novoNoh;

        // Atualiza o maior e o menor elemento, se necess�rio
        if (numero > p.maior)
            p.maior = numero;
        if (numero < p.menor)
            p.menor = numero;
    } else {
        // Sen�o, informa o usu�rio que n�o h� mais mem�ria
        printf("\nA pilha est� cheia pois n�o h� mais mem�ria dispon�vel.");
    }
}

int pop() {
    // Verifica se a pilha n�o est� vazia
    if (!verificarVazia()) {
        // Cria vari�vel que vai apontar para o n� a ser removido
        No* aux;
        // Cria vari�vel para guardar o dado do n� a ser removido
        int dado;
        // Aux aponta para o n� do topo
        aux = p.topo;
        // Dado ir� guardar o elemento do topo da pilha
        dado = p.topo->dado;
        // Atualiza o topo da pilha
        p.topo = aux->anterior;
        // Libera a mem�ria ocupada pelo n� removido
        free(aux);

        // Verifica se o elemento removido � o maior ou o menor elemento
        if (dado == p.maior) {
            // Se o elemento removido for o maior, atualiza o valor do maior elemento percorrendo a pilha novamente
            p.maior = obterMaior();
        }
        if (dado == p.menor) {
            // Se o elemento removido for o menor, atualiza o valor do menor elemento percorrendo a pilha novamente
            p.menor = obterMenor();
        }

        // Retorna o valor do n� removido
        return dado;
    } else {
        // Se a pilha estiver vazia, informa o usu�rio
        printf("\nA pilha est� vazia.");
        return 0;
    }
}

void imprimir() {
    // Verifica se a pilha n�o est� vazia
    if (!verificarVazia()) {
        // Declara uma vari�vel ponteiro auxiliar para percorrer os n�s da pilha
        No* aux;
        // Come�a a percorrer a partir do topo
        aux = p.topo;
        // Enquanto n�o chegar no fim
        while (aux != NULL) {
            // Imprimir o dado do n� apontado por aux
            printf(" %d", aux->dado);
            // Vai para o pr�ximo n�
            aux = aux->anterior;
        }
    } else {
        // Se estiver vazia, informa o usu�rio
        printf("\nA pilha est� vazia.");
    }
}

int obterMaior() {
    return p.maior;
}

int obterMenor() {
    return p.menor;
}

int main(int argc, char* argv[]) {
    int temp, opcao;
    inicializar();

    do {
        // Exibir o menu
        printf("\n    MENU");
        printf("\n1. Inicializar");
        printf("\n2. Inserir");
        printf("\n3. Remover");
        printf("\n4. Imprimir");
        printf("\n5. Obter Maior Elemento");
        printf("\n6. Obter Menor Elemento");
        printf("\n7. Sair");
        printf("\nDigite a op��o desejada: ");

        // Ler a op��o desejada pelo usu�rio
        scanf("%d", &opcao);

        // Processar a funcionalidade
        switch (opcao) {
            case 1:
                inicializar();
                break;
            case 2:
                printf("Digite um n�mero: ");
                scanf("%d", &temp);
                push(temp);
                break;
            case 3:
                temp = pop();
                printf("\nN�mero removido: %d", temp);
                break;
            case 4:
                imprimir();
                break;
            case 5:
                printf("\nMaior elemento: %d", obterMaior());
                break;
            case 6:
                printf("\nMenor elemento: %d", obterMenor());
                break;
            case 7:
                printf("\nEncerrando o programa...");
                break;
            default:
                printf("\nOp��o inv�lida. Escolha um n�mero v�lido de op��o.");
        }

    } while (opcao != 7);
}

