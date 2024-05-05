#ifndef PRIMALNN_H_
#define PRIMALNN_H_

#include <stddef.h>
#include <stdio.h>

#ifndef PRIMALNN_MALLOC
#include <stdlib.h>
#define PRIMALNN_MALLOC malloc
#endif // PRIMALNN_MALLOC

#ifndef PRIMALNN_ASSERT
#include <assert.h>
#define PRIMALNN_ASSERT assert
#endif // PRIMALNN_ASSERT

typedef struct {
    size_t rows;
    size_t cols;
    float *es;
} Matrix;

#define MATRIX_AT(a, i, j) (a).es[(i) * (a).cols + (j)]

Matrix matrix_alloc(size_t rows, size_t cols);
void matrix_dot(Matrix c, Matrix a, Matrix b);
void matrix_sum(Matrix c, Matrix a);
void matrix_print(Matrix a);

#endif // PRIMALNN_H

#ifdef PRIMALNN_IMPLEMENTATION

Matrix matrix_alloc(size_t rows, size_t cols){
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.es = PRIMALNN_MALLOC(sizeof(*m.es) * rows * cols);
    PRIMALNN_ASSERT(m.es != NULL);
    return m;
}

void matrix_dot(Matrix c, Matrix a, Matrix b){
    (void) c;
    (void) a;
    (void) b;
}

void matrix_sum(Matrix c, Matrix a) {
    (void) c;
    (void) a;
}

void matrix_print(Matrix a) {
    for (size_t i = 0; i < a.rows; i++) {
        for (size_t j = 0; j < a.cols; j++) {
            printf("%f", MATRIX_AT(a, i, j));
        }
        printf("\n");
    }
}

#endif // PRIMALNN_IMPLEMENTATION
