#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

// Intenta ejecutar vía fork/execvp, un comando externo.
// El valor de retorno es el status de retorno del comando externo ejecutado.

int externo (int argc, char ** argv){
    
    struct sigaction sig_old_action;
    struct sigaction sig_new_action;
    memset(&sig_new_action, 0, sizeof(sig_old_action));
    sig_new_action.sa_handler = SIG_IGN;
    sigaction(SIGINT, &sig_new_action, &sig_old_action);

    pid_t pid = fork();

    if(pid == -1){
        perror("Error creando proceso hijo");
        return 1;
    }

    if(pid == 0){
        if (execvp(argv[0], argv) == -1){
            fprintf(stderr, "No se puede ejecutar la instrucción %s: ", argv[0]);
            perror("");
        }
        exit(1);
    }

    int status;
    waitpid(pid, &status, 0);
    
    sigaction(SIGINT, &sig_old_action, NULL);
    
    return status;
}