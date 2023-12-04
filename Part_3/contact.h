#ifndef DIARYMANAGEMENT_CONTACT_H
#define DIARYMANAGEMENT_CONTACT_H

#include "appointment.h"

typedef struct s_contact{
    char* name;
    //rdv* appointments;
    rdv* head_rdv;
    int nbAppointments;
} contact;

contact *create_contact(char* firstn_surn);
void add_rdv(contact* ctc, rdv* appoint);

#endif //DIARYMANAGEMENT_CONTACT_H
