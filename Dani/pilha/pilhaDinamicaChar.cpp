#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char dado;
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

void push(Pilha* pilha, char caractere) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }
    novoNo->dado = caractere;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

char pop(Pilha* pilha) {
    if (verificarPilhaVazia(pilha)) {
        printf("Erro: a pilha esta vazia.\n");
        return '\0'; // Valor sentinela para indicar erro
    }
    No* noRemovido = pilha->topo;
    char dadoRemovido = noRemovido->dado;
    pilha->topo = noRemovido->proximo;
    free(noRemovido);
    return dadoRemovido;
}

void imprimirPilha(Pilha* pilha) {
    printf("Pilha: ");
    No* noAtual = pilha->topo;
    while (noAtual != NULL) {
        printf("%c ", noAtual->dado);
        noAtual = noAtual->proximo;
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    push(&pilha, 'A');
    push(&pilha, 'B');
    push(&pilha, 'C');
    push(&pilha, 'D');

    imprimirPilha(&pilha);

    char elementoRemovido = pop(&pilha);
    if (elementoRemovido != '\0') {
        printf("Elemento removido: %c\n", elementoRemovido);
    }

    imprimirPilha(&pilha);

    return 0;
}

