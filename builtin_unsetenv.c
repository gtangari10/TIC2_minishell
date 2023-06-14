#include <stdio.h> 
#include <stdlib.h>


// Elimina variables de ambiente pasadas como parámetro. 

int builtin_unsetenv (int argc, char ** argv){
    for (int i = 1; i<argc; i++){
        unsetenv(argv[i]);
        fprintf(stderr, "%s unset \n", argv[i]);
    }
    return 0;
}