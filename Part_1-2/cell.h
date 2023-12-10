#ifndef CELL_H
#define CELL_H

#include "../tools.h"

typedef struct s_cell {
    int value;
    struct s_cell** next;
} cell;

cell* create_cell(int val, int nbLevels);
#endif