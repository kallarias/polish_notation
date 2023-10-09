#include "pol_notat.h"

int if_operator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

int if_func(char c) { return c == 's' || c == 'c' || c == 't' || c == 'C' || c == 'S' || c == 'l'; }

int tok_func(char *s) {
    char output = ' ';
    if (strcmp(s, "sin") == 0) {
        output = 's';
    } else if (strcmp(s, "cos") == 0) {
        output = 'c';
    } else if (strcmp(s, "tan") == 0) {
        output = 't';
    } else if (strcmp(s, "ctg") == 0) {
        output = 'C';
    } else if (strcmp(s, "sqrt") == 0) {
        output = 'S';
    } else if (strcmp(s, "ln") == 0) {
        output = 'l';
    }
    return output;
}

int take_priority(char op) {
    int f;
    switch (op) {
        case '+':
            f = 1;
            break;
        case '-':
            f = 1;
            break;
        case '*':
            f = 2;
            break;
        case '/':
            f = 2;
            break;
        case 's':
            f = 3;
            break;
        case 'c':
            f = 3;
            break;
        case 't':
            f = 3;
            break;
        case 'C':
            f = 3;
            break;
        case 'S':
            f = 3;
            break;
        case 'l':
            f = 3;
            break;
        default:
            f = 4;
            break;
    }
    return f;
}

void infix_to_postfix(const char *mass, char *numbers, int *gg) {
    stack operators;
    init(&operators);
    int i, j, k;
    char token[10];
    for (i = 0, j = 0; *gg == 1 && mass[i] != '\0'; i++) {
        char c = mass[i];
        if (c == ' ' || c == '\t' || c == '\n')
            continue;
        else if (c >= 48 && c <= 57) {
            while ((c >= 48 && c <= 57) || c == '.') {
                numbers[j++] = c;
                c = mass[++i];
            }
            numbers[j++] = ' ';
            i--;

        } else if (c == 'x') {
            numbers[j++] = c;
            numbers[j++] = ' ';
        } else if (c >= 97 && c <= 122) {
            k = 0;
            while ((c >= 97 && c <= 122) || c == '(') {
                token[k] = c;
                k++;
                if (c == '(') break;
                c = mass[i + 1];
                i++;
            }
            if (token[k - 1] != '(') {
                *gg = 0;
            } else {
                token[k - 1] = '\0';
                if (tok_func(token)) {
                    push(&operators, tok_func(token), gg);
                    i--;
                } else {
                    *gg = 0;
                }
            }

        } else if (c == '(') {
            push(&operators, c, gg);
            if (mass[i + 1] == ')' || mass[i + 1] == '\n') {
                *gg = 0;
            }
        } else if (c == ')') {
            while (!if_empty(&operators) && operators.stack[operators.top] != '(') {
                numbers[j++] = operators.stack[operators.top--];
                numbers[j++] = ' ';
            }
            if (!if_empty(&operators) && operators.stack[operators.top] == '(') {
                pop(&operators, gg);
            }
        } else if (if_operator(c)) {
            if (c == '-' && (mass[i - 1] == '(' || i == 0)) {
                numbers[j++] = '0';
                numbers[j++] = ' ';
                push(&operators, c, gg);
            } else {
                while (!if_empty(&operators) &&
                       take_priority(operators.stack[operators.top]) >= take_priority(c) &&
                       operators.stack[operators.top] != '(') {
                    numbers[j++] = operators.stack[operators.top--];
                    numbers[j++] = ' ';
                }
                push(&operators, c, gg);
            }
        } else {
            *gg = 0;
        }
    }
    if (*gg != 0) {
        while (!if_empty(&operators)) {
            numbers[j++] = operators.stack[operators.top--];
            numbers[j++] = ' ';
        }
        numbers[j] = '\0';
    } else
        printf("Error: Math error\n");
}
