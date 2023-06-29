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
    // Verificar se a pilha está vazia ou se o novo elemento é maior do que o elemento no topo
    if (verificarVazia() || numero > p.topo->dado) {
        // Alocar memória para um novo nó da pilha
        No* novoNoh = (No*)malloc(sizeof(No));
        if (novoNoh != NULL) {
            // Guardar o elemento a ser inserido na pilha no membro "dado" do novoNoh
            novoNoh->dado = numero;
            // O próximo elemento do novoNoh será o elemento que está no topo
            novoNoh->anterior = p.topo;
            // Atualizar o topo da pilha
            p.topo = novoNoh;
        } else {
            // Se não houver mais memória disponível, informar ao usuário que a pilha está cheia
            printf("\nA pilha está cheia, pois não há mais memória disponível.\n");
        }
    }
}

int pop() {
    // Verificar se a pilha não está vazia
    if (!verificarVazia()) {
        // Criar uma variável que apontará para o nó a ser removido
        No* aux;
        // Criar uma variável para guardar o dado do nó a ser removido
        int dado;
        // Aux aponta para o nó do topo
        aux = p.topo;
        // Dado irá guardar o elemento do topo da pilha
        dado = p.topo->dado;
        // Atualizar o topo da pilha
        p.topo = aux->anterior;
        // Liberar a memória ocupada pelo nó removido
        free(aux);
        // Retornar o valor do nó removido
        return dado;
    } else {
        // Se a pilha estiver vazia, informar ao usuário
        printf("\nA pilha está vazia.\n");
        return 0;
    }
}

void imprimir() {
    // Verificar se a pilha não está vazia
    if (!verificarVazia()) {
        // Declarar uma variável ponteiro auxiliar para percorrer os nós da pilha
        No* aux;
        // Começar a percorrer a partir do topo
        aux = p.topo;
        // Enquanto não chegar ao fim
        while (aux != NULL) {
            // Imprimir o dado do nó apontado por aux
            printf(" %d", aux->dado);
            // Ir para o próximo nó
            aux = aux->anterior;
        }
        printf("\n");
    } else {
        // Se estiver vazia, informar ao usuário
        printf("\nA pilha está vazia.\n");
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

        // Ler a opção desejada pelo usuário
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

