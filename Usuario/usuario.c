#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Lista/lista.h"

Usuario* criar_lista() {
    return NULL; // Inicializa a lista como vazia
}

void liberar_lista(Usuario **lista) {
    Usuario *atual = *lista;
    Usuario *proximo;

    // Percorre a lista e libera a memória de cada usuário e suas séries
    while (atual != NULL) {
        proximo = atual->proximo;
        // Libera a memória alocada para as séries do usuário, se houver
        if (atual->series != NULL) {
            free(atual->series);
        }
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}

int gerar_id_unico(Usuario *lista) {
    int id;
    Usuario *atual;
    int id_unico;
    // Gera IDs aleatórios até encontrar um que não esteja na lista
    do {
        id_unico = 1;
        id = rand() % ID_MAX + 1;

        atual = lista;
        // Percorre a lista para verificar se o ID já existe
        while (atual != NULL) {
            if (atual->ID == id) {
                id_unico = 0;
                break;
            }
            atual = atual->proximo;
        }
    } while (!id_unico);

    return id;
}

int cadastrar_usuario(Usuario **lista) {
    char nome[MAX_NOME_DO_USUARIO];

    printf("Digite o nome do usuario:");
    fgets(nome, sizeof(nome), stdin);
    // Remove o '\n' do final, se presente
    nome[strcspn(nome, "\n")] = 0;

    if (strlen(nome) <= 1) { // Verifica se o nome é vazio ou só contém '\n'
        printf("Nome invalido!\n");
        return 0;
    }

    Usuario *novo = malloc(sizeof(Usuario)); // Aloca memória para o novo usuário

    // Verifica se a alocação foi bem-sucedida
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 0;
    }
    // Inicializa os campos do novo usuário
    novo->ID = gerar_id_unico(*lista);
    strcpy(novo->nome_do_usuario, nome);
    novo->series = NULL;
    novo->num_series = 0;
    novo->proximo = NULL;

    // Insererção se a lista estiver vazia
    if (*lista == NULL) {
        novo->anterior = NULL;
        *lista = novo;
        printf("Usuario foi cadastrado com sucesso! ID: %d\n", novo->ID);
        return 1;
    }

    Usuario *atual = *lista;
    Usuario *anterior = NULL;

    // Encontra a posição correta para inserir o novo usuário em ordem alfabética
    while (atual != NULL && strcasecmp(atual->nome_do_usuario, nome) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Ajusta os ponteiros para inserir o novo usuário na lista
    if (anterior == NULL) { // Inserir no inicio
        novo->proximo = *lista;
        (*lista)->anterior = novo;
        *lista = novo;
    } else if (atual == NULL) { // Insere no final
        anterior->proximo = novo;
        novo->anterior = anterior;
    } else { //Insere no meio
        anterior->proximo = novo;
        novo->anterior = anterior;
        novo->proximo = atual;
        atual->anterior = novo;
    }

    printf("Usuario foi cadastrado com sucesso! ID: %d\n", novo->ID);
    return 1;
}

int remover_usuario_por_id(Usuario **lista) {
    int id;

    printf("Digite o ID do usuario a remover: ");
    // Lê o ID e verifica se a entrada é válida
    if (scanf("%d", &id) != 1) {
        printf("ID invalido!\n");
        return 0;
    }

    Usuario *atual = *lista;
    // Percorre a lista para encontrar o usuário com o ID especificado
    while (atual != NULL) {
        if (atual->ID == id) {
            // Se o usuário não for o primeiro da lista
            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
            } else {
                *lista = atual->proximo;
            }
            // Se o usuário não for o último da lista
            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior;
            }
            // Libera a memória alocada para as séries do usuário, se houver
            if (atual->series != NULL) {
                free(atual->series);
            }

            free(atual);
            printf("Usuario foi removido com sucesso!\n");
            return 1;
        }
        atual = atual->proximo;
    }

    printf("Usuario não foi encontrado.\n");
    return 0;
}

Usuario* buscar_usuario_por_nome(Usuario *lista) {
    char nome[MAX_NOME_DO_USUARIO];

    printf("Digite o nome do usuario: ");
    fgets(nome, sizeof(nome), stdin);
    if (strlen(nome) <= 1) { // Verifica se o nome é vazio ou só contém '\n'
        printf("Nome invalido!\n");
        return NULL;
    }
    // Remove o '\n' do final, se presente
    nome[strcspn(nome, "\n")] = 0;

    Usuario *atual = lista;
    // Percorre a lista para encontrar o usuário com o nome especificado
    while (atual != NULL) {
        // Se o nome for igual, usuario encontrado
        if (strcasecmp(atual->nome_do_usuario, nome) == 0) {
            printf("Usuario encontrado: ID %d, Nome: %s\n",
                   atual->ID, atual->nome_do_usuario);
            return atual;
        }
        atual = atual->proximo; // Avança para o próximo usuário
    }

    printf("Usuario nao encontrado.\n");
    return NULL;
}

void listar_todos_usuarios(Usuario *lista) {
    Usuario *atual = lista;

    printf("\n=== LISTA DE USUARIOS ===\n");
    // Verifica se a lista está vazia
    if (atual == NULL) {
        printf("Nenhum usuario foi cadastrado!!\n");
        return;
    }
    // Percorre a lista e imprime os detalhes de cada usuário
    while (atual != NULL) {
        printf("ID: %d, Nome: %s, Series: %d\n",
               atual->ID, atual->nome_do_usuario, atual->num_series);
        atual = atual->proximo;
    }
}