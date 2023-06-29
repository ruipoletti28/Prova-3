#include <stdio.h>
#include <stdlib.h>

void inserir(int numero, int posicao);
int remover(int posicao);
void imprimir();
void inicializar();
int verificarVazia();

typedef struct no {
	int dado;
	struct no *proximo;
} No;

typedef struct lista {
	No *inicio;
} Lista;

Lista l;

void inicializar(){
	l.inicio = NULL;
}

int verificarVazia(){
	if(l.inicio == NULL)
		return 1;
	else return 0;
}

void inserir(int numero, int posicao){
	//alocar memoria para um novo noh da lista
	No *novoNoh = (No *) malloc(sizeof(No));
	//se foi alocada memoria, adiciona o novoNo na lista
	if(novoNoh != NULL) {
		//atribuir o elemento ao membro dado do novo noh
		novoNoh->dado = numero;
		//atribuir NULL ao campo proximo do novo noh
		novoNoh->proximo = NULL;
		//verificar se a lista estah vazia ou se deseja inserir elemento na primeira posicao
		if(verificarVazia() || posicao == 1) {
			//o campo proximo do novo noh devera apontar para o noh apontado no inicio
			novoNoh->proximo = l.inicio;
			//atualiza o inicio da lista
			l.inicio = novoNoh;
		} else {
			//criar um ponteiro para no chamado auxiliar
			No *auxiliar = NULL;
			//criar uma variavel contador para saber qual a posicao do noh que auxiliar aponta
			int posicaoNoAuxiliar = 1;
			//ponteiro auxiliar aponta para o primeiro noh da lista
			auxiliar = l.inicio;
			//percorre a lista ateh encontrar o noh na posicao-1 ou o final da lista
			while (posicaoNoAuxiliar < posicao-1 && auxiliar->proximo != NULL) {
				auxiliar = auxiliar->proximo;
				posicaoNoAuxiliar++;
			}
			//atualiza o campo proximo do novoNoh
			novoNoh->proximo = auxiliar->proximo;
			//atualiza o campo proximo do noh auxiliar
			auxiliar->proximo = novoNoh;
		}
	} else {
		//senao informa o usuario que nao ha mais memoria
		printf("\nNao eh possivel inserir elementos na lista pois a memoria estah cheia");
	}
}

void imprimir() {
	//verificar se a lista nao estah vazia
	if(!verificarVazia()) {
		//Declara uma variavel ponteiro auxiliar para percorrer os nohs da lista
		No *aux;
		//comeca a percorrer a partir do inicio
		aux = l.inicio;
		//enquanto nao chegar no fim
		while (aux != NULL) {
			//imprimir o dado do noh apontado pelo ponteiro auxiliar
			printf(" %d", aux->dado);
			//vai para o proximo noh
			aux = aux->proximo;
		}
	} else {
		//se estiver vazia, informa o usuario
		printf("\nA lista esta vazia");
	}
}

int remover(int posicao) {
	//verifica se a lista nao estah vazia
	if(!verificarVazia()) {
		//cria variavel auxiliar ponteiro para um noh
		No *aux = NULL;
		//cria variavel para guardar o dado do noh a ser removido
		int dado;
		//verificar se eh o primeiro elemento q sera removido
		if(posicao == 1) {
			//variavel auxiliar aponta para o primeiro noh
			aux = l.inicio;
			//atualiza o inicio da lista
			l.inicio = aux->proximo;
		} else {
			//declara uma variavel ponteiro noAnterior para percorrer os nohs da lista
			No *noAnterior;
			//criar uma variavel contador para saber qual a posicao do noh que anoAnterior aponta
			int posicaoNoAnterior = 1;
			//ponteiro noAnterior aponta para o primeiro noh da lista
			noAnterior = l.inicio;
			//percorre a lista ateh encontra o noh de posicao anterior ao noh da posicao a remover ou final da lista
			while(posicaoNoAnterior < posicao-1 && noAnterior != NULL) {
				noAnterior = noAnterior->proximo;
				posicaoNoAnterior++;
			}
			//se existir um noh na posicao desejada
			if(noAnterior != NULL && noAnterior->proximo != NULL) {
				//ponteiro auxiliar aponta para o noh a ser removido
				aux = noAnterior->proximo;
				//atualiza o membro proximo do noh anterior para apontar para o noh seguinte ao no apontado pelo ponteiro auxiliar
				noAnterior->proximo = aux->proximo;				
			} else {
				//se nao existe um noh na posicao desejada
				//informa ao usuario que nao existe elemento na posicao indicada
				printf("Nao existe elemento na posicao %d", posicao);
				return 0;
			}
		}
		//atribuir o dado do noh a remover para a variavel dado	
		dado = aux->dado;
		//libera a memoria ocupada pelo noh removido
		free(aux);
		//retorna o valor do noh removido
		return dado;		
	} else {
		printf("\nA lista estah vazia.");
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int opcao, temp, posicao;
	
	do {
		//exibir o menu
		printf("\n MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Exibir");
		printf("\n5. Sair");
		printf("\nDigite a opcao desejada: ");
		//pedir a opcao ao usuario
		scanf("%i", &opcao);
		
		//processar a opcao desejada
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				printf("\nDigite um numero: ");
				scanf("%d", &temp);
				printf("\nDigite a posicao: ");
				scanf("%d", &posicao);
				inserir(temp, posicao);
				break;
			case 3:
				printf("\nDigite a posicao: ");
				scanf("%d", &posicao);
				temp = remover(posicao);
				printf("\nNumero removido: %d",
					temp);
				break;
			case 4:
				imprimir();
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