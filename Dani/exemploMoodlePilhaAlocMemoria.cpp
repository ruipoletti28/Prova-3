void push(int numero) {
    No* novoNo = (No*)malloc(sizeof(No));  // Cria um novo n�

    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }

    novoNo->dado = numero;  // Atribui o n�mero ao dado do novo n�
    novoNo->anterior = p.topo;  // Faz o novo n� apontar para o antigo topo da pilha

    p.topo = novoNo;  // Atualiza o topo da pilha para o novo n�
}

/*
Explica��o do c�digo:

Cria-se um novo n� novoNo utilizando malloc para alocar mem�ria para ele.
Verifica-se se a aloca��o de mem�ria foi bem-sucedida. Caso contr�rio, exibe uma mensagem de erro e retorna.
Atribui-se o n�mero passado como par�metro ao campo dado do novo n�.
Define-se o campo anterior do novo n� para apontar para o antigo topo da pilha.
Atualiza-se o campo topo da pilha para apontar para o novo n�, tornando-o o novo topo da pilha.

Dessa forma, ao chamar a fun��o push passando um n�mero como argumento, esse n�mero ser� inserido na pilha como um novo n� no topo.
*/
