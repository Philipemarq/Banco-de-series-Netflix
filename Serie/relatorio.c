#include <stdio.h>
#include "relatorio.h"
#include "../Lista/lista.h"


void relatorio_series_melhores_avaliacoes(Usuario *lista) {
    if (lista == NULL) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    printf("\n=== SERIES MELHOR AVALIADAS (Nota 5) ===\n");

    Usuario *atual = lista;
    int encontradas = 0;

    // Itera sobre todos os usuários na lista
    while (atual != NULL) {
        Serie *serie_atual = atual->series; // usa um ponteiro auxiliar para iterar sobre as séries do usuário
        // Itera sobre todas as séries do usuário atual
        while (serie_atual != NULL) {
            if (serie_atual->nota == 5) {
                printf("Serie: %s\n", serie_atual->nome_da_serie);
                printf("Usuario: %s, Genero: %c\n", atual->nome_do_usuario, serie_atual->genero);
                printf("Comentario: %s\n", serie_atual->comentario);
                printf("---\n");
                encontradas++;
            }
            serie_atual = serie_atual->proxima;
        }
        atual = atual->proximo;
    }
    // Se nenhuma série com nota 5 foi encontrada
    if (encontradas == 0) {
        printf("Nenhuma serie com nota 5 encontrada.\n");
    } else {
        printf("Total de séries com nota 5: %d\n", encontradas);
        printf("---\n");
    }
}

void relatorio_series_piores_avaliacoes(Usuario *lista) {
    if (lista == NULL) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    printf("\n=== SERIES PIOR AVALIADAS (Nota 0-1) ===\n");
    int encontradas = 0;
    Usuario *atual = lista;
    // Itera sobre todos os usuários na lista
    while (atual != NULL) {
        Serie *serie_atual = atual->series; // usa um ponteiro auxiliar para iterar sobre as séries do usuário
        // Itera sobre todas as séries do usuário atual
        while (serie_atual != NULL) {
            if (serie_atual->nota <= 1) {
                printf("Serie: %s\n", serie_atual->nome_da_serie);
                printf("Usuario: %s, Nota: %d/5, Genero: %c\n",
                       atual->nome_do_usuario, serie_atual->nota, serie_atual->genero);
                printf("Comentario: %s\n", serie_atual->comentario);
                printf("---\n");
                encontradas++;
            }
            serie_atual = serie_atual->proxima;
        }
        atual = atual->proximo;
    }
    if (encontradas == 0) {
        printf("Nenhuma série com nota baixa encontrada.\n");
    } else {
        printf("Total de séries com nota 0: %d\n", encontradas);
        printf("---\n");
    }
}

void relatorio_estatisticas_usuarios(Usuario *lista) {
    if (lista == NULL) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    int total_usuarios = 0;
    int total_series = 0;
    int series_nota5 = 0;
    int series_nota0 = 0;

    Usuario *atual = lista;
    // Itera sobre todos os usuários na lista
    while (atual != NULL) {
        Serie *serie_atual = atual->series; // usa um ponteiro auxiliar para iterar sobre as séries do usuário
        // Itera sobre todas as séries do usuário atual
        while (serie_atual != NULL) {
            if (serie_atual->nota == 5) series_nota5++;
            if (serie_atual->nota == 0) series_nota0++;
            total_series++;
            serie_atual = serie_atual->proxima;
        }
        total_usuarios++;
        atual = atual->proximo;
    }

    printf("\n=== ESTATISTICAS ===\n");
    printf("Total de usuarios: %d\n", total_usuarios);
    printf("Total de series avaliadas: %d\n", total_series);
    printf("Series com nota 5: %d\n", series_nota5);
    printf("Series com nota 0: %d\n", series_nota0);
}