#include <stdlib.h>


extern int main(void);


int main(void)
{
    char* str = (char*)malloc(4);
    str[0] = 'b';
    str[0] = 'a';
    while(1);
    return 0;
}


