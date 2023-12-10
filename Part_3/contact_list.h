#ifndef DIARYMANAGEMENT_CONTACT_LIST_H
#define DIARYMANAGEMENT_CONTACT_LIST_H

#include "contact.h"

typedef struct s_contact_list {
    contact* head[4];
} c_lst;

c_lst* create_list(void);
void new_head(c_lst *, int, contact*);

void display_contact_list(c_lst);

int which_level(c_lst*, contact*);
void insert_0(c_lst *, contact*);
void insert_1(c_lst*, contact*);
void insert_2(c_lst*, contact*);
void insert_3(c_lst*, contact*);
void insert_lvls(c_lst*, contact*);

contact* search_zero_p3(c_lst, char*);
contact* search_lvls_p3(c_lst, char*);

#endif //DIARYMANAGEMENT_CONTACT_LIST_H
