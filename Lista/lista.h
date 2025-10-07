#ifndef LISTA_H
#define LISTA_H
#define MAX_NOME_DO_USUARIO 100
#define ID_MAX 10000
#define MAX_NOME_DA_SERIE 200
#define MAX_DE_COMENTARIOS 500

typedef struct serie {
    char nome_da_serie[MAX_NOME_DA_SERIE];
    char genero;
    short int nota;
    char comentario[MAX_DE_COMENTARIOS];
    struct serie *proxima;
    struct serie *anterior;
} Serie;

typedef struct usuario {
    int ID;
    char nome_do_usuario[MAX_NOME_DO_USUARIO];
    Serie *series;
    int num_series;
    struct usuario *proximo;
    struct usuario *anterior;
} Usuario;


void listar_generos();
char obter_genero_valido();
void menu_principal();

#endif