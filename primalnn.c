#define PRIMALNN_IMPLEMENTATION
#include "primalnn.h"

int main(void) {
    Matrix a = matrix_alloc(1, 2);
    matrix_rand(a, 0, 10);

    float id_data[4] = {
        1, 0, 
        0, 1
    };

    Matrix b = { .rows = 2, .cols = 2, .es = id_data};

    Matrix c = matrix_alloc(1, 2);

    matrix_print(a);
    printf("------------------------------\n");
    matrix_dot(c, a, b);
    matrix_print(c);

    return 0;
}
