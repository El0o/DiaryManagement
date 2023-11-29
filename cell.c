#include "cell.h"

cell* create_cell(int val, int nbLevels){
    cell* newcell = malloc(sizeof(cell));
    int i;
    newcell->value = val;
    for(i=0; i < nbLevels; i++) newcell->next[i] = NULL;
    return newcell;
}