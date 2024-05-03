#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define train_count (sizeof(train) / sizeof(train[0]))

// OR-gate
float train[][3] = {
    {0, 0 , 0},
    {1, 0 , 1},
    {0, 1 , 1},
    {1, 1 , 1},
};

float rand_float(void) {
  return  (float)rand() / (float)RAND_MAX;
}

// Loss function
float loss(float w1, float w2) {
    float result = 0.0f;
    for (size_t i = 0; i < train_count; i++) {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = x1 * w1 + x2 * w2;
        float d = y - train[i][2];
        result += d * d;
    }
    result /= train_count;
    return result;
}

int main() {
    srand(42);
    float w1 = rand_float();
    float w2 = rand_float();
    
    float eps = 1e-3;
    float rate = 1e-2;

    for (size_t i = 0; i < 1000; i++) {
        float l = loss(w1, w2);
        printf("w1 = %f, w2 = %f, l = %f\n", w1, w2, l);
        float dw1 = (loss(w1 + eps, w2) - l) / eps;
        float dw2 = (loss(w1, w2 + eps) - l) / eps;
        w1 -= rate * dw1;
        w2 -= rate * dw2;
    }

    //printf("Loss = %f\n", l);

    return 0;
}
