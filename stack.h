#ifndef STACK_H
#define STACK_H

#include "graph.h"

#define MAX_SIZE 10000
typedef struct {
    char stack[MAX_SIZE];
    int top;
} stack;

typedef struct {
    double stack[MAX_SIZE];
    int top;
} stack_double;

void init(stack *s);
int if_empty(stack *s);
int if_full(stack *s);
void push(stack *s, char value, int *gg);
char pop(stack *s, int *gg);
void init_d(stack_double *s);
int if_empty_d(stack_double *s);
int if_full_d(stack_double *s);
void push_d(stack_double *s, double value, int *gg);
double pop_d(stack_double *s, int *gg);

#endif