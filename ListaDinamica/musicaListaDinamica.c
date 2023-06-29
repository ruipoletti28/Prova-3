#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITULO 50
#define MAX_BANDA 50

// Definição da estrutura da música
typedef struct {
    char titulo[MAX_TITULO];
    char banda[MAX_BANDA];
    int tempoExecucao;
} Musica;

// Definição da estrutura do nó da lista
typedef struct No {
    Musica musica;
    struct No* proximo;
} No;

// Função para inserir uma música na playlist
void inserirMusica(No** playlist, Musica novaMusica) {
    // Aloca memória para o novo nó
    No* novoNo = (No*) malloc(sizeof(No));

    // Copia os dados da nova música para o nó
    strcpy(novoNo->musica.titulo, novaMusica.titulo);
    strcpy(novoNo->musica.banda, novaMusica.banda);
    novoNo->musica.tempoExecucao = novaMusica.tempoExecucao;

    // Verifica se a lista está vazia ou se a nova música deve ser inserida no início
    if (*playlist == NULL || strcmp(novaMusica.titulo, (*playlist)->musica.titulo) < 0) {
        // O próximo nó do novo nó será o nó atual do início da lista
        novoNo->proximo = *playlist;

        // O início da lista será o novo nó
        *playlist = novoNo;
    } else {
        No* atual = *playlist;

        // Percorre a lista até encontrar a posição correta para inserir a nova música
        while (atual->proximo != NULL && strcmp(novaMusica.titulo, atual->proximo->musica.titulo) > 0) {
            atual = atual->proximo;
        }

        // Insere o novo nó na posição correta
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

// Função para imprimir a playlist
void imprimirPlaylist(No* playlist) {
    No* atual = playlist;

    printf("Playlist:\n");

    // Percorre a lista e imprime as músicas
    while (atual != NULL) {
        printf("Título: %s\n", atual->musica.titulo);
        printf("Banda: %s\n", atual->musica.banda);
        printf("Tempo de execução: %d segundos\n\n", atual->musica.tempoExecucao);
        atual = atual->proximo;
    }
}

// Função para remover uma música da playlist
void removerMusica(No** playlist, char tituloMusica[]) {
    if (*playlist == NULL) {
        printf("A playlist está vazia. Não é possível remover.\n");
        return;
    }

    No* noRemovido = NULL;

    // Verifica se a música a ser removida está no início da lista
    if (strcmp(tituloMusica, (*playlist)->musica.titulo) == 0) {
        noRemovido = *playlist;
        *playlist = (*playlist)->proximo;
    } else {
        No* atual = *playlist;

        // Percorre a lista até encontrar a música a ser removida ou chegar ao final da lista
        while (atual->proximo != NULL && strcmp(tituloMusica, atual->proximo->musica.titulo) != 0) {
            atual = atual->proximo;
        }

        // Verifica se a música foi encontrada
        if (atual->proximo != NULL) {
            noRemovido = atual->proximo;
            atual->proximo = atual->proximo->proximo;
        }
    }

    // Libera a memória do nó removido
    if (noRemovido != NULL) {
        free(noRemovido);
        printf("A música \"%s\" foi removida da playlist.\n", tituloMusica);
    } else {
        printf("A música \"%s\" não foi encontrada na playlist.\n", tituloMusica);
    }
}

// Função principal
int main() {
    No* playlist = NULL; // Inicializa a playlist como vazia

    // Inserção de músicas na playlist
    Musica musica1 = { "Música 1", "Banda 1", 180 };
    inserirMusica(&playlist, musica1);

    Musica musica2 = { "Música 2", "Banda 2", 240 };
    inserirMusica(&playlist, musica2);

    Musica musica3 = { "Música 3", "Banda 3", 300 };
    inserirMusica(&playlist, musica3);

    // Impressão da playlist
    imprimirPlaylist(playlist);

    // Remoção de uma música da playlist
    removerMusica(&playlist, "Música 2");

    // Impressão da playlist após remoção
    imprimirPlaylist(playlist);

    // Libera a memória ocupada pela playlist
    while (playlist != NULL) {
        No* noRemovido = playlist;
        playlist = playlist->proximo;
        free(noRemovido);
    }

    return 0;
}
