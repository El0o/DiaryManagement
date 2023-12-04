#include "appointment.h"

rdv *create_appointment(char* DDMMYYYY, char* HHMM, char* hhmm, char* content) {
    rdv *newrdv = (rdv*) malloc(sizeof(rdv));
    for (int i=0; i<6;i++)
        newrdv->date[i]=DDMMYYYY[i];
    for(int j=0;j<4;j++) {
        newrdv->time[j]=HHMM[j];
        newrdv->length[j]=hhmm[j];
    }
    newrdv->purpose=(char*) malloc(sizeof(char));
    newrdv->purpose=content;
    newrdv->next=NULL;
    return newrdv;
}
