void encontrarPrimeiroPar() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio;
        printf("\nPrimeiro número par na fila: ");
        // Percorre a fila
        while (aux != NULL) {
            // Se o dado do nó atual for par
            if (aux->dado % 2 == 0) {
                // Imprime o número par e interrompe a busca
                printf("%d", aux->dado);
                return;
            }
            // Vai para o próximo nó
            aux = aux->proximo;
        }
        // Se nenhum número par foi encontrado
        printf("Nenhum número par na fila.");
    }
    else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

void encontrarUltimoPar() {
    // Verificar se a fila não está vazia
    if (!verificarVazia()) {
        // Declara um ponteiro auxiliar para percorrer a fila
        No* aux = f.inicio;
        int ultimoPar = 0; // Variável para armazenar o último número par encontrado
        
        // Percorre a fila
        while (aux != NULL) {
            // Se o dado do nó atual for par
            if (aux->dado % 2 == 0) {
                ultimoPar = aux->dado; // Atualiza o último número par encontrado
            }
            // Vai para o próximo nó
            aux = aux->proximo;
        }
        
        // Verifica se algum número par foi encontrado
        if (ultimoPar != 0) {
            printf("\nÚltimo número par na fila: %d", ultimoPar);
        } else {
            printf("\nNenhum número par na fila.");
        }
    } else {
        // Informa o usuário que a fila está vazia
        printf("\nA fila está vazia.");
    }
}

