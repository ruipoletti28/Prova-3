//encontra o maior nome e mostra a quantidade de letras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nome;
    char* sobrenome;
} Pessoa;

void concatenarNomes(Pessoa* pessoas, int numPessoas) {
    int i;
    for (i = 0; i < numPessoas; i++) {
        int tamanhoNome = strlen(pessoas[i].nome);
        int tamanhoSobrenome = strlen(pessoas[i].sobrenome);
        int tamanhoTotal = tamanhoNome + tamanhoSobrenome + 1;

        pessoas[i].nome = (char*)realloc(pessoas[i].nome, tamanhoTotal * sizeof(char));
        strcat(pessoas[i].nome, " ");
        strcat(pessoas[i].nome, pessoas[i].sobrenome);
    }
}

int encontrarNomeMaisLongo(Pessoa* pessoas, int numPessoas) {
    int i;
    int indiceMaior = 0;
    int tamanhoMaior = strlen(pessoas[0].nome);

    for (i = 1; i < numPessoas; i++) {
        int tamanhoAtual = strlen(pessoas[i].nome);
        if (tamanhoAtual > tamanhoMaior) {
            tamanhoMaior = tamanhoAtual;
            indiceMaior = i;
        }
    }

    return indiceMaior;
}

int contarLetras(char* nome) {
    int contador = 0;
    while (*nome != '\0') {
        if (*nome != ' ') {
            contador++;
        }
        nome++;
    }
    return contador;
}

int main() {
    int numPessoas;
    printf("Digite o numero de pessoas: ");
    scanf("%d", &numPessoas);

    Pessoa* pessoas = (Pessoa*)malloc(numPessoas * sizeof(Pessoa));

    if (pessoas == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    int i;
    for (i = 0; i < numPessoas; i++) {
        pessoas[i].nome = (char*)malloc(50 * sizeof(char));
        pessoas[i].sobrenome = (char*)malloc(50 * sizeof(char));

        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Digite o sobrenome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].sobrenome);
    }

    concatenarNomes(pessoas, numPessoas);

    printf("\nNomes concatenados:\n");
    for (i = 0; i < numPessoas; i++) {
        printf("%d: %s\n", i + 1, pessoas[i].nome);
    }

    int indiceMaior = encontrarNomeMaisLongo(pessoas, numPessoas);
    char* maiorNome = pessoas[indiceMaior].nome;
    int quantidadeLetrasMaior = contarLetras(maiorNome);

    printf("\nO maior nome e: %s\n", maiorNome);
    printf("A quantidade de letras do maior nome e: %d\n", quantidadeLetrasMaior);

    for (i = 0; i < numPessoas; i++) {
        free(pessoas[i].nome);
        free(pessoas[i].sobrenome);
    }
    free(pessoas);

    return 0;
}

   

