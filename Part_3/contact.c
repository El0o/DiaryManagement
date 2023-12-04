#include "contact.h"

contact *create_contact(char* firstn_surn){
    contact *newcontact = (contact*) malloc(sizeof(contact));
    int len= char_length(firstn_surn);
    newcontact->name=(char*) malloc(len*sizeof(char));
    newcontact->name=firstn_surn;
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