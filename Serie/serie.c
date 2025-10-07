#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serie.h"
#include "../Lista/lista.h"
#include "../Usuario/usuario.h"

int adicionar_serie_usuario(Usuario *lista) {
    // Busca o usuario pelo nome e guarda na variavel usuario
    Usuario *usuario = buscar_usuario_por_nome(lista);
    if (usuario == NULL) {
        return 0;
    }

    char nome_serie[MAX_NOME_DA_SERIE];
    char comentario[MAX_DE_COMENTARIOS];
    short int nota;

    printf("Digite o nome da serie: ");
    scanf("%s", nome_serie);
    nome_serie[strcspn(nome_serie, "\n")] = 0; // Remove o '\n' do final da string

    // Verifica se a série já existe para o usuario
    if (serie_existe(*usuario, nome_serie)) {
        printf("Serie ja existe para este Usuario!\n");
        return 0;
    }

    // Limpa o buffer
    while (getchar() != '\n');

    // Lista os gêneros disponíveis e verifica o gênero digitado
    listar_generos();
    char genero = obter_genero_valido();

    printf("Digite a nota (0-5): ");
    if (scanf("%hd", &nota) != 1) {
        printf("Nota invalida!\n");
        return 0;
    }

    // Formata a entrada da nota para garantir que esteja entre 0 e 5
    if (nota < 0) nota = 0;
    if (nota > 5) nota = 5;

    // Limpa o buffer
    while (getchar() != '\n');

    printf("Digite o comentario: ");
    scanf(" %[^\n]", comentario); // Lê o comentário com espaços
    comentario[strcspn(comentario, "\n")] = 0; // Remove o "\n" do final da string

    Serie *novaSerie = malloc(sizeof(Serie));

    if (novaSerie == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 0;
    }
    // Limpa o buffer
    while (getchar() != '\n');

    strcpy(novaSerie->nome_da_serie, nome_serie);
    novaSerie->genero = genero;
    novaSerie->nota = nota;
    strcpy(novaSerie->comentario, comentario);
    novaSerie->proxima = NULL;
    novaSerie->anterior = NULL;
    // Adiciona a nova série ao final da lista de séries do usuário
    if (usuario->series == NULL) {
        usuario->series = novaSerie;
    } else {
        printf("%s", usuario->series->nome_da_serie);
        Serie *atual = usuario->series;
        while (atual->proxima != NULL) {
            atual = atual->proxima;
        }
        atual->proxima = novaSerie;
        novaSerie->anterior = atual;
    }

    usuario->num_series++;
    printf("Serie adicionada com sucesso!\n");
    return 1;
}


int remover_serie_usuario(Usuario *lista) {
    // Busca o usuario pelo nome e guarda na variavel usuario
    Usuario *usuario = buscar_usuario_por_nome(lista);
    if (usuario == NULL) { // Se o usuario não for encontrado, retorna 0
        return 0;
    }
    // Verifica se o usuario possui séries cadastradas
    if (usuario->num_series == 0) {
        printf("Usuario nao possui series.\n");
        return 0;
    }

    char nome_serie[MAX_NOME_DA_SERIE];
    printf("Digite o nome da serie a remover: ");
    scanf(" %[^\n]", nome_serie); // Lê o nome da série com espaços
    nome_serie[strcspn(nome_serie, "\n")] = 0; // Remove o '\n' do final da string
    // Limpa o buffer após leitura válida
    while (getchar() != '\n');

    // Procura a série pelo nome
    Serie *atual = usuario->series;
    while (atual != NULL) {
        if (strcasecmp(atual->nome_da_serie, nome_serie) == 0) {
            // Ajusta os ponteiros para remover a série da lista
            if (atual->anterior != NULL) {
                atual->anterior->proxima = atual->proxima;
            } else {
                usuario->series = atual->proxima; // Se for a primeira série
            }
            if (atual->proxima != NULL) {
                atual->proxima->anterior = atual->anterior;
            }
            free(atual); // Libera a memória da série removida
            usuario->num_series--;
            // Se não houver mais séries, libera o ponteiro
            if (usuario->num_series == 0) {
                usuario->series = NULL;
            }
            printf("Serie removida com sucesso!\n");
            return 1;
        }
        atual = atual->proxima;
    }
    printf("Serie nao foi encontrada.\n");
    return 0;
}

void listar_series_usuario_especifico(Usuario *lista) {
    Usuario *usuario = buscar_usuario_por_nome(lista);
    if (usuario == NULL) {
        return;
    }

    printf("\n=== SERIES DE %s ===\n", usuario->nome_do_usuario);
    if (usuario->num_series == 0) {
        printf("Nenhuma serie cadastrada.\n");
        return;
    }
    Serie *atual = usuario->series;
    // Itera sobre todas as séries do usuário atual
    while (atual != NULL) {
        printf("Serie: %s\n", atual->nome_da_serie);
        printf("Genero: %c\n", atual->genero);
        printf("Nota: %d/5\n", atual->nota);
        printf("Comentario: %s\n", atual->comentario);
        printf("---\n");
        atual = atual->proxima;
    }
}

void favoritar_serie(Usuario *lista) {
    Usuario *usuario = buscar_usuario_por_nome(lista);
    if (usuario == NULL) {
        return;
    }

    if (usuario->num_series == 0) {
        printf("Usuario nao possui series.\n");
        return;
    }

    char nome_serie[MAX_NOME_DA_SERIE];

    printf("Digite o nome da serie para favoritar (dar nota 5): ");
    scanf(" %[^\n]", nome_serie); // Lê o nome da série com espaços
    nome_serie[strcspn(nome_serie, "\n")] = 0; // Remove o '\n' do final da string

    Serie *atual = usuario->series;
    // Procura a série pelo nome
    while (atual != NULL) {
        if (strcasecmp(atual->nome_da_serie, nome_serie) == 0) { // Compara ignorando maiúsculas/minúsculas
            atual->nota = 5;
            printf("Essa série '%s' favoritada com sucesso! (Nota 5)\n", nome_serie);
            // Limpa o buffer
            while (getchar() != '\n');
            return;
        }
        atual = atual->proxima;
    }
    // Limpa o buffer
    while (getchar() != '\n');

    printf("Série nao foi encontrada.\n");
}

int serie_existe(Usuario usuario, const char *nome_serie) {
    while (usuario.series != NULL) {
        if (strcasecmp(usuario.series->nome_da_serie, nome_serie) == 0) {
            return 1; // Série encontrada
        }
        usuario.series = usuario.series->anterior;
    }
    return 0; // Série não encontrada
}