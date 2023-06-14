#include <stdio.h> 
#include <unistd.h>
#include <string.h>
#include <grp.h>


// Muestra el grupo principal y los grupos secundarios del usuario.
// No lleva parámetros. 

int builtin_gid (int argc, char ** argv){

    int cant_groups = getgroups(0, NULL);//calculado para defnir gid_group
    gid_t gid = getgid();
    gid_t gid_group[cant_groups];
    int groups = getgroups(gid, gid_group);

    if(groups == -1){
        fprintf(stderr, "Error");
        return 1;
    }

    if(groups == 0){
        fprintf(stderr, "No hay ningun grupo que mostrar");
    }
    

    for(int i=0; i<groups;i++){
        struct group * grp = getgrgid(gid_group[i]);
        if(grp != NULL){
            fprintf(stderr,"%d(%s) ", gid_group[i], grp->gr_name);
        }
    }

    fprintf(stderr, "\n");
    return 0;
}



