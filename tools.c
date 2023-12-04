#include "tools.h"

int powint(int x, int n) {
    int i, ans=1;
    for(i=1; i<=n; i++) ans = ans*x;
    return ans;
}

int char_length(char* array){
    int len=0;
    for(int i=0; array[i]!='\0';i++)
        len++;
    return len;
}