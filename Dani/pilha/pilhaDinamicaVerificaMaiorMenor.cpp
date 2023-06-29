#include <stdio.h>
#include <stdlib.h>

void push(int numero);
int pop();
void imprimir();
int verificarVazia();
void inicializar();
int obterMaior();
int obterMenor();

typedef struct no {
    int dado;
    struct no* anterior;
} No;

typedef struct pilha {
    No* topo;
    int maior;
    int menor;
} Pilha;

Pilha p;

void inicializar() {
    p.topo = NULL;
    p.maior = INT_MIN;  // Valor inicial para o maior elemento
    p.menor = INT_MAX;  // Valor inicial para o menor elemento
}

int verificarVazia() {
    if (p.topo == NULL)
        return 1;
    else
        return 0;
}

void push(int numero) {
    // Aloca memória para um novo nó da pilha
    No* novoNoh = (No*)malloc(sizeof(No));
    // Se foi alocada memória, adiciona o novoNo no topo da pilha
    if (novoNoh != NULL) {
        // Guarda o elemento a ser inserido na pilha no membro dado do novoNo
        novoNoh->dado = numero;
        // O próximo elemento do novoNo será o elemento que está no topo
        novoNoh->anterior = p.topo;
        // Atualiza o topo da pilha
        p.topo = novoNoh;

        // Atualiza o maior e o menor elemento, se necessário
        if (numero > p.maior)
            p.maior = numero;
        if (numero < p.menor)
            p.menor = numero;
    } else {
        // Senão, informa o usuário que não há mais memória
        printf("\nA pilha está cheia pois não há mais memória disponível.");
    }
}

int pop() {
    // Verifica se a pilha não está vazia
    if (!verificarVazia()) {
        // Cria variável que vai apontar para o nó a ser removido
        No* aux;
        // Cria variável para guardar o dado do nó a ser removido
        int dado;
        // Aux aponta para o nó do topo
        aux = p.topo;
        // Dado irá guardar o elemento do topo da pilha
        dado = p.topo->dado;
        // Atualiza o topo da pilha
        p.topo = aux->anterior;
        // Libera a memória ocupada pelo nó removido
        free(aux);

        // Verifica se o elemento removido é o maior ou o menor elemento
        if (dado == p.maior) {
            // Se o elemento removido for o maior, atualiza o valor do maior elemento percorrendo a pilha novamente
            p.maior = obterMaior();
        }
        if (dado == p.menor) {
            // Se o elemento removido for o menor, atualiza o valor do menor elemento percorrendo a pilha novamente
            p.menor = obterMenor();
        }

        // Retorna o valor do nó removido
        return dado;
    } else {
        // Se a pilha estiver vazia, informa o usuário
        printf("\nA pilha está vazia.");
        return 0;
    }
}

void imprimir() {
    // Verifica se a pilha não está vazia
    if (!verificarVazia()) {
        // Declara uma variável ponteiro auxiliar para percorrer os nós da pilha
        No* aux;
        // Começa a percorrer a partir do topo
        aux = p.topo;
        // Enquanto não chegar no fim
        while (aux != NULL) {
            // Imprimir o dado do nó apontado por aux
            printf(" %d", aux->dado);
            // Vai para o próximo nó
            aux = aux->anterior;
        }
    } else {
        // Se estiver vazia, informa o usuário
        printf("\nA pilha está vazia.");
    }
}

int obterMaior() {
    return p.maior;
}

int obterMenor() {
    return p.menor;
}

int main(int argc, char* argv[]) {
    int temp, opcao;
    inicializar();

    do {
        // Exibir o menu
        printf("\n    MENU");
        printf("\n1. Inicializar");
        printf("\n2. Inserir");
        printf("\n3. Remover");
        printf("\n4. Imprimir");
        printf("\n5. Obter Maior Elemento");
        printf("\n6. Obter Menor Elemento");
        printf("\n7. Sair");
        printf("\nDigite a opção desejada: ");

        // Ler a opção desejada pelo usuário
        scanf("%d", &opcao);

        // Processar a funcionalidade
        switch (opcao) {
            case 1:
                inicializar();
                break;
            case 2:
                printf("Digite um número: ");
                scanf("%d", &temp);
                push(temp);
                break;
            case 3:
                temp = pop();
                printf("\nNúmero removido: %d", temp);
                break;
            case 4:
                imprimir();
                break;
            case 5:
                printf("\nMaior elemento: %d", obterMaior());
                break;
            case 6:
                printf("\nMenor elemento: %d", obterMenor());
                break;
            case 7:
                printf("\nEncerrando o programa...");
                break;
            default:
                printf("\nOpção inválida. Escolha um número válido de opção.");
        }

    } while (opcao != 7);
}

