#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "lexeme.h"
#include "rpn.h"
#include "stack.h"

int main() {
    char inputExpression[MAX_EXPRESSION_LENGTH];
    char postfixTokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH];
    int totalTokens;

    printf("Введите выражение: ");
    fgets(inputExpression, MAX_EXPRESSION_LENGTH, stdin);

    inputExpression[strcspn(inputExpression, "\n")] = '\0';

    if (validateExpression(inputExpression) == 0) {
        printf("n/a");
        return 1;
    }

    convertInfixToPostfix(inputExpression, postfixTokens, &totalTokens);
    plotGraph(postfixTokens, totalTokens);

    return 0;
}
