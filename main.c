#include <stdio.h>
#include "lvl_list.h"

int main() {


    lvl_list *list = create_empty_list(5);

    add_head(list, 0, 10);

    int lvl=3, val=11;
    for(int i=0; i<5;i++){
        insert_cell(list,lvl,val);
        lvl--;
        val=val+2;
    }

    display_list(*list);
    return 0;
}
