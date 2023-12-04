#ifndef DIARYMANAGEMENT_CONTACT_LIST_H
#define DIARYMANAGEMENT_CONTACT_LIST_H

#include "contact.h"

typedef struct s_contact_list {
    contact* head[4];
} c_lst;

c_lst* create_list(void);
void new_head(c_lst *, int, contact*);
void insert_0(c_lst *, contact*);


#endif //DIARYMANAGEMENT_CONTACT_LIST_H
