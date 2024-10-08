#ifndef LEXEME_HEADERS_H
#define LEXEME_HEADERS_H

#include "const_def.h"

void parseExpression(const char *infix, char tokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH],
                     int *tokenCount);
int validateExpression(const char *expression);
int isMathOperator(const char *token);
int isMathFunction(const char *token);
int isValidNumber(char token);

#endif
