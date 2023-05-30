#include <stdio.h> 
#include "minish.h"

#define HELP_CD "Esto es provisorio"
#define HELP_DIR "Esto es provisorio"
#define HELP_EXIT "Esto es provisorio"
#define HELP_HELP "Esto es provisorio"
#define HELP_HISTORY "Esto es provisorio"
#define HELP_GETENV "Esto es provisorio"
#define HELP_PID "Esto es provisorio"
#define HELP_SETENV "Esto es provisorio"
#define HELP_STATUS "Esto es provisorio"
#define HELP_GID "Esto es provisorio"
#define HELP_UNSETENV "Esto es provisorio"
#define HELP_UID "Esto es provisorio"


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
    for(int i=0; builtin_arr[i].cmd != NULL; i++){
        if(strcmp(argv[0], builtin_arr[i].cmd) == 0){
            return builtin_arr[i].func;
        }

    }
    return externo;
}