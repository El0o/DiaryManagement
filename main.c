#include "Part_1-2/lvl_list.h"
#include "Part_1-2/timer.h"
#include "Part_3/contact_list.h"

int main() {
    /*
     * Copy here the main() from either "copy_main_1.c", "copy_main_2.c" or "copy_main_3.c".
     * Instructions of how to run each part is provided both on the files and the associated "READMEs.md".
     */
    contact *flamel= create_contact("flamel_bezids");
    contact *gallouin= create_contact("gallouin_zaigy");
    contact *garnier= create_contact("garnier_yuier");
    contact *gartner= create_contact("gartner_cxbj");
    contact *grandin= create_contact("grandin_qhsuw");
    contact *gruss= create_contact("gruss_ioremsw");
    contact *guetta= create_contact("guetta_huqwo");
    contact *humbert= create_contact("humbert_sdqji");
    c_lst *list=create_list();

    insert_lvls(list,flamel);
    insert_lvls(list, gruss);
    insert_lvls(list, gartner);
    insert_lvls(list, guetta);
    insert_lvls(list, garnier);
    insert_lvls(list, humbert);
    insert_lvls(list,gallouin);
    insert_lvls(list, grandin);


    printf("%d\n", search_lvls_p3(*list,"garnier_yuier"));
    printf("%d\n", search_lvls_p3(*list,"garnier_yr"));
    printf("%d\n", search_lvls_p3(*list,"guetta_huqwo"));
    return 0;
}
