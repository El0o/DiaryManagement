#include "lvl_list.h"

lvl_list* create_empty_list(int nbLvl){
    lvl_list *newlist = malloc(sizeof(lvl_list));
    int i;
    newlist->max_level = nbLvl;
    for(i=0; i < nbLvl; i++) newlist->head[i] = NULL;
    return newlist;
}

int add_head(lvl_list* lst, int val){
    int i=0;
    while(i < lst->max_level){
        if(lst->head[i] == NULL) {
            cell *newhead = create_cell(val, lst->max_level);
            lst->head[i] = newhead;
            return 1;
        }
        i++;
    }
    return 0;
}


void insert_cell(lvl_list* lst, int level, int val){
    cell* here = lst->head[level];
    cell* newcell = create_cell(val, lst->max_level);
    while (level > -1){
        while(here->next[level] != NULL && here->next[level]->value < val) here = here->next[level];
        newcell->next[level] = here->next[level]->next[level];
        here->next[level] = newcell;
        level--;
    }
}