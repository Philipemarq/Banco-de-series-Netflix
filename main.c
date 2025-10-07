#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "Usuario/usuario.h"
#include "Lista/lista.h"
#include "Serie/serie.h"
#include "Serie/relatorio.h"

int main() {
    setlocale(LC_ALL, ""); // define a localidade do sistema para o padrao do ambiente
    Usuario *lista = criar_lista();
    printf("Lista inicial: %p\n", (void*)lista);
    int opcao;

    srand(time(NULL)); // Gera semente para números aleatorios
    do {
        menu_principal(); // Exibe o menu

        printf("Digite sua opção: ");
        // lê a opção do usuario e verifica se é válida
        if (scanf("%d", &opcao) != 1) {
            printf("Opção inválida!\n");
            // Limpa o buffer em caso de entrada inválida
            while (getchar() != '\n');
            continue;
        }

        // limpa o buffer após leitura válida
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrar_usuario(&lista); // Chama a função para cadastrar usuário
            break;
            case 2:
                remover_usuario_por_id(&lista); // Chama a função para remover usuário
            break;
            case 3:
                buscar_usuario_por_nome(lista); // Chama a função para buscar usuário
            break;
            case 4:
                listar_todos_usuarios(lista); // Chama a função para listar todos os usuários
            break;
            case 5:
                adicionar_serie_usuario(lista); // Chama a função para adicionar série a usuário
            break;
            case 6:
                remover_serie_usuario(lista); // Chama a função para remover série de usuário
            break;
            case 7:
                listar_series_usuario_especifico(lista); // Chama a função para listar séries de um usuário específico
            break;
            case 8:
                favoritar_serie(lista); // Chama a função para favoritar série
            break;
            case 9:
                relatorio_series_melhores_avaliacoes(lista); // Chama a função para relatar séries melhor avaliadas
            break;
            case 10:
                relatorio_series_piores_avaliacoes(lista); // Chama a função para relatar séries pior avaliadas
            break;
            case 11:
                relatorio_estatisticas_usuarios(lista); // Chama a função para relatar estatísticas gerais
            break;
            case 0:
                printf("Programa encerrado.\n");
            break;
            default:
                printf("Opção inválida!\n");
        }

        if (opcao != 0) {
            printf("\nPressione qualquer tecla para continuar...");
            getchar();
        }

    } while (opcao != 0);

    liberar_lista(&lista);
    return 0;
}
