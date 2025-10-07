#include "../Lista/lista.h"
#ifndef SERIE_H
#define SERIE_H


int adicionar_serie_usuario(Usuario *lista);
int remover_serie_usuario(Usuario *lista);
void listar_series_usuario_especifico(Usuario *lista);
void favoritar_serie(Usuario *lista);
int serie_existe(Usuario usuario, const char *nome_serie);

#endif //SERIE_H
