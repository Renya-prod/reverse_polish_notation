#include "lexeme.h"

#include <stdio.h>
#include <string.h>

#include "const_def.h"

void parseExpression(const char *infix, char tokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH],
                     int *tokenCount) {
    int index = 0;
    *tokenCount = 0;

    while (infix[index] != '\0') {
        if ((infix[index] >= '0' && infix[index] <= '9') || infix[index] == '.') {
            int tokenIndex = 0;
            while ((infix[index] >= '0' && infix[index] <= '9') || infix[index] == '.') {
                tokens[*tokenCount][tokenIndex++] = infix[index++];
            }
            tokens[*tokenCount][tokenIndex] = '\0';
            (*tokenCount)++;
        } else if ((infix[index] >= 'a' && infix[index] <= 'z') ||
                   (infix[index] >= 'A' && infix[index] <= 'Z')) {
            int tokenIndex = 0;
            while ((infix[index] >= 'a' && infix[index] <= 'z') ||
                   (infix[index] >= 'A' && infix[index] <= 'Z')) {
                tokens[*tokenCount][tokenIndex++] = infix[index++];
            }
            tokens[*tokenCount][tokenIndex] = '\0';
            (*tokenCount)++;
        } else if (infix[index] == '+' || infix[index] == '-' || infix[index] == '*' || infix[index] == '/') {
            tokens[*tokenCount][0] = infix[index++];
            tokens[*tokenCount][1] = '\0';
            (*tokenCount)++;
        } else if (infix[index] == '(' || infix[index] == ')') {
            tokens[*tokenCount][0] = infix[index++];
            tokens[*tokenCount][1] = '\0';
            (*tokenCount)++;
        } else {
            index++;
        }
    }
}

int validateExpression(const char *expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (!((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.' ||
              expression[i] == '-' || expression[i] == '+' || expression[i] == '*' || expression[i] == '/' ||
              expression[i] == ' ' || expression[i] == '(' || expression[i] == ')' ||
              (expression[i] >= 'a' && expression[i] <= 'z') ||
              (expression[i] >= 'A' && expression[i] <= 'Z'))) {
            return 0;
        }
    }

    return 1;
}

int isMathOperator(const char *token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0);
}

int isMathFunction(const char *token) {
    return (strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tg") == 0 ||
            strcmp(token, "ctg") == 0 || strcmp(token, "ln") == 0 || strcmp(token, "sqrt") == 0);
}

int isValidNumber(char token) { return (token >= '0' && token <= '9'); }
