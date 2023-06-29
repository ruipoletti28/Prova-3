#include <stdio.h>
#include <stdlib.h>

int contarMultiplosDe2(int* vetor, int tamanho) {
    int i;
    int quantidadeMultiplos = 0;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            quantidadeMultiplos++;
        }
    }

    return quantidadeMultiplos;
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

    int quantidadeMultiplos = contarMultiplosDe2(vetor, tamanho);

    printf("Quantidade de numeros multiplos de 2: %d\n", quantidadeMultiplos);

    free(vetor);

    return 0;
}

