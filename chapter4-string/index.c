#include <stdio.h>
#include <string.h>
#include "sstring.h"

int Index(SString S, SString T)
{
    if (S.length < T.length)
        return 0;
    int i = 1, j = 1;
    while (i + T.length - 1 <= S.length)
    {
        int k;
        for (k = 0; k < T.length; k++)
        {
            if (S.ch[i] != T.ch[j])
                break;
            i++;
            j++;
        }
        if (j > T.length)
            return i - T.length;

        i = i - j + 2;
        j = 1;
    }
    return 0;
}

int main(void)
{
    SString S;
    char *source = "abaabaabcabaabc";
    int i;
    for (i = 0; i < strlen(source); i++)
        S.ch[i + 1] = source[i];
    S.length = strlen(source);
    SString T;
    source = "abaabc";
    T.length = strlen(source);
    for (i = 0; i < T.length; i++)
        T.ch[i + 1] = source[i];
    printf("%d\n", Index(S, T));
    return 0;
}