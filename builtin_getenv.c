#include <stdio.h> 
#include <stdlib.h>

extern char **environ;

static int all_env_variables();
static int print_variables(int argc, char **argv);


int builtin_getenv (int argc, char **argv){
    // Devuelve los valores de las variables de ambiente pasadas por los argumentos
    if (argc == 1){
        return all_env_variables();
    } else {
        return print_variables(argc, argv);
    }
    return 0;
}


static int all_env_variables(){
    char **env = environ;

    // Recorre todas las variables de ambientes hasta que haya alguna con NULL
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}

static int print_variables(int argc, char **argv){
    char *variable_name;
    char *variable_value;
    for (int i = 1; i<argc; i++){
        variable_name = argv[i];
        variable_value = getenv(argv[i]);
        if (variable_value != NULL){
            fprintf(stderr, "%s=%s \n", variable_name, variable_value);
        }else{
            fprintf(stderr, "No se encuentra ninguna variable de ambiente con nombre: %s \n", variable_name);
            return 1;
        }
    }
    return 0;
}

