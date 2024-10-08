#ifndef STACK_HEADERS_H
#define STACK_HEADERS_H

#include "const_def.h"

typedef struct {
    double items[MAX_STACK_CAPACITY];
    int top;
} Stack;

typedef struct {
    char items[MAX_STACK_CAPACITY][MAX_EXPRESSION_LENGTH];
    int top;
} StringStack;

void stackPush(Stack *stack, double value);
double stackPop(Stack *stack);
void stackPushString(StringStack *stack, const char *value);
char *popStringStack(StringStack *stack);
int isStringStackEmpty(StringStack *stack);

#endif
