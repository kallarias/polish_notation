#include "printing.h"

void print_graph(const char *postfix, int postfix_length, double (*counter)(char *, double, int *), int *gg) {
    char matrix[Y][X];
    int cnt = 0;
    char func[postfix_length];

    for (double x = X_START; x <= X_END + 0.05 && *gg == 1; x += X_STEP) {
        for (int i = 0; i < postfix_length; i++) {
            func[i] = postfix[i];
        }
        double y = counter(func, x, gg);
        if (isnan(y) == 0 && *gg == 1) {
            double distance_y = y - Y_START;
            int yrange = (int)((distance_y + 0.01) / (Y_END - Y_START) * (X - 1));

            for (int i = 0; i <= X; i++) {
                if (i == yrange) {
                    matrix[cnt][i] = '*';
                } else {
                    matrix[cnt][i] = '.';
                }
            }
            cnt++;
        } else {
            printf("Error: You can math error\n");
            *gg = 0;
        }
    }
    for (int j = 0; j < X && *gg == 1; j++) {
        for (int i = 0; i < Y; i++) {
            printf("%2c", matrix[i][25 - j - 1]);
        }
        if (j != X - 1) {
            printf("\n");
        }
    }
}