#include "menu.h"

void menu(){
    char choice;
    char name[50];
    c_lst *list=create_list();

    printf("\nDIARY MANAGEMENT APPLICATION\n\n"
           "[ 1 ] - Create a contact\n"
           "[ 2 ] - Search for a contact\n"
           "[ 3 ] - View a contact's appointments\n"
           "[ 4 ] - Create an appointment for a contact\n"
           "[ 5 ] - Delete an appointment\n\n"
           "Enter your choice of option :");

    scanf(" %c", &choice);

    switch(choice){
        case ('1'):
            printf("\n\nPlease enter your contact's name as following 'surname_firstname' :");
            scanf(" %s",name);
            contact *ctc= create_contact(name);
            insert_lvls(list,ctc);
            break;

        case ('2'):
            printf("\nPlease enter the contact's name you're looking for as following 'surname_firstname' :");
            scanf(" %s\n", name);
            break;
        default:
            printf("hehe");
    }

}