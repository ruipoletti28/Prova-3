void push(int numero) {
    No* novoNo = (No*)malloc(sizeof(No));  // Cria um novo nó

    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }

    novoNo->dado = numero;  // Atribui o número ao dado do novo nó
    novoNo->anterior = p.topo;  // Faz o novo nó apontar para o antigo topo da pilha

    p.topo = novoNo;  // Atualiza o topo da pilha para o novo nó
}

/*
Explicação do código:

Cria-se um novo nó novoNo utilizando malloc para alocar memória para ele.
Verifica-se se a alocação de memória foi bem-sucedida. Caso contrário, exibe uma mensagem de erro e retorna.
Atribui-se o número passado como parâmetro ao campo dado do novo nó.
Define-se o campo anterior do novo nó para apontar para o antigo topo da pilha.
Atualiza-se o campo topo da pilha para apontar para o novo nó, tornando-o o novo topo da pilha.

Dessa forma, ao chamar a função push passando um número como argumento, esse número será inserido na pilha como um novo nó no topo.
*/
