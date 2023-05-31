#include <stdio.h> 
#include <stdlib.h>

int builtin_setenv (int argc, char ** argv){
    if (argc != 3){
        fprintf(stderr, "setenv debe tener solo dos argumentos: variable y valor.\n");
        return 1;
    }
    return setenv(argv[1], argv[2], 1);    
}