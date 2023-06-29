#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no* proximo;
} No;

typedef struct pilha {
    No* topo;
} Pilha;

void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

int verificarPilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void push(Pilha* pilha, int numero) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }
    novoNo->dado = numero;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

int pop(Pilha* pilha) {
    if (verificarPilhaVazia(pilha)) {
        printf("Erro: a pilha esta vazia.\n");
        return -1; // Valor sentinela para indicar erro
    }
    No* noRemovido = pilha->topo;
    int dadoRemovido = noRemovido->dado;
    pilha->topo = noRemovido->proximo;
    free(noRemovido);
    return dadoRemovido;
}

void imprimirPilha(Pilha* pilha) {
    printf("Pilha: ");
    No* noAtual = pilha->topo;
    while (noAtual != NULL) {
        printf("%d ", noAtual->dado);
        noAtual = noAtual->proximo;
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    push(&pilha, 40);

    imprimirPilha(&pilha);

    int elementoRemovido = pop(&pilha);
    if (elementoRemovido != -1) {
        printf("Elemento removido: %d\n", elementoRemovido);
    }

    imprimirPilha(&pilha);

    return 0;
}

/*
Neste exemplo, a pilha é implementada usando uma estrutura Pilha, que contém um ponteiro para o topo da pilha. Cada elemento da pilha é representado por um nó da estrutura No, 
que possui um campo dado para armazenar o valor e um campo proximo para apontar para o próximo nó da pilha. As principais operações são implementadas da seguinte forma:

inicializarPilha: Inicializa a pilha, definindo o ponteiro para o topo como nulo.
verificarPilhaVazia: Verifica se a pilha está vazia, retornando 1 se estiver vazia ou 0 caso contrário.
push: Insere um elemento no topo da pilha, criando um novo nó, atribuindo o valor e atualizando os ponteiros.
pop: Remove o elemento do topo da pilha, atualizando os ponteiros e liberando a memória do nó removido.
imprimirPilha: Imprime os elementos da pilha, percorrendo os nós e exibindo os valores.
*/
