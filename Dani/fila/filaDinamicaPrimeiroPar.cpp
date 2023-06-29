void encontrarPrimeiroPar() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio;
        printf("\nPrimeiro n�mero par na fila: ");
        // Percorre a fila
        while (aux != NULL) {
            // Se o dado do n� atual for par
            if (aux->dado % 2 == 0) {
                // Imprime o n�mero par e interrompe a busca
                printf("%d", aux->dado);
                return;
            }
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
        // Se nenhum n�mero par foi encontrado
        printf("Nenhum n�mero par na fila.");
    }
    else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
    }
}

void encontrarUltimoPar() {
    // Verificar se a fila n�o est� vazia
    if (!verificarVazia()) {
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio;
        int ultimoPar = 0; // Vari�vel para armazenar o �ltimo n�mero par encontrado
        
        // Percorre a fila
        while (aux != NULL) {
            // Se o dado do n� atual for par
            if (aux->dado % 2 == 0) {
                ultimoPar = aux->dado; // Atualiza o �ltimo n�mero par encontrado
            }
            // Vai para o pr�ximo n�
            aux = aux->proximo;
        }
        
        // Verifica se algum n�mero par foi encontrado
        if (ultimoPar != 0) {
            printf("\n�ltimo n�mero par na fila: %d", ultimoPar);
        } else {
            printf("\nNenhum n�mero par na fila.");
        }
    } else {
        // Informa o usu�rio que a fila est� vazia
        printf("\nA fila est� vazia.");
    }
}

