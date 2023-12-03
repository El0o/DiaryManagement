#ifndef DIARYMANAGEMENT_APPOINTMENT_H
#define DIARYMANAGEMENT_APPOINTMENT_H

#include <stdlib.h>
#include "../tools.h"

typedef struct s_appointment {
    int date[3];
    int time[2];
    int length[2];
    char* purpose;
} rdv;

rdv *create_appointment(char* DDMMYYYY, char* HHMM, char* hhmm, char* content);

#endif //DIARYMANAGEMENT_APPOINTMENT_H
