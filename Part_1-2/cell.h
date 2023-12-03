#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_cell {
    int value;
    struct s_cell** next;
} cell;

cell* create_cell(int, int);
#endif