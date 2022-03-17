#include <stdio.h>
#include <stdlib.h>

bool sub_func(char *&);

int main(void)
{
    char *p;
    if(sub_func(p))
    {
        printf("%s\n",p);
    }
    return 0;
}

bool sub_func(char *&p)
{
    p=(char *)malloc(sizeof(char)*100);
    if(!p)
        return false;
    else
    {
        fgets(p,100,stdin);
        return true;
    }
}