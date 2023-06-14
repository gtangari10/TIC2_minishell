#include <stdio.h> 
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>

// Muestra el userid como número y también el nombre de usuario.
// Sin parámetros.

int builtin_uid (){
    uid_t uid = getuid();
    struct passwd * name = getpwuid(uid);
    if(name != NULL){
        fprintf(stderr, "UID: %d, Name: %s, Info: '%s'\n", name->pw_uid, name->pw_name, name->pw_gecos);
    }
    return 0;
}