#ifndef DIARYMANAGEMENT_CONTACT_H
#define DIARYMANAGEMENT_CONTACT_H

#include "appointment.h"

typedef struct s_contact{
    char* name;
    rdv* head_rdv;
    struct s_contact *next[4];
    int nbAppointments;
} contact;

contact *create_contact(char* lastn_firstn);
void add_rdv(contact*, rdv*);
void display_rdvs(contact*);
void display_contact(contact);


#endif //DIARYMANAGEMENT_CONTACT_H
