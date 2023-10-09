#include "stack.h"

void init(stack *s) { s->top = -1; }

int if_empty(stack *s) { return s->top == -1; }

int if_full(stack *s) { return s->top == MAX_SIZE - 1; }

void push(stack *s, char value, int *gg) {
    if (if_full(s)) {
        printf("Stack Overflow\n");
        *gg = 0;
    } else
        s->stack[++(s->top)] = value;
}

char pop(stack *s, int *gg) {
    char set;
    if (if_empty(s)) {
        printf("Stack Underflow\n");
        *gg = 0;
        set = 0;
    } else
        set = s->stack[s->top--];
    return set;
}

void init_d(stack_double *s) { s->top = -1; }

int if_empty_d(stack_double *s) { return s->top == -1; }

int if_full_d(stack_double *s) { return s->top == MAX_SIZE - 1; }

void push_d(stack_double *s, double value, int *gg) {
    if (if_full_d(s)) {
        printf("Stack Overflow\n");
        *gg = 0;
    } else
        s->stack[++s->top] = value;
}

double pop_d(stack_double *s, int *gg) {
    char set;
    if (if_empty_d(s)) {
        printf("Stack Underflow\n");
        *gg = 0;
        set = 0;
    } else
        set = s->stack[s->top--];
    return set;
}