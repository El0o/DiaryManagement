#ifndef DIARYMANAGEMENT_CONTACT_H
#define DIARYMANAGEMENT_CONTACT_H

typedef struct s_contact{
    char* surname;
    char* first_name;
}contact;

typedef struct s_appointment{
    int date[3];
    int time[2];
    int length[2];
    char* purpose;
}rdv;

typedef struct s_entry{
    contact contact;
    rdv* lst_rdv;
}entry;

#endif //DIARYMANAGEMENT_CONTACT_H
