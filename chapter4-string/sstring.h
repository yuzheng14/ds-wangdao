#include <stdio.h>

#if !defined S_STRING_H
#define S_STRING_H

#ifdef MAXLEN
#undef MAXLEN
#endif

#define MAXLEN 255

#if !defined S_STRING
#define S_STRING
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;
#endif

#endif