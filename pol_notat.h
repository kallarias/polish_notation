#ifndef POLISH_NOT_H
#define POLISH_NOT_H

#include "graph.h"
void infix_to_postfix(const char *mass, char *numbers, int *gg);
int if_operator(char c);
int tok_func(char *s);
int take_priority(char op);
int if_func(char c);

#endif