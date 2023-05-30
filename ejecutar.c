#include <stdio.h> 
#include <string.h>
#include "minish.h"


struct builtin_struct builtin_arr[] = {
        { "cd", builtin_cd, HELP_CD },
        { "dir", builtin_dir, HELP_DIR},
        { "exit", builtin_exit, HELP_EXIT},
        { "help", builtin_help, HELP_HELP},
        { "history", builtin_history, HELP_HISTORY},
        { "getenv", builtin_getenv, HELP_GETENV},
        { "pid", builtin_pid, HELP_PID},
        { "setenv", builtin_setenv, HELP_SETENV},
        { "status", builtin_status, HELP_STATUS},
        { "gid", builtin_gid, HELP_GID},
        { "unsetenv", builtin_unsetenv, HELP_UNSETENV},
        { "uid", builtin_uid, HELP_UID },
        { NULL, NULL, NULL }
    };

//No hay nada testeado :D
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