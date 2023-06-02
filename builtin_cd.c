#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"

int change_path(char* argument);
void truncate_path(char* path);

int builtin_cd (int argc, char ** argv){
    //Primero hace el control de cantidad de argumentos, si hay solo uno, devuelve 0 y termina
    //Si hay 2, llama a change_path
    if (argc == 1){
        return 0;
    } else if (argc == 2){
        return change_path(argv[1]);
    } else {
        fprintf(stderr, "cd: argumentos incorrectos. help cd para ayuda\n");
        return 1;
    }
    return 0;
}

int change_path(char *argument){
    //Cambia el path

    // Si hay .., saca lo que viene despues de la ultima /
    // Si empieza con /, el argument es el path entero
    // Si no, concatena el path actual con el argument
    char path_from[MAXCWD];

    getcwd(path_from, MAXCWD);
    
    if (strcmp(argument, "..") == 0){
        truncate_path(path_from);
    } else if (argument[0] == '/'){
        strcpy(path_from, argument);
    } else {
        strcat(path_from, "/");
        strcat(path_from, argument);
    }

    if (chdir(path_from) != 0){
        fprintf(stderr, "%s: El directorio ingresado no existe\n", argument);
        return 1;
    }
    setenv("PWD", path_from, 1);

    return 0;
}

void truncate_path(char *path){
    //Trunca el path en la primer /, si no hay / es porque esta en el primer nivel
    // y no hace nada
    char *last_char =strrchr(path, '/');
    *last_char = '\0';
}