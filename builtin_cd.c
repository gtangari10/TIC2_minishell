#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"

int change_path(char* argument);
int go_home();
void truncate_path(char* path);
extern char *previous_path;

int builtin_cd (int argc, char ** argv){
    //Primero hace el control de cantidad de argumentos, si hay solo uno, devuelve 0 y termina
    //Si hay 2, llama a change_path
    if (argc == 1){
        return go_home();
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
    // Si es -, vuelve al previous path
    // Si no, concatena el path actual con el argument
    char path[MAXCWD];
    
    if (strcmp(argument, "..") == 0){
        getcwd(path, MAXCWD);
        truncate_path(path);
    }
    else if (argument[0] == '/'){
        strcpy(path, argument);
    }
    else if (strcmp(argument, "-") == 0){
        strcpy(path, previous_path);
    } 
    else {
        getcwd(path, MAXCWD);
        strcat(path, "/");
        strcat(path, argument);
    }

    if (chdir(path) != 0){
        fprintf(stderr, "%s: El directorio ingresado no existe\n", argument);
        return 1;
    } else {
        previous_path = getenv("PWD");
        setenv("PWD", path, 1);
    }
    return 0;
}

int go_home(){
    char *path;
    path = getenv("HOME");
    if (chdir(path) != 0){
        fprintf(stderr, "No se puede volver a HOME\n");
        return 1;
    } else{
        previous_path = getenv("PWD");
        setenv("PWD", path, 1);
    }
    return 0;
}

void truncate_path(char *path){
    //Trunca el path en la primer /, si no hay / es porque esta en el primer nivel
    // y no hace nada
    char *last_char =strrchr(path, '/');
    *last_char = '\0';
}