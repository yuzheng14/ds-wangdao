#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char ElemType;

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LiStack;

bool InitStack(LiStack *S);
bool StackEmpty(LiStack S);
bool Push(LiStack *S, ElemType e);
bool Pop(LiStack *S, ElemType *e);
bool GetTop(LiStack S, ElemType *e);
bool DestroyStack(LiStack *S);

bool InitStack(LiStack *S)
{
    (*S) = NULL;
    return true;
}

bool StackEmpty(LiStack S)
{
    return S == NULL;
}

bool Push(LiStack *S, ElemType e)
{
    LinkNode *new = (LinkNode *)malloc(sizeof(LinkNode));
    if (!new)
        return false;
    new->data = e;
    new->next = (*S);
    (*S) = new;
    return true;
}

bool Pop(LiStack *S, ElemType *e)
{
    if (StackEmpty(*S))
        return false;
    if (e)
        *e = (*S)->data;
    LinkNode *current = (*S);
    (*S) = current->next;
    free(current);
    return true;
}

bool GetTop(LiStack S, ElemType *e)
{
    if (StackEmpty(S))
        return false;
    if (e)
        *e = S->data;
    return true;
}

bool DestroyStack(LiStack *S)
{
    if (!(*S))
        return false;
    while (!StackEmpty(*S))
        Pop(S, NULL);
    return true;
}

bool bracketCheck(char *brackets, int length)
{
    LiStack bracketStack;
    InitStack(&bracketStack);
    int i;
    for (i = 0; i < length; i++)
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{')
        {
            Push(&bracketStack, brackets[i]);
        }
        else
        {
            if (StackEmpty(bracketStack))
                return false;
            else
            {
                char topElem;
                Pop(&bracketStack, &topElem);
                switch (brackets[i])
                {
                case ')':
                    if (topElem != '(')
                        return false;
                    break;
                case ']':
                    if (topElem != '[')
                        return false;
                    break;
                case '}':
                    if (topElem != '{')
                        return false;
                    break;
                default:
                    return false;
                    break;
                }
            }
        }
    return StackEmpty(bracketStack);
}

void puts_true(bool boolean)
{
    if (boolean)
        puts("true");
    else
        puts("false");
}

// TODO compute_expression()

int main(void)
{
    char *brackets = "{[()()]}((())(())())";
    puts_true(bracketCheck(brackets, 20));
    brackets = "{[]]}";
    puts_true(bracketCheck(brackets, 5));
    brackets = "{([]}";
    puts_true(bracketCheck(brackets, 5));
    brackets = "(()))";
    puts_true(bracketCheck(brackets, 5));
    brackets = "(()()";
    puts_true(bracketCheck(brackets, 5));
    return 0;
}