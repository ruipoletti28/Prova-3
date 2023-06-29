#include <stdio.h>
#include <stdlib.h>

void inserir(int numero, int posicao);
int remover(int posicao);
void imprimir();
void inicializar();
int verificarVazia();
int encontrarMaior();
int encontrarMenor();
int encontrarPrimeiroPar();
int encontrarUltimoPar();
int contarElementosPares();

typedef struct no {
	int dado;
	struct no *proximo;
} No;

typedef struct lista {
	No *inicio;
} Lista;

Lista l;

void inicializar() {
	l.inicio = NULL;
}

int verificarVazia() {
	if (l.inicio == NULL)
		return 1;
	else
		return 0;
}

void inserir(int numero, int posicao) {
	No *novoNoh = (No *)malloc(sizeof(No));
	if (novoNoh != NULL) {
		novoNoh->dado = numero;
		novoNoh->proximo = NULL;
		if (verificarVazia() || posicao == 1) {
			novoNoh->proximo = l.inicio;
			l.inicio = novoNoh;
		} else {
			No *auxiliar = NULL;
			int posicaoNoAuxiliar = 1;
			auxiliar = l.inicio;
			while (posicaoNoAuxiliar < posicao - 1 && auxiliar->proximo != NULL) {
				auxiliar = auxiliar->proximo;
				posicaoNoAuxiliar++;
			}
			novoNoh->proximo = auxiliar->proximo;
			auxiliar->proximo = novoNoh;
		}
	} else {
		printf("\nNao eh possivel inserir elementos na lista pois a memoria estah cheia");
	}
}

void imprimir() {
	if (!verificarVazia()) {
		No *aux;
		aux = l.inicio;
		while (aux != NULL) {
			printf(" %d", aux->dado);
			aux = aux->proximo;
		}
	} else {
		printf("\nA lista esta vazia");
	}
}

int remover(int posicao) {
	if (!verificarVazia()) {
		No *aux = NULL;
		int dado;
		if (posicao == 1) {
			aux = l.inicio;
			l.inicio = aux->proximo;
		} else {
			No *noAnterior;
			int posicaoNoAnterior = 1;
			noAnterior = l.inicio;
			while (posicaoNoAnterior < posicao - 1 && noAnterior != NULL) {
				noAnterior = noAnterior->proximo;
				posicaoNoAnterior++;
			}
			if (noAnterior != NULL && noAnterior->proximo != NULL) {
				aux = noAnterior->proximo;
				noAnterior->proximo = aux->proximo;
			} else {
				printf("Nao existe elemento na posicao %d", posicao);
				return 0;
			}
		}
		dado = aux->dado;
		free(aux);
		return dado;
	} else {
		printf("\nA lista estah vazia.");
	}
	return 0;
}

int encontrarMaior() {
	if (!verificarVazia()) {
		No *aux = l.inicio;
		int maior = aux->dado;
		aux = aux->proximo;
		while (aux != NULL) {
			if (aux->dado > maior)
				maior = aux->dado;
			aux = aux->proximo;
		}
		return maior;
	} else {
		printf("\nA lista estah vazia.");
		return -1; // Retorna um valor inválido para indicar que não há elementos na lista
	}
}

int encontrarMenor() {
	if (!verificarVazia()) {
		No *aux = l.inicio;
		int menor = aux->dado;
		aux = aux->proximo;
		while (aux != NULL) {
			if (aux->dado < menor)
				menor = aux->dado;
			aux = aux->proximo;
		}
		return menor;
	} else {
		printf("\nA lista estah vazia.");
		return -1; // Retorna um valor inválido para indicar que não há elementos na lista
	}
}

int encontrarPrimeiroPar() {
	if (!verificarVazia()) {
		No *aux = l.inicio;
		while (aux != NULL) {
			if (aux->dado % 2 == 0)
				return aux->dado;
			aux = aux->proximo;
		}
		printf("\nNao foi encontrado nenhum numero par na lista.");
		return -1; // Retorna um valor inválido para indicar que não há números pares na lista
	} else {
		printf("\nA lista estah vazia.");
		return -1; // Retorna um valor inválido para indicar que não há elementos na lista
	}
}

int encontrarUltimoPar() {
	if (!verificarVazia()) {
		No *aux = l.inicio;
		int ultimoPar = -1; // Valor inválido para indicar que não há números pares na lista
		while (aux != NULL) {
			if (aux->dado % 2 == 0)
				ultimoPar = aux->dado;
			aux = aux->proximo;
		}
		if (ultimoPar != -1)
			return ultimoPar;
		else {
			printf("\nNao foi encontrado nenhum numero par na lista.");
			return -1; // Retorna um valor inválido para indicar que não há números pares na lista
		}
	} else {
		printf("\nA lista estah vazia.");
		return -1; // Retorna um valor inválido para indicar que não há elementos na lista
	}
}

int contarElementosPares() {
	if (!verificarVazia()) {
		No *aux = l.inicio;
		int quantidadePares = 0;
		while (aux != NULL) {
			if (aux->dado % 2 == 0)
				quantidadePares++;
			aux = aux->proximo;
		}
		return quantidadePares;
	} else {
		printf("\nA lista estah vazia.");
		return 0;
	}
}

int localizarElemento(int numero) {
	if (!verificarVazia()) {
		No *aux = l.inicio;
		int posicao = 1;
		while (aux != NULL) {
			if (aux->dado == numero)
				return posicao;
			aux = aux->proximo;
			posicao++;
		}
		printf("\nO numero %d nao foi encontrado na lista.", numero);
		return -1; // Retorna um valor inválido para indicar que o número não foi encontrado
	} else {
		printf("\nA lista estah vazia.");
		return -1; // Retorna um valor inválido para indicar que não há elementos na lista
	}
}


int main(int argc, char *argv[]) {
	int opcao, temp, posicao;

	do {
		printf("\n MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Exibir");
		printf("\n5. Maior Elemento");
		printf("\n6. Menor Elemento");
		printf("\n7. Primeiro Elemento Par");
		printf("\n8. Ultimo Elemento Par");
		printf("\n9. Quantidade de Elementos Pares");
		printf("\n10. Localizar Elemento");
		printf("\n11. Sair");
		printf("\nDigite a opcao desejada: ");
		scanf("%i", &opcao);

		switch (opcao) {
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
				printf("\nNumero removido: %d", temp);
				break;
			case 4:
				imprimir();
				break;
			case 5:
				temp = encontrarMaior();
				if (temp != -1)
					printf("\nMaior elemento: %d", temp);
				break;
			case 6:
				temp = encontrarMenor();
				if (temp != -1)
					printf("\nMenor elemento: %d", temp);
				break;
			case 7:
				temp = encontrarPrimeiroPar();
				if (temp != -1)
					printf("\nPrimeiro elemento par: %d", temp);
				break;
			case 8:
				temp = encontrarUltimoPar();
				if (temp != -1)
					printf("\nUltimo elemento par: %d", temp);
				break;
			case 9:
				temp = contarElementosPares();
				printf("\nQuantidade de elementos pares: %d", temp);
				break;
			case 11:
				printf("\nSaindo do programa...");
				break;
			case 10:
				printf("\nDigite o numero a ser localizado: ");
				scanf("%d", &temp);
				posicao = localizarElemento(temp);
				if (posicao != -1)
					printf("\nO numero %d foi encontrado na posicao %d", temp, posicao);
				break;
			default:
				printf("\nEscolha uma opcao valida!");
		}

	} while (opcao != 10);
	return 0;
}

