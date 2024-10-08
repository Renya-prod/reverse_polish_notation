#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const_def.h"
#include "lexeme.h"
#include "rpn.h"
#include "stack.h"

void plotGraph(char rpnTokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH], int totalTokens) {
    char canvas[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    memset(canvas, '.', sizeof(canvas));

    double xScale = (DISPLAY_WIDTH - 1) / (4 * PI_VALUE);
    double yScale = (DISPLAY_HEIGHT - 1) / 2;

    int hasX = 0;

    for (int i = 0; i < totalTokens; i++) {
        if (strcmp(rpnTokens[i], "x") == 0) {
            hasX = 1;
            break;
        }
    }

    if (!hasX) {
        printf("n/a");
        return;
    }

    for (int i = 0; i < DISPLAY_WIDTH; i++) {
        double xValue = i * (4 * PI_VALUE) / (DISPLAY_WIDTH - 1);
        double yValue = calculateRPN(rpnTokens, totalTokens, xValue);

        int plot_x = (int)(xValue * xScale);
        int plot_y = (int)(((yValue + 1) * yScale));

        if (plot_x >= 0 && plot_x < DISPLAY_WIDTH && plot_y >= 0 && plot_y < DISPLAY_HEIGHT) {
            canvas[plot_y][plot_x] = '*';
        }
    }

    for (int i = 0; i < DISPLAY_HEIGHT; i++) {
        printf("%.*s\n", DISPLAY_WIDTH, canvas[i]);
    }
}

double calculateRPN(char rpnTokens[MAX_EXPRESSION_LENGTH][MAX_EXPRESSION_LENGTH], int totalTokens,
                    double xValue) {
    Stack myStack;
    myStack.top = -1;

    for (int i = 0; i < totalTokens; i++) {
        if (isValidNumber(rpnTokens[i][0])) {
            stackPush(&myStack, atof(rpnTokens[i]));
        } else if (rpnTokens[i][0] == 'x') {
            stackPush(&myStack, xValue);
        } else if (isMathFunction(rpnTokens[i])) {
            double argument = stackPop(&myStack);
            double result = performFunction(rpnTokens[i], argument);
            stackPush(&myStack, result);
        } else if (isMathOperator(rpnTokens[i])) {
            double operandB = stackPop(&myStack);
            double operandA = stackPop(&myStack);
            double result = performOperation(rpnTokens[i], operandA, operandB, xValue);
            stackPush(&myStack, result);
        }
    }
    return stackPop(&myStack);
}

double performFunction(const char *func, double arg) {
    if (strcmp(func, "sin") == 0) return sin(arg);
    if (strcmp(func, "cos") == 0) return cos(arg);
    if (strcmp(func, "tg") == 0) return tan(arg);
    if (strcmp(func, "ln") == 0) return log(arg);
    if (strcmp(func, "sqrt") == 0) return sqrt(arg);
    return 1.0 / tan(arg);
}

double performOperation(const char *op, double a, double b, double xValue) {
    if (strcmp(op, "+") == 0) return a + b;
    if (strcmp(op, "-") == 0) return a - b;
    if (strcmp(op, "*") == 0) return a * b;
    if (strcmp(op, "/") == 0) {
        if (b == 0 || (b == xValue && xValue == 0)) {
            return NAN;
        }
        return a / b;
    }
    return 0;
}
