#if !defined UF_SET_H
#define UF_SET_H

#if defined SIZE
#undef SIZE
#endif
#define SIZE 13

typedef int UFSets[SIZE];

void Initial(int S[], int length);

#endif