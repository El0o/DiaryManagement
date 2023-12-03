#include "cell.h"

cell* create_cell(int val, int nbLevels){
    cell* newcell = (cell*) malloc(sizeof(cell));
    int i;
    newcell->value = val;
    newcell->next = (cell**) malloc(nbLevels*sizeof(cell));
    for(i=0; i < nbLevels; i++) newcell->next[i] = NULL;
    return newcell;
}