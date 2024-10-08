#include "stack.h"

#include <string.h>

void stackPush(Stack *stack, double value) {
    if (stack->top < MAX_STACK_CAPACITY - 1) {
        stack->items[++stack->top] = value;
    }
}

double stackPop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    }
    return 0.0;
}

void stackPushString(StringStack *stack, const char *value) {
    if (stack->top < MAX_STACK_CAPACITY - 1) {
        strcpy(stack->items[++stack->top], value);
    }
}

char *popStringStack(StringStack *stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    }
    return NULL;
}

int isStringStackEmpty(StringStack *stack) { return stack->top == -1; }
