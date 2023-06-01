#include <stdio.h> 
#include "minish.h"


int builtin_help (int argc, char ** argv){
    // Si está vacío, imprimir los comandos internos
    // Si hay algo después, que tome la primera palabra siguiente y se fije
    // Si hay un comando interno con eso, que haga una pequeña descripción. Se puede usar los del minish para conocer
    // Si no hay un comando interno, escribir No se encontró el comando <comando>

    if(argc == 1){
        fprintf(stderr, "help [");
        for(int i=0; builtin_arr[i].cmd != NULL; i++){
            fprintf(stderr,"%s|", builtin_arr[i].cmd);
        }
        fprintf(stderr,"]\n");
        return 0;

    }

    struct builtin_struct * aux = builtin_lookup(argv[1]);
    if(aux != NULL){
        fprintf(stderr, "%s\n", aux->help_txt);
    }
    else{
        fprintf(stderr, "No se encontró comando <%s>\n", argv[1]);
        return 1;
    }

    return 0;
}