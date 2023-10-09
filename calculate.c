#include "calculate.h"

double postfix_count(char *numbers, double x, int *gg) {
    stack_double counter;
    init_d(&counter);
    char *del;
    double num = 0.0, a = num, b;
    del = strtok(numbers, " ");
    while (del != NULL && *gg == 1) {
        if (del[0] >= 48 && del[0] <= 57) {
            num = strtod(del, NULL);
            push_d(&counter, num, gg);
        } else if (del[0] == 'x') {
            push_d(&counter, x, gg);
        } else if (if_operator(del[0])) {
            b = pop_d(&counter, gg);
            if (*gg == 1) a = pop_d(&counter, gg);
            if (*gg == 1) {
                switch (del[0]) {
                    case '+':
                        push_d(&counter, a + b, gg);
                        break;
                    case '-':
                        push_d(&counter, a - b, gg);
                        break;
                    case '*':
                        push_d(&counter, a * b, gg);
                        break;
                    case '/':
                        push_d(&counter, a / b, gg);
                        break;
                }
            }
        } else if (if_func(del[0])) {
            a = pop_d(&counter, gg);
            if (*gg == 1) {
                switch (del[0]) {
                    case 's':
                        push_d(&counter, sin(a), gg);
                        break;
                    case 'c':
                        push_d(&counter, cos(a), gg);
                        break;
                    case 't':
                        push_d(&counter, tan(a), gg);
                        break;
                    case 'C':
                        push_d(&counter, tan(M_PI / 2 - a), gg);
                        break;
                    case 'S':
                        push_d(&counter, sqrt(a), gg);
                        break;
                    case 'l':
                        push_d(&counter, log(a), gg);
                        break;
                }
            }
        }
        del = strtok(NULL, " ");
    }
    if (*gg == 1)
        a = pop_d(&counter, gg);
    else
        printf("Error\n");
    return a;
}