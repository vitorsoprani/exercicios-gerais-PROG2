#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "utils.h"

#define DEBUG 1

Usuario* CriaUsuario(char* nome, int cpf) {
    Usuario* usuario = (Usuario*)malloc(sizeof(Usuario));

#if DEBUG
    if (usuario == NULL)
        ERRO("CriaUsuario(usuario.c)", "Nao foi possivel alocar o struct usuario");
#endif

    usuario->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));

#if DEBUG
    if (usuario == NULL)
        ERRO("CriaUsuario(usuario.c)", "Nao foi possivel alocar o atributo 'nome' no struct usuario");
#endif
    strcpy(usuario->nome, nome);

    usuario->cpf = cpf;

    return usuario;
}

char* RecuperaNomeUsuario(Usuario* usuario) {
#if DEBUG
    if (usuario == NULL)
        ERRO("RecuperaNomeUsuario(usuario.c)", "Foi passado um ponteiro NULL como parametro (usuario)");
#endif

    return usuario->nome;
}

int RecuperaCpfUsuario(Usuario* usuario) {
#if DEBUG
    if (usuario == NULL)
        ERRO("RecuperaCpfUsuario(usuario.c)", "Foi passado um ponteiro NULL como parametro (usuario)");
#endif

    return usuario->cpf;
}

void DestroiUsuario(Usuario* usuario) {
    if (usuario != NULL) {
        if (usuario->nome != NULL)
            free(usuario->nome);
        free(usuario);
    }
}