#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "wrappers.h"
#include "minish.h"
#include "utils.h"

#define HELP_CD      "cd [..|dir] - cambia de directorio corriente"
#define HELP_DIR     "dir [str]- muestra archivos en directorio corriente, que tengan 'str'"
#define HELP_EXIT    "exit [status] - finaliza el minish con un status de retorno (por defecto 0)"
#define HELP_HELP    "help [cd|dir|exit|help|history|getenv|pid|setenv|status|gid|unsetenv|uid]"
#define HELP_HISTORY "history [N] - muestra los últimos N (10) comandos escritos"
#define HELP_GETENV  "getenv var [var] - muestra valor de variable(s) de ambiente"
#define HELP_PID     "pid - muestra Process Id del minish"
#define HELP_SETENV  "setenv var valor - agrega o cambia valor de variable de ambiente"
#define HELP_STATUS  "status - muestra status de retorno de ultimo comando ejecutado"
#define HELP_UID     "uid - muestra nombre y número de usuario dueño del minish"
#define HELP_GID    "gid - muestra el grupo principal y los grupos secundarios del usuario"
#define HELP_UNSETENV "unsetenv - elimina variables de ambiente"

#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define ANSI_COLOR_CYAN     "\e[0;36m"

// Array que almacena todos los builtins. 
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
char *previous_path;
void load_history(struct deq *);
void at_exit();

void handleSignal(int signum) {
    if (signum == 2){
        fprintf(stderr, "Interrupt!\n");
    }
}


struct deq * new_deq;
char * history_path;
int main(){

    new_deq = deq_create(); //creo estructura para insertar archivos
    // Armar la estructura handleSignal
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handleSignal;
    sigemptyset(&sa.sa_mask);

    // Settea la acción para hacer ante un Control-C
    sigaction(SIGINT, &sa, NULL);
    
    //FILE *fp; //Comentado para que no de warning
    char line[MAXLINE];
    int argc = MAXWORDS;
    char *argv[MAXWORDS];
    globalstatret = 0; 

    char * name = getenv("USER"); //gets user name
    char * path = getenv("PWD"); //gets user path
    previous_path = getenv("PWD"); //copies user path again
    
    load_history(new_deq);
    char * hist_argv;

    fprintf(stderr, ANSI_COLOR_GREEN"(minish)" ANSI_COLOR_CYAN " (%s):%s> " ANSI_COLOR_RESET, name, path);
    while(1){
        if(fgets(line, MAXLINE, stdin) != NULL && strcmp(line, "\n") != 0){
            argc = linea2argv(line, MAXWORDS, argv); //updates the value of argc
            if (argc > 0){
                hist_argv = strdup_or_exit(argv[0]);
                strcat(hist_argv, "\n");
                deq_append(new_deq, hist_argv); //mal
                globalstatret = ejecutar(argc, argv); //updates return_status
            }
        }
        if (feof(stdin) != 0){
            fprintf(stderr, "\n");
            at_exit();
            break;
        }
        path = getenv("PWD"); //gets user path
        fprintf(stderr, ANSI_COLOR_GREEN"(minish)" ANSI_COLOR_CYAN " (%s):%s> " ANSI_COLOR_RESET, name, path);

    }

} 

// Esta funcion es parte del history.
void load_history(struct deq * deque){
    FILE *fp;
    history_path = malloc_or_exit(MAXLINE);
    strcpy(history_path, getenv("HOME"));
    char line[MAXCWD];

    strcat(history_path, "/");
    strcat(history_path, HISTORY_FILE);

    if ((fp = fopen_or_exit(history_path, "r")) == NULL){
        perror("No abre la history para leer");
        return;
    }
    
    while (fgets(line, MAXCWD, fp) != NULL) {
        deq_append(deque, line);
    }
    fclose(fp);
}

void at_exit(){
    FILE *fp;
    fprintf(stderr, "%s \n", history_path);

    if ((fp = fopen_or_exit(history_path, "w")) == NULL){
        perror("No se pudo escribir la history");
        return;
    }
    
    struct deq_elem *e = new_deq->leftmost;
    struct deq_elem *next;
    for (int i = 0; i < new_deq->count; i++){
        fprintf(fp, "%s", e->str);
        next = e->next;
        if (e != NULL){
            free(e);
        }
        e = next;
    }

    if (new_deq != NULL){
        free(new_deq);
    }
    fclose(fp);

}