#include "input_valid.h"

void exm_infix(char* mass, int size, int* gg) {
    int count = 0;
    int i = 0;
    while (i < size && *gg == 1) {
        if (mass[i] == ' ' || mass[i] == '\t' || mass[i] == '\n') {
            i++;
            continue;
        }
        if (count < 0) {
            printf("Error: different count of '(' and ')'\n");
            *gg = 0;
        }
        if (!if_operator(mass[i]) && if_numb(mass[i]) && mass[i] != '(' && mass[i] != ')' && mass[i] != ' ') {
            printf("Error: invalid value entered\n");
            *gg = 0;
        }
        if (mass[i] == '(') {
            if (mass[i + 1] == ')') {
                printf("Error: empty expression\n");
                *gg = 0;
            }
            count++;
        } else if (mass[i] == ')') {
            count--;
        }
        i++;
    }
    if (count > 0) {
        printf("Error: different count of '(' and ')'\n");
        *gg = 0;
    }
}

int if_numb(char c) {
    int f = 1;
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) f = 0;
    return f;
}
