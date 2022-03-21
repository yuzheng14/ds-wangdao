#include <stdio.h>

#if !defined H_STRING_H
#define H_STRING_H

#if !defined H_STRING
#define H_STRING
typedef struct
{
    char *ch;
    int length;
} HString;
#endif

#endif