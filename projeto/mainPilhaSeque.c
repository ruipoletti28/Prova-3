#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 25000
#define qntd 25000

typedef long clock_t;

typedef struct pilhaSequencial {
    int vetor[tamanho];
    int topo;
} PilhaSequencial;

PilhaSequencial p;

void push(int elemento);
int pop();
void imprimir();
int verificarVazia();
int verificarCheia();
void inicializar();
void insereMilElementos();
void removeMilElementos();

void push(int elemento) {
    // verificar se a pilha está cheia
    if (verificarCheia()) {
        printf("Nao eh possivel inserir elemento na pilha pois ela estah cheia");
        return;
    }

    // adicionar o elemento no topo da pilha
    p.vetor[p.topo] = elemento;
    p.topo++;
}

    int pop() {
        // verificar se a pilha está vazia
        if (verificarVazia()) {
            printf("A pilha estah vazia.");
            return 0;
        }
    
        // obter o elemento do topo da pilha e atualizar o topo
        p.topo--;
        return p.vetor[p.topo];
    }

void imprimir() {
    // verificar se a pilha está vazia
    if (verificarVazia()) {
        printf("A pilha estah vazia.");
        return;
    }

    // percorrer a pilha do topo até o fundo
    for (int i = p.topo - 1; i >= 0; i--) {
        printf("%d ", p.vetor[i]);
    }
}

int verificarVazia() {
    return (p.topo == 0);
}

int verificarCheia() {
    return (p.topo == tamanho);
}

void inicializar() {
    p.topo = 0;
}

/*void RandomInteger () {
    double start, finish, elapsed;
    start = (double) clock ();
    
    int low = 0;
    int high = 1000;
    int i;
    for (i = 0; i < 1000; i++) {
        int k;
        double d;
        d = (double) rand () / ((double) RAND_MAX + 1);
        k = d * (high - low + 1);
        push(k);
    }
    finish = (double) clock ();
    elapsed = finish - start;
    printf("\nTempo decorrido: %f", elapsed);
    //return low + k;
}*/

void insereMilElementos() {
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    int low = 1;
    int high = 10000;
    int i;
    for (i = 0; i < qntd; i++) {
        int k;
        double d;
        d = (double) rand () / ((double) RAND_MAX + 1);
        k = d * (high - low + 1);
        push(k); 
    }
    end_t = clock ();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTempo decorrido: %f, inserindo %d", total_t, i);
    //return low + k;
}

void removeMilElementos() {
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    int i;
    for (i = 0; i < qntd; i++) {
        pop(); 
    }
    end_t = clock ();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTempo decorrido: %f, removendo %d", total_t, i);
    //return low + k;
}

void imprimirMilElementos() {
    // verificar se a pilha está vazia
    if (verificarVazia()) {
        printf("A pilha estah vazia.");
        return;
    }

    int i;
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
    // percorrer a pilha do topo até o fundo
    for (i = p.topo - 1; i >= 0; i--) {
        printf("%d ", p.vetor[i]);
    }
    end_t = clock ();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTempo decorrido: %f", total_t);
}

int main(int argc, char* argv[]) {
    int opcao, elemento;
    inicializar();

    do {
        printf("\n     MENU");
        printf("\n1. Inserir elemento na pilha");
        printf("\n2. Remover elemento da pilha");
        printf("\n3. Imprimir a pilha");
        printf("\n4. Inserir 1k de elementos na pilha");
        printf("\n5. Remove 1k de elementos na pilha");
        printf("\n6. Printar 1k de elementos na pilha");
        printf("\n7. Sair");
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a inserir na pilha: ");
                scanf("%d", &elemento);
                push(elemento);
                break;
            case 2:
                elemento = pop();
                printf("O elemento removido da pilha foi: %d", elemento);
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("\nInserindo 1k de elementos na pilha.");
                insereMilElementos();
                break;
            case 5:
                printf("\nRemovendo 1k de elementos na pilha.");
                removeMilElementos();
                break;
            case 6: 
                printf("\nPrintando 1k de elementos na pilha.");
                imprimirMilElementos();
                break;
            case 7:
                printf("\nEncerrando o programa...");
                break;
            default:
                printf("\nOpcao invalida. Escolha um numero de 1 a 5.");
    
        }

    } while (opcao != 7);

    return 0;
}
