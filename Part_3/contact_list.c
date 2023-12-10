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
            if (position->name[letter] == ctc->name[letter]){
                    if (strcmp(position->name, ctc->name)>0)
                        return i;
                    else
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
        int stop=0;
        contact* position=list->head[0],*previous;
        while(position!=NULL && !stop){
            if (strcmp(position->name,ctc->name)<0) {
                previous = position;
                position = position->next[0];
            }
            else stop=1;
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
            previous->next[0]=ctc;
    }
}


void insert_1(c_lst* list, contact* ctc){
    if (list->head[1]==NULL)
        new_head(list,1,ctc);
    else{
        int stop=0;
        contact* position=list->head[1],*previous;

        while(position!=NULL && !stop){
            if (strcmp(position->name,ctc->name)<0) {
                previous = position;
                position = position->next[1];
            }
            else stop=1;
        }

        if (stop) {
            if (position == list->head[1]) {
                new_head(list, 1, ctc);
                if(position->name[2]!=ctc->name[2])
                    list->head[1]->next[1] = position;
                else
                    list->head[1]->next[1] = position->next[1];
            }
            else {
                previous->next[1] = ctc;
                if(position->name[2]!=ctc->name[2])
                    ctc->next[1] = position;
                else
                    ctc->next[1] = position->next[1];
            }
        }
        else
            previous->next[1] = ctc;
    }
    insert_0(list,ctc);
}


void insert_2(c_lst* list, contact* ctc) {
    if (list->head[2] == NULL)
        new_head(list, 2, ctc);
    else {
        int stop = 0;
        contact *position = list->head[2], *previous;

        while (position != NULL && !stop) {
            if (strcmp(position->name, ctc->name) < 0) {
                previous = position;
                position = position->next[2];
            }
            else stop = 1;
        }

        if (stop) {
            if (position == list->head[2]) {
                new_head(list, 2, ctc);
                if(position->name[1]!=ctc->name[1])
                    list->head[2]->next[2] = position;
                else
                    list->head[2]->next[2] = position->next[2];
            }
            else {
                previous->next[2] = ctc;
                if(position->name[1]!=ctc->name[1])
                    ctc->next[2] = position;
                else
                    ctc->next[2] = position->next[2];
            }
        }
        else
            previous->next[2] = ctc;
    }
    insert_1(list,ctc);
}


void insert_3(c_lst* list, contact* ctc) {
    if (list->head[3] == NULL)
        new_head(list, 3, ctc);
    else {
        int stop = 0;
        contact *position = list->head[3], *previous;

        while (position != NULL &&!stop) {
            if (strcmp(position->name, ctc->name) < 0) {
                previous = position;
                position = position->next[3];
            }
            else stop=1;
        }

        if (stop) {
            if (position == list->head[3]) {
                new_head(list, 3, ctc);
                if(position->name[0]!=ctc->name[0])
                    list->head[3]->next[3] = position;
                else
                    list->head[3]->next[3] = position->next[3];
            }
            else {
                previous->next[3] = ctc;
                if(position->name[0]!=ctc->name[0])
                    ctc->next[3] = position;
                else
                    ctc->next[3] = position->next[3];
            }
        }
        else
            previous->next[3] = ctc;
    }
    insert_2(list, ctc);
}


void insert_lvls(c_lst* list, contact* ctc){
    int lvl= which_level(list, ctc);
    switch (lvl){
        case (0):
            insert_0(list,ctc);
            break;
        case (1):
            insert_1(list, ctc);
            break;
        case (2):
            insert_2(list, ctc);
            break;
        case (3):
            insert_3(list, ctc);
            break;
        default:
            printf("Error : level does not exist");
            break;
    }
}


int search_zero_p3(c_lst list, char *name) {
    contact * position = list.head[0];
    while (position != NULL) {
        if (strcmp(position->name, name) == 0)
            return 1;
        position = position->next[0];
    }
    return 0;
}


int search_lvls_p3(c_lst list, char *name){
    int i=3, found=0;
    contact *position=list.head[i];
    while(position==NULL && i>-1){
        i--;
        position=list.head[i];
    }
    while(strcmp(position->name, name)>0){
        i--;
        position=list.head[i];
    }
    while(i>-1 && !found){
        if (strcmp(position->name,name)==0)
            found=1;
        else{
            if (position->next[i]!=NULL) {
                if (strcmp(position->next[i]->name,name)<=0)
                    position = position->next[i];
                else i--;
            }
            else i--;
        }
    }
    return found;
}
