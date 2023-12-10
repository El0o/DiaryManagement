#include "menu.h"

void menu(){
    char choice='0';
    c_lst *list=create_list();

    printf("\nDIARY MANAGEMENT APPLICATION\n\n");

    while(choice!='6') {
        printf("[ 1 ] - Create a contact\n"
               "[ 2 ] - Search for a contact\n"
               "[ 3 ] - Create an appointment for a contact\n"
               "[ 4 ] - View a contact's appointments\n"
               "[ 5 ] - Delete an appointment\n"
               "[ 6 ] - Quit\n\n"
               "Enter your choice of option :");

        scanf(" %c", &choice);

        switch (choice) {
            case ('1'):
                choice_1(list);
                break;

            case ('2'):
                choice_2(list);
                break;

            case ('3'):
                choice_3(list);
                break;

            case ('4'):
                break;

            case ('5'):
                break;

            case('6'):
                break;

            default:
                printf("hehe");
        }
    }
}


void choice_1(c_lst* list){
    char* name= (char*) malloc(sizeof(char)*50);
    printf("\n\nPlease enter your contact's name as following 'surname_firstname' :");
    scanf(" %s", name);
    insert_lvls(list, create_contact(name));
    printf("\nInsertion into the list of contacts done ! Now choose your next action :\n\n");
}


void choice_2(c_lst* list){
    char* name= (char*) malloc(sizeof(char)*50);
    printf("\nPlease enter the contact's name you're looking for as following 'surname_firstname' :");
    scanf(" %s", name);
    if (search_lvls_p3(*list,name)==NULL)
        printf("\n%s was NOT found in the list of contacts ! Now choose your next action :\n\n",name);
    else
        printf("\n%s was found in the list of contacts ! Now choose your next action :\n\n",name);
}


void choice_3(c_lst* list){
    char yn[10];
    char* name= (char*) malloc(sizeof(char)*50);
    char date[8]="12345678", time[4]="1234", length[4]="4321";
    char* purpose= (char*) malloc(sizeof(char));

    printf("\nTo create an appointment for a contact you have to enter a few informations."
           "\nFirst, the date in format 'DDMMYYYY' :");
    scanf("%s",date);
    printf("Then the time/hours in format 'HHMM' :");
    scanf("%s",time);
    printf("Next its length still in the format 'HHMM' :");
    scanf("%s",length);
    printf("And finally, you can write a small paragraph to describe its purpose :");
    scanf("%s", purpose);

    char stop='y';
    while(stop=='y'){
        printf("\n\nEnter the name of the contact you want to assign this appointment to in format 'surname_firstname' :");
        scanf("%s",name);

        if(search_lvls_p3(*list,name)==NULL){
            printf("This name was not found in the list, do you want to create it ? Please enter 'yes' or 'no'");
            scanf("%s",yn);

            if(strcmp(yn,"yes")==0) {
                insert_lvls(list, create_contact(name));
                add_rdv(search_lvls_p3(*list, name), create_appointment(date, time, length, purpose));
                printf("\nOperation successfully completed !");
            }
            else if(strcmp(yn,"no")==0)
                printf("\nUnderstood, this contact will not be added to the list.");
            else
                printf("We're sorry we did not understand what you wrote.");
        }

        else add_rdv(search_lvls_p3(*list, name), create_appointment(date, time, length, purpose));

        printf("\nDo you want to assign this appointment to another contact ? If so enter y, else enter any other character:");
        scanf("%c", &stop);
    }
}