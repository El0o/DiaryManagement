#ifndef DIARYMANAGEMENT_CONTACT_LIST_H
#define DIARYMANAGEMENT_CONTACT_LIST_H

#include "contact.h"

typedef struct s_contact_list {
    contact* head[4];
} c_lst;

c_lst* create_list(void);
void new_head(c_lst *, int, contact*);
void display_contact_list(c_lst);
//void display_lvl(lvl_list, int);
//void display_list(lvl_list);
//void insert_cell(lvl_list*, int, int);
int which_level(c_lst*, contact*);
void insert_0(c_lst *, contact*);
void insert_1(c_lst*, contact*);


#endif //DIARYMANAGEMENT_CONTACT_LIST_H
