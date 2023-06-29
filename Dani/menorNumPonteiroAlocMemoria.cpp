#include <stdio.h>
#include <stdlib.h>

int encontrarMenor(int* vetor, int tamanho) {
    int i;
    int menor = vetor[0];  // Inicializa com o primeiro elemento do vetor

    for (i = 1; i < tamanho; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    return menor;
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

    int menor = encontrarMenor(vetor, tamanho);

    printf("Menor elemento: %d\n", menor);

    free(vetor);

    return 0;
}

