#include <stdio.h> 
#include <string.h>
#include "minish.h"



int ejecutar (int argc, char ** argv){
    //fprintf(stderr, "Entre a ejecutar");
    //fprintf(stderr, "%s", argv[0]);
    for(int i=0; builtin_arr[i].cmd != NULL; i++){
        //fprintf(stderr, "'%s'\n", builtin_arr[i].cmd);
        //fprintf(stderr, "'%s'\n", argv[0]);
        if(strcmp(argv[0], builtin_arr[i].cmd) == 0){
            //fprintf(stderr, "entre al if");
            return (builtin_arr[i].func)(argc, argv);
        }

    }
    //return externo;
    return 0;
}