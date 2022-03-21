#include <stdio.h>

#if !defined L_STRING_H
#define L_STRING_H

#if !defined L_STRING
#define L_STRING
typedef struct StringNode
{
    char ch;
    struct StringNode *next;
} StringNode, *String;
#endif

#endif