#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"

void listar_generos() {
    printf("\nGeneros disponiveis:\n");
    printf("A - Acao\n");
    printf("C - Comedia\n");
    printf("D - Drama\n");
    printf("F - Ficcao Cientifica\n");
    printf("T - Terror\n");
    printf("R - Romance\n");
    printf("M - Misterio\n");
    printf("V - Animacao\n");
    printf("O - Documentario\n");
}

// Exibe o menu principal do sistema
void menu_principal() {
    printf("=== SISTEMA NETFLIX! ===\n");
    printf("\n -- Escolha uma opção! -- \n");
    printf("1. Cadastrar usuario\n");
    printf("2. Remover usuario\n");
    printf("3. Buscar usuario\n");
    printf("4. Listar todos os usuarios\n");
    printf("5. Adicionar serie a usuario\n");
    printf("6. Remover serie de usuario\n");
    printf("7. Listar series de usuario\n");
    printf("8. Favoritar serie (dar nota 5)\n");
    printf("9. Relatorio - Series melhor avaliadas\n");
    printf("10. Relatorio - Series pior avaliadas\n");
    printf("11. Estatisticas gerais\n");
    printf("0. Sair\n\n");
}

char obter_genero_valido() {
    char generos_validos[] = "ACDFTRMVO";
    char genero;

    while (1) {
        printf("Digite o genero (A/C/D/F/T/R/M/V/O): ");
        scanf(" %c", &genero);
        fflush(stdin);
        // Converte o caractere para maiúsculo para facilitar a comparação
        genero = toupper(genero);
        // Verifica se o gênero digitado é válido
        for (int i = 0; i < strlen(generos_validos); i++) { // Percorre a string de gêneros válidos
            if (genero == generos_validos[i]) {
                return genero;
            }
        }
        printf("Genero invalido! Tente novamente.\n");
        listar_generos();
    }
}
