#include <stdio.h> 
#include <string.h>
#include "minish.h"

// Consulta si cmd es efectivamente un builtin.
// Si es así, retorna un puntero a esa estructura.
// Si no, retorna NULL.

struct builtin_struct * builtin_lookup(char *cmd){
    for(int i=0; builtin_arr[i].cmd != NULL; i++){
        if(strcmp(cmd, builtin_arr[i].cmd) == 0){
            return &builtin_arr[i];
        }

    }
    return NULL;
}