#include <stdio.h>
#include "minish.h"

//No lleva parametros.
//Muestra el status de retorno del último comando ejecutado.

int builtin_status (int argc, char ** argv){
    fprintf(stderr, "%d\n",globalstatret);
    return 0;
}