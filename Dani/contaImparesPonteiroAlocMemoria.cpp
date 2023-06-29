#include <stdio.h>
#include <stdlib.h>

int contarNumerosImpares(int* vetor, int tamanho) {
    int i;
    int quantidadeImpares = 0;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 != 0) {
            quantidadeImpares++;
        }
    }

    return quantidadeImpares;
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int* vetor = (int*)malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    int i;
    for (i = 0; i < tamanho; i++) {
        printf("Digite o valor para o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int quantidadeImpares = contarNumerosImpares(vetor, tamanho);

    printf("Quantidade de numeros impares: %d\n", quantidadeImpares);

    free(vetor);

    return 0;
}

