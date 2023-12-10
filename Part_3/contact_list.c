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
        contact *curr = list.head[i];
        while(curr != NULL) {
            printf("-->[ %s |@-]",curr->name);
            curr = curr->next[i];
        }
        printf("-->NULL\n");
    }
}

void new_head(c_lst* lst, int level, contact* contact){
    if (level >= 4) {
        perror("Cannot add head on unexisting level"); //mets un message d'erreur dans la console
        exit(1); //quitte le programme
    }
    contact->next[level] = lst->head[level];
    lst->head[level] = contact;
}


int which_level(c_lst* list, contact* ctc){
    int letter=0,stop=0;
    contact* position=list->head[3];
    if (position==NULL)
        return 3;
    for(int i=3;i>0;i--){
        position=list->head[i];
        while(position!=NULL && !stop && ctc->name[letter]!='_' && position->name[letter]!='_') {
            if (position->name[letter] == ctc->name[letter])
                for(int j=letter+1; ctc->name[j]!='_' && position->name[j]!='_' && !stop; j++){
                    if (position->name[j] > ctc->name[j])
                        return i;
                    else if (position->name[j] < ctc->name[j])
                        stop=1;
                }
            else if (position->name[letter] > ctc->name[letter])
                return i;
            else {
                if (position->next[i] == NULL)
                    return i;
                else
                    position = position->next[i];
            }
        }
        letter++;
        stop=0;
    }
    return 0;
}


void insert_0(c_lst * list, contact* ctc){
    if (list->head[0]==NULL)
        new_head(list,0,ctc);
    else{
        int stop=0, i;
        contact* position=list->head[0],*previous;
        while(position!=NULL && !stop){
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
        if(stop){
            if (position==list->head[0]) {
                new_head(list, 0, ctc);
                list->head[0]->next[0]=position;
            }
            else {
                previous->next[0] = ctc;
                ctc->next[0] = position;
            }
        }
        else
            position->next[0]=ctc;
    }
}

void insert_1(c_lst* list, contact* ctc){
    if (list->head[1]==NULL)
        new_head(list,1,ctc);
    else{
        int stop=0, i;
        contact* position=list->head[1], *previous;
        while(position!=NULL && !stop){
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
        if(stop){
            if (position==list->head[0]) {
                new_head(list, 0, ctc);
                list->head[0]->next[0]=position;
            }
            else {
                previous->next[0] = ctc;
                ctc->next[0] = position;
            }
        }
        else
            position->next[0]=ctc;
    }
    insert_0(list,ctc);
}