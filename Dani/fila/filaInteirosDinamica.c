#include <stdio.h>
#include <stdlib.h>

void inserir(int numero);
void inicializar();
int verificarVazia();
void imprimir();
int remover();

typedef struct no {
	int dado;
	struct no *proximo;
} No;

typedef struct fila {
	No *inicio, *final;
} Fila;

Fila f;

void inicializar(){
	f.inicio = NULL;
	f.final = NULL;
}

int verificarVazia(){
	if(f.inicio == NULL)
		return 1;
	else return 0;
}

void inserir(int numero){
	//aloca memoria para um novo noh da fila
	No *novoNo = (No*) malloc((sizeof(No)));
    //se foi alocado memoria, adiciona o novoNo no fim da fila	
	if(novoNo != NULL) {
		//guarda o numero a inserir na fila na variavel dado do novoNo
		novoNo->dado = numero;
		//O novoNo sera o ultimo elemento da fila, logo nao tem proximo
		novoNo->proximo = NULL;
		//se a fila estiver fazia, o novoNo sera tambem o inicio da fila
		if(verificarVazia()) {
			f.inicio = novoNo;
		} else {
			//se ja tiver elementos na fila, adiciona o novoNo apos o noh que estah no final da fila
			f.final->proximo = novoNo;		
		}
		//atualiza o final da fila para que seja o novoNo
		f.final = novoNo;
	} else {
		//senao informa o usuario que nao ha mais memoria
		printf("\nNao eh possivel adicionar na fila pois nao ha mais memoria disponivel.");
	}
}

void imprimir(){
	//verificar se a fila nao estah vazia
	if(!verificarVazia()) {
		//Declara uma variavel ponteiro auxiliar para percorrer os nohs da fila
		No *aux;
		printf("\nOs elementos na fila sao: ");
		//comeca a percorre a fila do inicio
		aux = f.inicio;
		//enquanto nao chegar no fim
		while(aux != NULL) {
			//imprimir o dado do noh apontado por aux
			printf(" %d", aux->dado);
			//vai para o proximo noh
			aux = aux->proximo;
		}
	} else {
		//informa o usuario que a fila estah vazia
		printf("\nA fila estah vazia.");
	}
}

int remover() {
	//verificar se a fila não estah vazia
	if(!verificarVazia()) {
		//Cria variavel que vai apontar para o noh a ser removido
		No *aux;
		//Cria variavel para guardar o dado do noh a ser removido
		int dado;
		//aux aponta para o noh do inicio da fila
		aux = f.inicio;
		//dado ira guardar o elemento do inicio da fila
		dado = aux->dado;
		//atualizar o inicio da fila
		f.inicio = aux->proximo;
		//se o noh removido for o no final da fila, atualiza o final da fila
		if(f.final == aux)
			f.final = NULL;		
		//libera a memoria ocupada pelo noh removido
		free(aux);
		//retorna o valor do noh removido
		return dado;
	} else {
		//informa o usuario que a fila estah vazia
		printf("A fila estah vazia.");
	}
}

int main(int argc, char *argv[]) {
	int temp;
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
				printf("Digite o numero: ");
				scanf("%d", &temp);
				inserir(temp);
				break;
			case 3:
				temp = remover();
				printf("\nNumero removido: %d", temp);
				break;
			case 4:
				imprimir();
				break;
			case 5:
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 5);
}

