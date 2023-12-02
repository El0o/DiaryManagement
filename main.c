#include <stdio.h>
#include "lvl_list.h"

int main() {
    int n=4;

    lvl_list* list = build_test_list(n);
    display_list(*list);
    /*
    printf("hello\n");
    lvl_list *list = create_empty_list(5);
    int val=23;
    for(int lvl=5; lvl>=0;lvl--){
        insert_cell(list,lvl,val);
        val=val-3;
    }
    insert_cell(list,4,4);
    insert_cell(list,5,34);
    insert_cell(list,4,4);
    insert_cell(list,3,12);

    display_list(*list);
     */

    return 0;
}
