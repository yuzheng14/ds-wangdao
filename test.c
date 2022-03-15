#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *n;
    if (n == NULL)
    {
        printf("n is null.\n");
        printf("n:%p\n", n);
    }
    else
    {
        puts("n is not null.\n");
        printf("n:%p\n*n:%d\n", n, *n);
    }
}