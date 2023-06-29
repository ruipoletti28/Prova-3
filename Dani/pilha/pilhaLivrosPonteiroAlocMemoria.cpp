#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* titulo;
    char* autor;
} Livro;

typedef struct {
    Livro* livros;
    int topo;
    int capacidade;
} PilhaLivros;

void inicializarPilha(PilhaLivros* pilha, int capacidade) {
    pilha->livros = (Livro*)malloc(capacidade * sizeof(Livro));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
}

int pilhaVazia(PilhaLivros* pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(PilhaLivros* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

void empilharLivro(PilhaLivros* pilha, Livro livro) {
    if (pilhaCheia(pilha)) {
        printf("A pilha está cheia. Não é possível empilhar o livro.\n");
        return;
    }

    pilha->topo++;
    pilha->livros[pilha->topo] = livro;
}

Livro desempilharLivro(PilhaLivros* pilha) {
    Livro livroVazio;
    livroVazio.titulo = NULL;
    livroVazio.autor = NULL;

    if (pilhaVazia(pilha)) {
        printf("A pilha está vazia. Não é possível desempilhar um livro.\n");
        return livroVazio;
    }

    Livro livroDesempilhado = pilha->livros[pilha->topo];
    pilha->topo--;

    return livroDesempilhado;
}

void exibirLivro(Livro livro) {
    printf("Título: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("------------------------\n");
}

void exibirPilhaLivros(PilhaLivros* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha está vazia.\n");
        return;
    }

    int i;
    for (i = pilha->topo; i >= 0; i--) {
        printf("Livro %d:\n", pilha->topo - i + 1);
        exibirLivro(pilha->livros[i]);
    }
}

void liberarPilha(PilhaLivros* pilha) {
    free(pilha->livros);
}

int main() {
    int capacidade;
    printf("Digite a capacidade da pilha de livros: ");
    scanf("%d", &capacidade);

    PilhaLivros pilha;
    inicializarPilha(&pilha, capacidade);

    int opcao;
    do {
        printf("Escolha uma opção:\n");
        printf("1 - Empilhar livro\n");
        printf("2 - Desempilhar livro\n");
        printf("3 - Exibir pilha de livros\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Livro livro;
                printf("Digite o título do livro: ");
                char buffer[100];
                scanf("%s", buffer);
                livro.titulo = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
                strcpy(livro.titulo, buffer);

                printf("Digite o autor do livro: ");
                scanf("%s", buffer);
                livro.autor = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
                strcpy(livro.autor, buffer);

                empilharLivro(&pilha, livro);
                break;
            }
            case 2: {
                Livro livroDesempilhado = desempilharLivro(&pilha);
                if (livroDesempilhado.titulo != NULL && livroDesempilhado.autor != NULL) {
                    printf("Livro desempilhado:\n");
                    exibirLivro(livroDesempilhado);
                    free(livroDesempilhado.titulo);
                    free(livroDesempilhado.autor);
                }
                break;
            }
            case 3:
                printf("Pilha de livros:\n");
                exibirPilhaLivros(&pilha);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    liberarPilha(&pilha);

    return 0;
}

