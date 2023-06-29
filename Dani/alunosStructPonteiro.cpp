#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float nota1;
    float nota2;
    float media;
} Aluno;

void calcularMedia(Aluno* alunos, int numAlunos) {
    int i;
    for (i = 0; i < numAlunos; i++) {
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2;
    }
}

void exibirAlunos(Aluno* alunos, int numAlunos) {
    int i;
    for (i = 0; i < numAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Media: %.2f\n", alunos[i].media);
        printf("------------------------\n");
    }
}

int main() {
    int numAlunos;
    printf("Digite o numero de alunos: ");
    scanf("%d", &numAlunos);

    Aluno* alunos = (Aluno*)malloc(numAlunos * sizeof(Aluno));

    if (alunos == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    int i;
    for (i = 0; i < numAlunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("Digite a idade do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].idade);
        printf("Digite a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("Digite a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);
    }

    calcularMedia(alunos, numAlunos);
    exibirAlunos(alunos, numAlunos);

    free(alunos);

    return 0;
}

