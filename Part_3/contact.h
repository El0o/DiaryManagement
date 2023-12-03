#ifndef DIARYMANAGEMENT_CONTACT_H
#define DIARYMANAGEMENT_CONTACT_H

#include "appointment.h"

typedef struct s_contact{
    char* name;
    rdv* appointments;
    int nbAppointments;
} contact;



#endif //DIARYMANAGEMENT_CONTACT_H
