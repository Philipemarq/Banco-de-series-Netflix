#include "../Lista/lista.h"
#ifndef USUARIO_H
#define USUARIO_H


Usuario* criar_lista();
void liberar_lista(Usuario **lista);
int gerar_id_unico(Usuario *lista);

int cadastrar_usuario(Usuario **lista);
int remover_usuario_por_id(Usuario **lista);
Usuario* buscar_usuario_por_nome(Usuario *lista);
void listar_todos_usuarios(Usuario *lista);

#endif //USUARIO_H
