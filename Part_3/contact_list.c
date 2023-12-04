#include "contact_list.h"

c_lst* create_list(void){
    c_lst* newlist = malloc(sizeof(c_lst));
    for(int i=0; i < 4; i++)
        newlist->head[i] = NULL;
    return newlist;
}

void display_contact_list(c_lst list) {
    for(int i=0; i<4; i++) {
        printf("[list head_%d @-]", i);
        contact *curr= list.head[i];
        while(curr != NULL) {
            printf("-->[ %s |@-]",curr->name);
            curr = curr->next[i];
        }
        printf("-->NULL\n");
    }
}
/*void new_head(c_lst* lst, int level, contact* contact){
void new_head(c_lst* lst, int level, contact* contact){
    if (level >= 4) {
        perror("Cannot add head on unexisting level"); //mets un message d'erreur dans la console
        exit(1); //quitte le programme
    }
    contact->next[level] = lst->head[level];
    lst->head[level] = contact;
}

void insert_0(c_lst * list, contact* ctc){
    int stop=0, i;
    if (list->head[0]==NULL)
        new_head(list,0,ctc);
    else{
        contact* position=list->head[0],*previous;
        while(position->next[0]!=NULL && !stop){
            i=0;
            while(ctc->name[i]!='_' && position->name[i]!='_'){
                if (position->name[i] > ctc->name[i])
                    stop=1;
                else if (position->name[i]==ctc->name[i])
                    i++;
                else {
                    previous=position;
                    position=position->next[0];
                }
            }
        }
        if (position==list->head[0])
            new_head(list,0,ctc);
        else if(stop){
            previous->next[0]=ctc;
            ctc->next[0]=position;
        }
        else
            position->next[0]=ctc;
    }
}*/