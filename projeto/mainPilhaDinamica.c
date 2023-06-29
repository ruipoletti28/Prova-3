#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 1000
#define qntd 1000

typedef long clock_t;

void push(int numero);
int pop();
void imprimir();
int verificarVazia();
void inicializar();

typedef struct no {
	int dado;
	struct no *anterior;
} No;

typedef struct pilha {
	No *topo;
} Pilha;

Pilha p;

void inicializar(){
	p.topo = NULL;
}

int verificarVazia(){
	if(p.topo == NULL)
		return 1;
	else return 0;
}

void push(int numero){
	//aloca memoria para um novo noh da pilha
	No *novoNoh = (No *) malloc(sizeof(No));
	//se foi alocado memoria, adiciona o novoNo no topo da pilha
	if(novoNoh != NULL) {
		//guarda o elemento a inserir na pilha no membro dado do novoNo
		novoNoh->dado = numero;
		//o proximo elemento do novoNo serah o elemento que estah no topo
		novoNoh->anterior = p.topo;
		//Atualiza o topo da pilha
		p.topo = novoNoh;	
	} else{
		//senao informa o usuario que nao ha mais memoria
		printf("\nA pilha estah cheia pois nao ha mais memoria disponivel");
	}
}

int pop(){
	//verificar se a pilha n�o estah vazia
	if(!verificarVazia()) {
		//cria variavel que vai apontar para o noh a ser removido
		No *aux;
		//cria variavel para guardar o dado do noh a ser removido
		int dado;
		//aux aponta para o noh do topo
		aux = p.topo;
		//dado ira guardar o elemento do topo da pilha
		dado = p.topo->dado;
		//atualizar o topo da pilha
		p.topo = aux->anterior;
		//libera a memoria ocupada pelo noh removido
		free(aux);
		//retorna o valor do noh removido
		return dado;
	} else {
		//se a pilha estiver vazia, informa o usuario
		printf("\nA pilha estah vazia.");
		return 0;
	}
}

void imprimir(){
	//verificar se a pilha nao estah vazia
	if(!verificarVazia()) {
		//Declara uma variavel ponteiro auxiliar para percorrer os nohs da pilha
		No *aux;
		//comeca a percorrer a partir do topo
		aux = p.topo;
		//enquanto nao chegar no fim
		while(aux != NULL) {
			//imprimir o dado do noh apontado por aux
			printf(" %d", aux->dado);
			//vai para o proximo noh
			aux = aux->anterior;
		}	
	} else {
		//se estiver vazia, informa o usuario
		printf("\nA pilha esta vazia.");
	}
}

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
        printf("\nElemento: %i", k);
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
        int k = pop();
        printf("\nElemento: %i", k);
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
        printf("\nA pilha estah vazia.");
        return;
    }
    clock_t start_t, end_t;
    double total_t;
    start_t = clock();
     
    //Declara uma variavel ponteiro auxiliar para percorrer os nohs da pilha
    No *aux;
    //comeca a percorrer a partir do topo
    aux = p.topo;
    //enquanto nao chegar no fim
    while(aux != NULL) {
        //imprimir o dado do noh apontado por aux
        printf("\nElemento: %d", aux->dado);
        //vai para o proximo noh
        aux = aux->anterior;
    }

    end_t = clock ();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTempo decorrido: %f", total_t);
}

int main(int argc, char *argv[]) {
	int temp, opcao;
	inicializar();

	do {
		//exibir o menu
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Sair");
		printf("\nDigite a opcao desejada: ");
		
		//ler a opcao desejada pelo usuario
		scanf("%d", &opcao);
		
		//processar a funcionalidade
		switch (opcao) {
            case 1:
                inicializar();
                break;
            case 2:
                printf("Digite o elemento a inserir na pilha: ");
                scanf("%d", &temp);
                push(temp);
                break;
            case 3:
                temp = pop();
                printf("O elemento removido da pilha foi: %d", temp);
                break;
            case 4:
                imprimir();
                break;
            case 5:
                printf("\nInserindo 1k de elementos na pilha.");
                insereMilElementos();
                break;
            case 6:
                printf("\nRemovendo 1k de elementos na pilha.");
                removeMilElementos();
                break;
            case 7: 
                printf("\nPrintando 1k de elementos na pilha.");
                imprimirMilElementos();
                break;
            case 8:
                printf("\nEncerrando o programa...");
                break;
            default:
                printf("\nOpcao invalida. Escolha um numero de 1 a 5.");
    
        }

    } while (opcao != 8);
}