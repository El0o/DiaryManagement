#ifndef LVL_LIST_H
#define LVL_LIST_H

#include "cell.h"

typedef struct s_lvl_list {
    int max_level;
    cell** head;
} lvl_list;

lvl_list* create_empty_list(int);
void add_head(lvl_list*, int, int);
void display_lvl(lvl_list, int);
void display_list(lvl_list);
void insert_cell(lvl_list*, int, int);

int search_zero(lvl_list, int);

#endif