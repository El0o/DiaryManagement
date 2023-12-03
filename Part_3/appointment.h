#ifndef DIARYMANAGEMENT_APPOINTMENT_H
#define DIARYMANAGEMENT_APPOINTMENT_H

typedef struct s_appointment {
    int date[3];
    int time[2];
    int length[2];
    char* purpose;
} rdv;

rdv *create_appointment(int DDMMYYYY, int HHMM, int hhmm, char*);

#endif //DIARYMANAGEMENT_APPOINTMENT_H
