#include "graph.h"  // For test printf("Expression in postfix notation: %s\n", numbers); (14)

int main() {
    int gg = 1;
    char mass[MAX_SIZE];
    printf("Enter the expression: ");
    fgets(mass, MAX_SIZE, stdin);
    int size = strlen(mass);
    exm_infix(mass, size, &gg);
    if (gg == 1) {
        char numbers[size];
        infix_to_postfix(mass, numbers, &gg);
        if (gg == 1) {
            print_graph(numbers, strlen(numbers), postfix_count, &gg);
        }
    }
    return 0;
}