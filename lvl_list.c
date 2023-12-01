#include "lvl_list.h"

lvl_list* create_empty_list(int nbLvl){
    lvl_list* newlist = malloc(sizeof(lvl_list));
    int i;
    newlist->max_level = nbLvl;
    newlist->head = (cell**) malloc(nbLvl*sizeof(cell));
    for(i=0; i < nbLvl; i++) newlist->head[i] = NULL;
    return newlist;
}

void add_head(lvl_list* lst, int level, int val){
    if (level >= lst->max_level) {
        perror("Cannot add head on unexisting level"); //mets un message d'erreur dans la console
        exit(1); //quitte le programme
    }
    cell *newhead = create_cell(val, level);
    newhead->next[level] = lst->head[level];
    lst->head[level] = newhead;
}


/*void insert_cell(lvl_list* lst, int level, int val){
    cell *here;
    cell *newcell = create_cell(val, lst->max_level);
    while (level > -1){
        if (here == NULL) add_head(lst, level, val);
        else while (here != NULL) {
                if (here->next[level]->value < val)
                here = here->next[level];
            }
            if (here == lst->head[level]) add_head(lst, level, val);
            else {
                newcell->next[level] = here->next[level];
                here->next[level] = newcell;
            }
        level--;
    }
}*/

void insert_cell(lvl_list *lst, int lvl, int val){
    cell *newcell= create_cell(val,lvl);
    cell *position;
    int stop;
    for(int i=lvl-1;i>-1;i--){
        stop=0;
        if (lst->head[i]==NULL)
            add_head(lst, i, val);
        else{
            if (lst->head[i]->value>val)
                add_head(lst, i, val);
            else{
                position = lst->head[i];
                while (position->next[i] != NULL && !stop) {
                    if (position->next[i]->value > val)
                        stop=1;
                    else position = position->next[i];
                }
                newcell->next[i] = position->next[i];
                position->next[i] = newcell;
            }
        }
    }
}

void display_lvl(lvl_list list, int lvl){
    printf("[list head_%d @-]", lvl);
    cell *curr_cell= list.head[lvl];
    while(curr_cell!=NULL) {
        printf("-->[%d|@-]",curr_cell->value);
        curr_cell = curr_cell->next[lvl];
    }
    printf("-->NULL\n");
}

void display_list(lvl_list list){
    for(int i=0; i<list.max_level; i++){
        display_lvl(list, i);
    }
}