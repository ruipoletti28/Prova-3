#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    int quantidade;
} Item;

typedef struct no {
    Item item;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;

void inicializar(Lista* lista) {
    lista->inicio = NULL;
}

int verificarVazia(Lista* lista) {
    return (lista->inicio == NULL);
}

void inserir(Lista* lista, Item item, int posicao) {
    No* novoNoh = (No*)malloc(sizeof(No));
    if (novoNoh != NULL) {
        novoNoh->item = item;
        novoNoh->proximo = NULL;
        
        if (verificarVazia(lista) || posicao == 1) {
            novoNoh->proximo = lista->inicio;
            lista->inicio = novoNoh;
        } else {
            No* auxiliar = lista->inicio;
            int posicaoAtual = 1;
            
            while (posicaoAtual < posicao - 1 && auxiliar->proximo != NULL) {
                auxiliar = auxiliar->proximo;
                posicaoAtual++;
            }
            
            novoNoh->proximo = auxiliar->proximo;
            auxiliar->proximo = novoNoh;
        }
    } else {
        printf("\nNao eh possivel inserir elementos na lista pois a memoria estah cheia.");
    }
}

void imprimir(Lista* lista) {
    if (!verificarVazia(lista)) {
        No* auxiliar = lista->inicio;
        
        while (auxiliar != NULL) {
            printf("Nome: %s - Quantidade: %d\n", auxiliar->item.nome, auxiliar->item.quantidade);
            auxiliar = auxiliar->proximo;
        }
    } else {
        printf("\nA lista esta vazia.");
    }
}

Item remover(Lista* lista, int posicao) {
    Item itemRemovido;
    itemRemovido.quantidade = 0; // Inicializa a quantidade como zero
    
    if (!verificarVazia(lista)) {
        No* auxiliar = NULL;
        
        if (posicao == 1) {
            auxiliar = lista->inicio;
            lista->inicio = auxiliar->proximo;
        } else {
            No* noAnterior = lista->inicio;
            int posicaoAtual = 1;
            
            while (posicaoAtual < posicao - 1 && noAnterior != NULL) {
                noAnterior = noAnterior->proximo;
                posicaoAtual++;
            }
            
            if (noAnterior != NULL && noAnterior->proximo != NULL) {
                auxiliar = noAnterior->proximo;
                noAnterior->proximo = auxiliar->proximo;
            } else {
                printf("Nao existe elemento na posicao %d", posicao);
                return itemRemovido;
            }
        }
        
        itemRemovido = auxiliar->item;
        free(auxiliar);
    } else {
        printf("\nA lista estah vazia.");
    }
    
    return itemRemovido;
}

int main() {
    Lista lista;
    inicializar(&lista);
    
    int opcao;
    
    do {
        printf("\n MENU");
        printf("\n1. Inicializar");
        printf("\n2. Inserir");
        printf("\n3. Remover");
        printf("\n4. Exibir");
        printf("\n5. Sair");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                inicializar(&lista);
                printf("\nLista inicializada.");
                break;
            }
            case 2: {
                Item item;
                printf("\nDigite o nome do item: ");
                scanf(" %[^\n]", item.nome);
                printf("\nDigite a quantidade: ");
                scanf("%d", &item.quantidade);
                int posicao;
                printf("\nDigite a posicao: ");
                scanf("%d", &posicao);
                inserir(&lista, item, posicao);
                break;
            }
            case 3: {
                int posicao;
                printf("\nDigite a posicao: ");
                scanf("%d", &posicao);
                Item itemRemovido = remover(&lista, posicao);
                if (itemRemovido.quantidade != 0) {
                    printf("\nItem removido: Nome: %s - Quantidade: %d",
                        itemRemovido.nome, itemRemovido.quantidade);
                }
                break;
            }
            case 4: {
                imprimir(&lista);
                break;
            }
            case 5: {
                printf("\nSaindo do programa...");
                break;
            }
            default:
                printf("\nEscolha uma opcao valida!");
        }
        
    } while (opcao != 5);
    
    return 0;
}

