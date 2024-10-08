#include "rpn.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "lexeme.h"
#include "stack.h"

void convertInfixToPostfix(char *infix, char postfixTokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH],
                           int *length) {
    StringStack stack;
    stack.top = -1;
    char tokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH];
    int tokenCount;

    parseExpression(infix, tokens, &tokenCount);
    *length = 0;

    for (int i = 0; i < tokenCount; i++) {
        if (isValidNumber(tokens[i][0]) || tokens[i][0] == 'x') {
            strcpy(postfixTokens[(*length)++], tokens[i]);
        } else if (isMathFunction(tokens[i])) {
            stackPushString(&stack, tokens[i]);
        } else if (strcmp(tokens[i], "(") == 0) {
            stackPushString(&stack, tokens[i]);
        } else if (strcmp(tokens[i], ")") == 0) {
            while (!isStringStackEmpty(&stack) && strcmp(stack.items[stack.top], "(") != 0) {
                strcpy(postfixTokens[(*length)++], popStringStack(&stack));
            }
            popStringStack(&stack);
            if (!isStringStackEmpty(&stack) && isMathFunction(stack.items[stack.top])) {
                strcpy(postfixTokens[(*length)++], popStringStack(&stack));
            }
        } else if (isMathOperator(tokens[i])) {
            while (!isStringStackEmpty(&stack) &&
                   getOperatorPrecedence(stack.items[stack.top]) >= getOperatorPrecedence(tokens[i])) {
                strcpy(postfixTokens[(*length)++], popStringStack(&stack));
            }
            stackPushString(&stack, tokens[i]);
        }
    }

    while (!isStringStackEmpty(&stack)) {
        strcpy(postfixTokens[(*length)++], popStringStack(&stack));
    }
}

int getOperatorPrecedence(const char *operator) {
    if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0) return 1;
    if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0) return 2;
    return 0;
}
