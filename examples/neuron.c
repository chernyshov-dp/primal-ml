#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
    {5, 10},
    {6, 12},
    {7, 14},
    {8, 16},
    {9, 18},
    {10, 20},
};

#define train_count (sizeof(train) / sizeof(train[0]))

float rand_float(void) {
  return (float)rand() / (float)RAND_MAX;
}

// Loss function
float loss(float w, float b) {
    float result = 0.0f;
    for (size_t i = 0; i < train_count; i++) {
        float x = train[i][0];
        float y = x * w + b;
        float d = y - train[i][1];
        result += d * d;
    }
    result /= train_count;
    return result;
}

int main() {
    // srand(time(0));
    srand(42);
    float w = rand_float() * 10.0f; // Weight
    float b = rand_float() * 0.1f; // Bias

    float eps = 1e-3;
    float rate = 1e-3; // Learning rate

    printf("Loss = %f, w = %f\n", loss(w, b), w);
    for (size_t i = 0; i < 200; i++) {

        // float l = loss(w, b);

        // Approximate gradient of 2D function
        float dw = (loss(w + eps, b) - loss(w, b)) / eps;
        float db = (loss(w, b + eps) - loss(w, b)) / eps;

        w -= rate * dw;
        b -= rate * db;
        printf("Loss = %f, w = %f, b = %f\n", loss(w, b), w, b);
    }

    printf("---------------------------------------------\n");
    printf("w = %f, b = %f\n", w, b);
    
    return 0;
}
