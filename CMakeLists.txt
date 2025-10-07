cmake_minimum_required(VERSION 3.30.5)
project(projaed C)

set(CMAKE_C_STANDARD 11)

add_executable(projaed main.c
        Lista/lista.c
        Lista/lista.h
        usuario/usuario.c
        serie/serie.c
        serie/relatorio.c
        serie/serie.h
        usuario/usuario.h
        serie/relatorio.h
)
