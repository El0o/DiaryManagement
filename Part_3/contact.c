
#include "contact.h"

contact *create_contact(char* lastn_firstn){
    contact *newcontact = (contact*) malloc(sizeof(contact));
    int len= char_length(lastn_firstn);
    newcontact->name=(char*) malloc(len*sizeof(char));
    newcontact->name=lastn_firstn;
    newcontact->head_rdv=NULL;
    for(int i=0; i<4;i++)
        newcontact->next[i]=NULL;;
    newcontact->nbAppointments=0;
    return newcontact;
}

void add_rdv(contact* ctc, rdv* appoint){
    if (ctc->head_rdv==NULL)
        ctc->head_rdv=appoint;
    else{
        rdv* position=ctc->head_rdv;
        while(position->next!=NULL)
            position=position->next;
        position->next=appoint;
    }
}

void display_rdvs(contact* ctc){
    display_contact(*ctc);
    rdv* appoint=ctc->head_rdv;
    while(appoint!=NULL){
        printf("\nDate : %s - At : %s - For : %s - Description : %s",
               appoint->date,appoint->time, appoint->length,appoint->purpose);
        appoint=appoint->next;
    }
}

void display_contact(contact ctc){
    printf("Name : %s\n", ctc.name);
    printf("You have %d appointments with them.\n", ctc.nbAppointments);
}


