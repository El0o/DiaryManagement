
#include "tools.h"

int powint(int x, int n) {
    int i, ans=1;
    for(i=1; i<=n; i++) ans = ans*x;
    return ans;
}

int char_length(char* str){ //  strlen() existe déjà
    int len=0;
    for(int i=0; str[i]!='\0';i++)
        len++;
    return len;
}

int id_underscore(char* lastn_firstn){
    int id=0;
    while (lastn_firstn[id] != '_' && lastn_firstn[id] != '\0') id++;
    if (lastn_firstn[id] == '\0') {
        perror("No underscore in the string");
        id = -999;
    }
    return id;
}

char* name_to_dis(char* lastn_firstn) { // ne marche pas
    char *fullname=  malloc(strlen(lastn_firstn)+1);
    strncpy(fullname, lastn_firstn + id_underscore(lastn_firstn)+1, strlen(lastn_firstn) - id_underscore(lastn_firstn)-1);
    strcat(fullname, " ");
    strncat(fullname, lastn_firstn, id_underscore(lastn_firstn));
    return fullname;
}



/*
char* get_name(char* lastn_firstn){ // Does not work !!!
    char* nameToDisplay = (char*) malloc(char_length(lastn_firstn));
    int i=1;
    nameToDisplay[0] = nameToDisplay[0] = lastn_firstn[0]-32;
    while(lastn_firstn[i] != '_') {
        nameToDisplay[i] = lastn_firstn[i];
        i++;
    }
    nameToDisplay[i] = ' ';
    i++;
    nameToDisplay[i] = nameToDisplay[i] = lastn_firstn[i]-32;
    while (lastn_firstn[i] != '\0') {
        nameToDisplay[i] = lastn_firstn[i];
        i++;
    }
    return nameToDisplay;
}

 getname()'s first prototype. Doesn't work properly.


char* get_name(char* lastn_firstn, char mode){
    *namepart = (char*) malloc(char_length(lastn_firstn)*sizeof(char));
    int i=0, j=0;
    switch (mode) {
        case 'l' :
            while(lastn_firstn[i] != '_') {
                namepart[i] = lastn_firstn[i];
                i++;
            }
            namepart[0] = namepart[0]-32;
            break;
        case 'f' :
            while(lastn_firstn[i] != '_') i++;
            i++;
            while(lastn_firstn[i+j] != '\0') {
                namepart[j] = lastn_firstn[i+j];
                j++;
            }
            namepart[0] = namepart[0]-32;
            break;
        default:
            perror("Unavailable mode, please use 'f' or 'l' ");
            exit(1);
    }
    return namepart;
}
 */