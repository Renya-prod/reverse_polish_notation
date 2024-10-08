#ifndef RPN_HEADERS_H
#define RPN_HEADERS_H

#include "const_def.h"

void convertInfixToPostfix(char *infix, char postfixTokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH],
                           int *length);
int getOperatorPrecedence(const char *operator);

#endif
