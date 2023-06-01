#include <stdio.h> 
#include <stdlib.h>
#include "minish.h"

int builtin_exit (int argc, char ** argv){
    // termina el shell, admite un parámetro que es el status de retorno. 
    //Sin ningún parámetro, usa como status de retorno el del último comando ejecutado.
    int status = globalstatret;

    if (argc == 1){
        exit(status);
    }
    else {
        // Se fija que el argumento sea un numero
        char *endptr;
        int value = strtol(argv[1], &endptr, 10);
        if (*endptr == '\0') {
            exit(value);
        } else {
            exit(status);
        }
    }
}