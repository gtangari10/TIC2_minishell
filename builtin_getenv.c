#include <stdio.h> 
#include <stdlib.h>

char extern **environ;

int all_env_variables();
int print_variables(int argc, char **argv);


int builtin_getenv (int argc, char **argv){
    // Specify the name of the environment variable you want to retrieve
    if (argc == 1){
        return all_env_variables();
    } else {
        return print_variables(argc, argv);
    }
    return 0;
}


int all_env_variables(){
    char **env = environ;

    // Iterate through each environment variable until NULL is encountered
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}

int print_variables(int argc, char **argv){
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

