#include "stdio.h"

#define Expression_Length_MAX 50
char * s_gets(char * string, int n);

int main(void){
    char Infix[Expression_Length_MAX];

    gets(Infix);
    puts(Infix);

    return 0;
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            *find= '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}
