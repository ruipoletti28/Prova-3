#include <stdio.h>
#include <stdlib.h>

void push(int numero);
int pop();
void imprimir();
int verificarVazia();
void inicializar();

typedef struct no {
    int dado;
    struct no* anterior;
} No;

typedef struct pilha {
    No* topo;
} Pilha;

Pilha p;

void inicializar() {
    p.topo = NULL;
}

int verificarVazia() {
    if (p.topo == NULL)
        return 1;
    else
        return 0;
}

void push(int numero) {
    // Verificar se a pilha est� vazia ou se o novo elemento � maior do que o elemento no topo
    if (verificarVazia() || numero > p.topo->dado) {
        // Alocar mem�ria para um novo n� da pilha
        No* novoNoh = (No*)malloc(sizeof(No));
        if (novoNoh != NULL) {
            // Guardar o elemento a ser inserido na pilha no membro "dado" do novoNoh
            novoNoh->dado = numero;
            // O pr�ximo elemento do novoNoh ser� o elemento que est� no topo
            novoNoh->anterior = p.topo;
            // Atualizar o topo da pilha
            p.topo = novoNoh;
        } else {
            // Se n�o houver mais mem�ria dispon�vel, informar ao usu�rio que a pilha est� cheia
            printf("\nA pilha est� cheia, pois n�o h� mais mem�ria dispon�vel.\n");
        }
    }
}

int pop() {
    // Verificar se a pilha n�o est� vazia
    if (!verificarVazia()) {
        // Criar uma vari�vel que apontar� para o n� a ser removido
        No* aux;
        // Criar uma vari�vel para guardar o dado do n� a ser removido
        int dado;
        // Aux aponta para o n� do topo
        aux = p.topo;
        // Dado ir� guardar o elemento do topo da pilha
        dado = p.topo->dado;
        // Atualizar o topo da pilha
        p.topo = aux->anterior;
        // Liberar a mem�ria ocupada pelo n� removido
        free(aux);
        // Retornar o valor do n� removido
        return dado;
    } else {
        // Se a pilha estiver vazia, informar ao usu�rio
        printf("\nA pilha est� vazia.\n");
        return 0;
    }
}

void imprimir() {
    // Verificar se a pilha n�o est� vazia
    if (!verificarVazia()) {
        // Declarar uma vari�vel ponteiro auxiliar para percorrer os n�s da pilha
        No* aux;
        // Come�ar a percorrer a partir do topo
        aux = p.topo;
        // Enquanto n�o chegar ao fim
        while (aux != NULL) {
            // Imprimir o dado do n� apontado por aux
            printf(" %d", aux->dado);
            // Ir para o pr�ximo n�
            aux = aux->anterior;
        }
        printf("\n");
    } else {
        // Se estiver vazia, informar ao usu�rio
        printf("\nA pilha est� vazia.\n");
    }
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
        printf("\n5. Sair");
        printf("\nDigite a opcao desejada: ");

        // Ler a op��o desejada pelo usu�rio
        scanf("%d", &opcao);

        // Processar a funcionalidade
        switch (opcao) {
            case 1:
                inicializar();
                break;
            case 2:
                printf("Digite um numero: ");
                scanf("%d", &temp);
                push(temp);
                break;
            case 3:
                temp = pop();
                printf("Numero removido: %d\n", temp);
                break;
            case 4:
                imprimir();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida. Escolha um numero valido de opcao.\n");
        }

    } while (opcao != 5);

    return 0;
}

