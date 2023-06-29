#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir(char placa[11], int passageiros, double carga);
void inicializar();
int verificarVazia();
void imprimir();
void remover();

typedef struct {
    char placa[11];
    int passageiros;
    double carga;
} Onibus;

typedef struct no {
    Onibus dado;
    struct no* proximo;
} No;

typedef struct fila {
    No* inicio;
    No* final;
} Fila;

Fila f;

void inicializar() {
    f.inicio = NULL;
    f.final = NULL;
}

int verificarVazia() {
    if (f.inicio == NULL)
        return 1;
    else
        return 0;
}

void inserir(char placa[11], int passageiros, double carga) {
    // Aloca memória para um novo nó da fila
    No* novoNo = (No*)malloc(sizeof(No));
    // Se foi alocado memória, adiciona o novoNo no fim da fila
    if (novoNo != NULL) {
        // Copia os dados do ônibus para o campo dado do novoNo
        strncpy(novoNo->dado.placa, placa, 10);
        novoNo->dado.placa[10] = '\0';
        novoNo->dado.passageiros = passageiros;
        novoNo->dado.carga = carga;
        // O novoNo será o último elemento da fila, logo não tem próximo
        novoNo->proximo = NULL;
        // Se a fila estiver vazia, o novoNo será também o início da fila
        if (verificarVazia()) {
            f.inicio = novoNo;
        }
        else {
            // Se já tiver elementos na fila, adiciona o novoNo após o nó que está no final da fila
            f.final->proximo = novoNo;
        }
        // Atualiza o final da fila para que seja o novoNo
        f.final = novoNo;
    }
    else {
        // Informa o usuário que não há mais memória disponível
        printf("\nNão é possível adicionar na fila, pois não há mais memória disponível.");
    }
}

void imprimir() {
    // Verifica se a fila não está vazia
    if (!verificarVazia()) {
        // Declara uma variável ponteiro auxiliar para percorrer os nós da fila
        No* aux;
        printf("\nOs ônibus na fila são:\n");
        // Começa a percorrer a fila do início
        aux = f.inicio;
        // Enquanto não chegar ao fim
        while (aux != NULL) {
            // Imprime os dados do ônibus apontado por aux
            printf("Placa: %s, Passageiros: %d, Carga: %.2f\n", aux->dado.placa, aux->dado.passageiros, aux->dado.carga);
            // Vai para o próximo nó
            aux = aux->proximo;
        }
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

void remover() {
    // Verifica se a fila não está vazia
    if (!verificarVazia()) {
        // Cria variável que vai apontar para o nó a ser removido
        No* aux;
        // aux aponta para o nó do início da fila
        aux = f.inicio;
        // Atualiza o início da fila
        f.inicio = aux->proximo;
        // Se o nó removido for o nó final da fila, atualiza o final da fila
        if (f.final == aux)
            f.final = NULL;
        // Libera a memória ocupada pelo nó removido
        free(aux);
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("A fila está vazia.");
    }
}

int main(int argc, char* argv[]) {
    char placa[11];
    int passageiros;
    double carga;
    int opcao;
    inicializar();

    do {
        // Exibe o menu
        printf("\n    MENU");
        printf("\n1. Inicializar");
        printf("\n2. Inserir ônibus");
        printf("\n3. Remover ônibus");
        printf("\n4. Imprimir ônibus");
        printf("\n5. Sair");
        printf("\nDigite a opção desejada: ");

        // Lê a opção desejada pelo usuário
        scanf("%d", &opcao);

        // Processa a funcionalidade
        switch (opcao) {
        case 1:
            inicializar();
            break;
        case 2:
            printf("Digite a placa do ônibus: ");
            scanf("%s", placa);
            printf("Digite a quantidade de passageiros: ");
            scanf("%d", &passageiros);
            printf("Digite a carga do ônibus: ");
            scanf("%lf", &carga);
            inserir(placa, passageiros, carga);
            break;
        case 3:
            remover();
            break;
        case 4:
            imprimir();
            break;
        case 5:
            printf("Encerrando o programa...");
            break;
        default:
            printf("\nOpção inválida. Escolha um número válido de opção.");
        }

    } while (opcao != 5);
}

