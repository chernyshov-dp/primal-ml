#include <stddef.h>
#include <stdio.h>
#include <time.h>

#ifndef PRIMALNN_H_
#define PRIMALNN_H_

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

float rand_float(void);

Matrix matrix_alloc(size_t rows, size_t cols);
void matrix_dot(Matrix c, Matrix a, Matrix b);
void matrix_sum(Matrix c, Matrix a);
void matrix_print(Matrix a);
void matrix_rand(Matrix a, float low, float high);
void matrix_fill(Matrix a, float x);

#endif // PRIMALNN_H

#ifdef PRIMALNN_IMPLEMENTATION

float rand_float(void) {
  return (float)rand() / (float)RAND_MAX;
}

Matrix matrix_alloc(size_t rows, size_t cols){
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.es = PRIMALNN_MALLOC(sizeof(*m.es) * rows * cols);
    PRIMALNN_ASSERT(m.es != NULL);
    return m;
}

void matrix_dot(Matrix c, Matrix a, Matrix b){
    PRIMALNN_ASSERT(a.cols == b.rows);
    size_t n = a.cols;
    PRIMALNN_ASSERT(c.rows == a.rows);
    PRIMALNN_ASSERT(c.cols == b.cols);

    for (size_t i = 0; i < c.rows; i++) {
        for (size_t j = 0; j < c.cols; j++) {
            MATRIX_AT(c, i, j) = 0;
            for (size_t k = 0; k < n; k++) {
                MATRIX_AT(c, i, j) += MATRIX_AT(a, i, k) * MATRIX_AT(b, j, k);
            }
        }
    }
}

void matrix_sum(Matrix c, Matrix a) {
    PRIMALNN_ASSERT(c.rows == a.rows);
    PRIMALNN_ASSERT(c.cols == a.cols);
    for (size_t i = 0; i < c.rows; i++) {
        for (size_t j = 0; j < c.cols; j++) {
            MATRIX_AT(c, i, j) += MATRIX_AT(a, i, j);
        }
    }
}

void matrix_print(Matrix a) {
    for (size_t i = 0; i < a.rows; i++) {
        for (size_t j = 0; j < a.cols; j++) {
            printf("%f ", MATRIX_AT(a, i, j));
        }
        printf("\n");
    }
}

void matrix_rand(Matrix a, float low, float high) {
    srand(time(0));
    for (size_t i = 0; i < a.rows; i++) {
        for (size_t j = 0; j < a.cols; j++) {
            MATRIX_AT(a, i, j) = rand_float() * (high - low) + low;
        }
    }
}

void matrix_fill(Matrix a, float x) {
    for (size_t i = 0; i < a.rows; i++) {
        for (size_t j = 0; j < a.cols; j++) {
            MATRIX_AT(a, i, j) = x;
        }
    }
}

#endif // PRIMALNN_IMPLEMENTATION
