#include <stdio.h> 
#include <stdlib.h>
#include "minish.h"
#include <string.h>

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


int globalstatret;

int main(){

    //FILE *fp; //Comentado para que no de warning
    char line[MAXLINE];
    int argc = MAXWORDS;
    char *argv[MAXWORDS];
    globalstatret = 0; 

    char * name = getenv("USER"); //gets user name
    char * path = getenv("PWD"); //gets user path

    fprintf(stderr, "(minish) (%s):%s> ", name, path);
    while(1){



        if(fgets(line, MAXLINE, stdin) != NULL && strcmp(line, "\n") != 0){
            //fprintf(stderr, "%s", line);
            argc = linea2argv(line, MAXWORDS, argv); //updates the value of argc

            //Tests argv
            
            // for(int i = 0; i < argc; i++){
            //     fprintf(stderr,"%s\n", argv[i]);
            // }
            
            globalstatret = ejecutar(argc, argv); //updates return_status


        }
        fprintf(stderr, "(minish) (%s):%s> ", name, path);
    }

} 