#include <stdio.h> 
#include <string.h>
#include "minish.h"

// Decide si es un comando interno, si lo es, lo ejecuta.
// De lo contrario, invoca a externo()

int ejecutar(int argc, char **argv){
    struct builtin_struct * elem = builtin_lookup(argv[0]);
    if(elem != NULL){
        return (elem->func)(argc, argv);
    }

    return externo(argc,argv);

}