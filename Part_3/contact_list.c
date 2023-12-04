#include "contact_list.h"

c_lst* create_list(void){
    c_lst* newlist = malloc(sizeof(c_lst));
    for(int i=0; i < 4; i++)
        newlist->head[i] = NULL;
    return newlist;
}

/*void new_head(c_lst* lst, int level, contact* contact){
    if (level >= 4) {
        perror("Cannot add head on unexisting level"); //mets un message d'erreur dans la console
        exit(1); //quitte le programme
    }
    contact->next[level] = lst->head[level];
    lst->head[level] = contact;
}*/