#include <stdio.h> 
#include <stdlib.h>
#include "minish.h"
#include <string.h>


#define MAXLINE 1024
#define MAXWORD 256

#define HELP_CD      "cd [..|dir] - cambia de directorio corriente"
#define HELP_DIR     "dir [str]- muestra archivos en directorio corriente, que tengan 'str'"
#define HELP_EXIT    "exit [status] - finaliza el minish con un status de retorno (por defecto 0)"
#define HELP_HELP    "help [cd|dir|exit|help|history|getenv|pid|setenv|status|uid]"
#define HELP_HISTORY "history [N] - muestra los últimos N (10) comandos escritos"
#define HELP_GETENV  "getenv var [var] - muestra valor de variable(s) de ambiente"
#define HELP_PID     "pid - muestra Process Id del minish"
#define HELP_SETENV  "setenv var valor - agrega o cambia valor de variable de ambiente"
#define HELP_STATUS  "status - muestra status de retorno de ultimo comando ejecutado"
#define HELP_UID     "uid - muestra nombre y número de usuario dueño del minish"
#define HELP_GID    " - "
#define HELP_UNSETENV " - "



/*
//Esto creo que es mejor idea tenerlo en el ejecutar
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


int main(){

    char *line;

    while(fgets(line, MAXLINE, stdin) != NULL){
        
    }
    return 0;

}

*/

int main(){

    //FILE *fp; //Comentado para que no de warning
    char line[MAXLINE];
    int argc = MAXWORD;
    char *argv[MAXWORD];
    //int return_status = 0; //comentado para que no de warnings

    fprintf(stderr, "(minish)$ ");
    while(1){

        if(fgets(line, MAXLINE, stdin) != NULL && strcmp(line, "\n") != 0){
            fprintf(stderr, "%s", line);
            argc = linea2argv(line, argc, argv); //updates the value of argc
            //return_status = ejecutar(argc, argv); //updates return_status


        }
        fprintf(stderr, "(minish)$ ");        
    }

} 