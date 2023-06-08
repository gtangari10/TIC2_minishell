#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "minish.h"

int print_files_in_directory(char *path);
int print_files_with_strstr_in_directory(char* directory, char* string);
int check_directory(char* directory, char* path);
void get_new_path(char* argument, char* path);
extern char* previous_path;

int builtin_dir (int argc, char ** argv){

    char *directory;
    if (argc == 1){
        directory = getenv("PWD");
        return print_files_in_directory(directory);
    }
    else if(argc == 2){
        char path[MAXCWD];
        get_new_path(argv[1], path);
        int result = print_files_in_directory(path);

        if (result == 0) return 0;

        directory = getenv("PWD");
        // sino me fijo que archivos contienen ese str y los imprimo
        return print_files_with_strstr_in_directory(directory, argv[1]);
    }
    else if(argc == 3){
        char path[MAXCWD];
        get_new_path(argv[1], path);
        return print_files_with_strstr_in_directory(path, argv[2]);
    }
    else {
        fprintf(stderr, "dir acepta uno o dos argumentos, consultar help para ver el uso.\n");
    }

    return 0;
}

int check_directory(char* directory, char* path){
    get_new_path(directory, path);
    DIR *dir = opendir(path);
    if (dir != NULL) {
        closedir(dir);
        return 0; // Valid directory
    }
    return 1; // Not a directory or does not exist
}

int print_files_in_directory(char *path){
    DIR * dir = opendir(path);

    if (dir == NULL){
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!(*entry->d_name == '.')){
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}

int print_files_with_strstr_in_directory(char *path, char *str){
    // printf("%s", str);
    DIR * dir = opendir(path);

    if (dir == NULL){
        return 1;
    }

    char *result;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!(*entry->d_name == '.')){
            result = strstr(entry->d_name, str);
            if (result != NULL){
                printf("%s\n", entry->d_name);
            }
        }
    }

    closedir(dir);
    return 0;
}

static void truncate_path(char *path){
    //Trunca el path en la primer /, si no hay / es porque esta en el primer nivel
    // y no hace nada
    char *last_char =strrchr(path, '/');
    *last_char = '\0';
}

void get_new_path(char *argument, char *path){
    //Cambia el path

    // Si hay .., saca lo que viene despues de la ultima /
    // Si empieza con /, el argument es el path entero
    // Si es -, vuelve al previous path
    // Si no, concatena el path actual con el argument

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
}

