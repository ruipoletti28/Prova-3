#include <stdio.h>

int encontrarMaior(int* vetor, int tamanho) {
    int i;
    int maior = *vetor;  // Inicializa com o primeiro elemento do vetor

    for (i = 1; i < tamanho; i++) {
        if (*(vetor + i) > maior) {  // Equivalente a vetor[i]
            maior = *(vetor + i);
        }
    }

    return maior;
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
        scanf("%d", vetor + i);  // Equivalente a &vetor[i]
    }

    int maior = encontrarMaior(vetor, tamanho);

    printf("Maior elemento: %d\n", maior);

    free(vetor);

    return 0;
}

