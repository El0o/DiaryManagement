#ifndef DIARYMANAGEMENT_APPOINTMENT_H
#define DIARYMANAGEMENT_APPOINTMENT_H

#include <stdlib.h>
#include "../tools.h"

#include "stdlib.h"

typedef struct s_appointment {
    char date[6];
    char time[4];
    char length[4];
    char* purpose;
    struct s_appointment* next;
} rdv;

rdv *create_appointment(char* DDMMYYYY, char* HHMM, char* hhmm, char* content);

#endif //DIARYMANAGEMENT_APPOINTMENT_H