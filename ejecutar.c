#include <stdio.h> 
#include <string.h>
#include "minish.h"


/*
int ejecutar (int argc, char ** argv){
    for(int i=0; builtin_arr[i].cmd != NULL; i++){
        if(strcmp(argv[0], builtin_arr[i].cmd) == 0){
            return (builtin_arr[i].func)(argc, argv);
        }

    }
    //return externo;
    return 0;
}
*/


int ejecutar(int argc, char **argv){
    struct builtin_struct * elem = builtin_lookup(argv[0]);
    if(elem != NULL){
        return (elem->func)(argc, argv);
    }

    //return externo;
    return 0;

}