#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

void exibirData(Data* data) {
    printf("%d/%d/%d\n", data->dia, data->mes, data->ano);
}

int main() {
    Data data;
    Data* ptrData = &data;

    ptrData->dia = 15;
    ptrData->mes = 6;
    ptrData->ano = 2022;

    exibirData(ptrData);

    return 0;
}

