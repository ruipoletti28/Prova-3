#include <stdio.h>

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

void calcularMedia(Aluno* aluno) {
    aluno->media = (aluno->nota1 + aluno->nota2) / 2;
}

int main() {
    Aluno aluno1;

    printf("Digite o nome do aluno: ");
    scanf("%s", aluno1.nome);

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &aluno1.nota1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &aluno1.nota2);

    calcularMedia(&aluno1);

    printf("Nome: %s\n", aluno1.nome);
    printf("Media: %.2f\n", aluno1.media);

    return 0;
}

