#ifndef GRAPH_HEADERS_H
#define GRAPH_HEADERS_H

#include "const_def.h"
#include "stack.h"

void plotGraph(char rpnTokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH], int totalTokens);
double calculateRPN(char rpnTokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH], int totalTokens,
                    double xValue);
double performFunction(const char *func, double arg);
double performOperation(const char *op, double a, double b, double xValue);

#endif
