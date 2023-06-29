#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* titulo;
    char* autor;
} Livro;

void exibirLivros(Livro** livros, int numLivros) {
    int i;
    for (i = 0; i < numLivros; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: %s\n", livros[i]->titulo);
        printf("Autor: %s\n", livros[i]->autor);
        printf("------------------------\n");
    }
}

int main() {
    int numLivros;
    printf("Digite o número de livros: ");
    scanf("%d", &numLivros);

    Livro** livros = (Livro**)malloc(numLivros * sizeof(Livro*));

    if (livros == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    int i;
    for (i = 0; i < numLivros; i++) {
        livros[i] = (Livro*)malloc(sizeof(Livro));

        printf("Digite o título do livro %d: ", i + 1);
        char buffer[100];
        scanf("%s", buffer);
        livros[i]->titulo = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(livros[i]->titulo, buffer);

        printf("Digite o autor do livro %d: ", i + 1);
        scanf("%s", buffer);
        livros[i]->autor = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(livros[i]->autor, buffer);
    }

    exibirLivros(livros, numLivros);

    for (i = 0; i < numLivros; i++) {
        free(livros[i]->titulo);
        free(livros[i]->autor);
        free(livros[i]);
    }
    free(livros);

    return 0;
}

