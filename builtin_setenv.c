#include <stdio.h> 
#include <stdlib.h>

// define una variable nueva de ambiente 
// o cambia el valor de una variable de ambiente existente.
// debe tener dos argumentos: variable y valor.

int builtin_setenv (int argc, char ** argv){
    if (argc != 3){
        fprintf(stderr, "setenv debe tener solo dos argumentos: variable y valor.\n");
        return 1;
    }
    return setenv(argv[1], argv[2], 1);    
}