#include <stdio.h>

void trocarValores(int* ptrA, int* ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int a, b;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    trocarValores(&a, &b);

    printf("Valores trocados:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}

