#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MODELO 50
#define MAX_COR 15

typedef struct {
    char modelo[MAX_MODELO];
    char cor[MAX_COR];
    char tamanho;
} Roupa;

void push(Roupa roupa);
Roupa pop();
void imprimir();
int verificarVazia();
void inicializar();

typedef struct no {
	Roupa dado;
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

void push(Roupa roupa){
	//aloca memoria para um novo noh da pilha
	No *novoNoh = (No *) malloc(sizeof(No));
	//se foi alocado memoria, adiciona o novoNo no topo da pilha
	if(novoNoh != NULL) {
		//guarda a roupa a inserir na pilha no membro dado do novoNo
		novoNoh->dado = roupa;
		//o proximo elemento do novoNo serah o elemento que estah no topo
		novoNoh->anterior = p.topo;
		//Atualiza o topo da pilha
		p.topo = novoNoh;	
	} else{
		//senao informa o usuario que nao ha mais memoria
		printf("\nA pilha estah cheia pois nao ha mais memoria disponivel");
	}
}

Roupa pop(){
	//verificar se a pilha não estah vazia
	if(!verificarVazia()) {
		//cria variavel que vai apontar para o noh a ser removido
		No *aux;
		//cria variavel para guardar o dado do noh a ser removido
		Roupa dado;
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
		Roupa roupaVazia;
		memset(&roupaVazia, 0, sizeof(Roupa));
		return roupaVazia;
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
			//imprimir os dados da roupa apontada por aux
			printf("Modelo: %s, Cor: %s, Tamanho: %c\n", aux->dado.modelo, aux->dado.cor, aux->dado.tamanho);
			//vai para o proximo noh
			aux = aux->anterior;
		}	
	} else {
		//se estiver vazia, informa o usuario
		printf("\nA pilha esta vazia.");
	}
}

int main() {
	Roupa temp;
	int opcao;
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
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				printf("Digite o modelo da roupa: ");
				scanf(" %[^\n]s", temp.modelo);
				printf("Digite a cor da roupa: ");
				scanf(" %[^\n]s", temp.cor);
				printf("Digite o tamanho da roupa (P, M ou G): ");
				scanf(" %c", &temp.tamanho);
				push(temp);
				break;
			case 3:
				temp = pop();
				if (temp.modelo[0] != '\0') {
					printf("Roupa removida: Modelo: %s, Cor: %s, Tamanho: %c\n", temp.modelo, temp.cor, temp.tamanho);
				}
				break;
			case 4:
				imprimir();
				break;
			case 5:
				printf("Encerrando o programa...\n");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 5);

	return 0;
}

