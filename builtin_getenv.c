#include <stdio.h> 
#include <stdlib.h>

int builtin_getenv (int argc, char ** argv){
    // Specify the name of the environment variable you want to retrieve
    char *variable_name;
    char *variable_value;
    for (int i = 1; i<argc; i++){
        variable_name = argv[i];
        variable_value = getenv(argv[i]);
        if (variable_value != NULL){
            printf("%s=%s \n", variable_name, variable_value);
        }else{
            fprintf(stderr, "No se encuentra ninguna variable de ambiente con nombre: %s", variable_name);
        }
    }


    return 0;
}


