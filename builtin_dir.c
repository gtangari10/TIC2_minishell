#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int print_files_in_directory(char *path);

int builtin_dir (int argc, char ** argv){

    char *directory;
    if (argc == 1){
        directory = getenv("PWD");
        return print_files_in_directory(directory);
    }
    if(argc == 2){
        // primero tengo que fijarme si es el nombre de algún otro dir

        directory = getenv("PWD");
        // sino me fijo que archivos contienen ese str y los imprimo
        return print_files_with_strstr_in_directory(directory, argv[1]);

    }

    return 0;
}


int print_files_in_directory(char *path){
    printf("%s", path);
    
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
            result = strstr(str, entry->d_name);
            if (result != NULL){
                printf("%s\n", entry->d_name);
                printf("HOLAAAAAA\n", entry->d_name);

            }
        }
    }

    closedir(dir);
    return 0;
}


// dir [texto/directorio] – Simula una ejecución simplificada del comando ls -l. Sin
// argumentos muestra la lista de archivos del directorio corriente). Con un único
// argumento, será un texto que:
// o si corresponde a un directorio existente, muestra la lista de todos los archivos de
// ese directorio
// o si no es un directorio, muestra todos los archivos cuyo nombre contenga ese
// texto.
// Con dos argumentos, el funcionamiento es la fusión de los dos casos anteriores: el
// primer argumento debe ser un directorio (si no, es un error) y el segundo es el texto de
// filtro