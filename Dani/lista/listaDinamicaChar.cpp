#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char dado;
    struct no* proximo;
} No;

typedef struct lista {
    No* inicio;
} Lista;

void inicializar(Lista* lista) {
    lista->inicio = NULL;
}

int verificarVazia(Lista* lista) {
    return (lista->inicio == NULL);
}

void inserir(Lista* lista, char caracter, int posicao) {
    No* novoNoh = (No*)malloc(sizeof(No));
    if (novoNoh != NULL) {
        novoNoh->dado = caracter;
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
            printf("%c ", auxiliar->dado);
            auxiliar = auxiliar->proximo;
        }
    } else {
        printf("\nA lista esta vazia.");
    }
}

char remover(Lista* lista, int posicao) {
    if (!verificarVazia(lista)) {
        No* auxiliar = NULL;
        char caracterRemovido;
        
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
                return '\0';
            }
        }
        
        caracterRemovido = auxiliar->dado;
        free(auxiliar);
        return caracterRemovido;
    } else {
        printf("\nA lista estah vazia.");
    }
    
    return '\0';
}

int main() {
    Lista lista;
    int opcao, posicao;
    char caracter;
    
    inicializar(&lista);
    
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
            case 1:
                inicializar(&lista);
                printf("\nLista inicializada.");
                break;
            case 2:
                printf("\nDigite um caractere: ");
                scanf(" %c", &caracter);
                printf("\nDigite a posicao: ");
                scanf("%d", &posicao);
                inserir(&lista, caracter, posicao);
                break;
            case 3:
                printf("\nDigite a posicao: ");
                scanf("%d", &posicao);
                caracter = remover(&lista, posicao);
                if (caracter != '\0') {
                    printf("\nCaractere removido: %c", caracter);
                }
                break;
            case 4:
                imprimir(&lista);
                break;
            case 5:
                printf("\nSaindo do programa...");
                break;
            default:
                printf("\nEscolha uma opcao valida!");
        }
        
    } while (opcao != 5);
    
    return 0;
}

