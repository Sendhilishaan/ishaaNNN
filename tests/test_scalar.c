#include "scalar.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1e-5f

static void check(const char* name, float got, float expected) {
    if (fabsf(got - expected) > EPSILON) {
        printf("FAIL %s: got %.6f, expected %.6f\n", name, got, expected);
        assert(0);
    }
    printf("PASS %s: %.6f\n", name, got);
}

int main(void) {
    /* Basic ops */
    check("scalar_add",  scalar_add(2.0f, 3.0f),   5.0f);
    check("scalar_sub",  scalar_sub(5.0f, 3.0f),   2.0f);
    check("scalar_mul",  scalar_mul(3.0f, 4.0f),  12.0f);
    check("scalar_div",  scalar_div(10.0f, 4.0f),  2.5f);

    /* ReLU */
    check("relu_pos",    relu(2.5f),   2.5f);
    check("relu_neg",    relu(-1.0f),  0.0f);
    check("relu_zero",   relu(0.0f),   0.0f);
    check("relu_prime_pos", relu_prime(1.0f),  1.0f);
    check("relu_prime_neg", relu_prime(-1.0f), 0.0f);

    /* Sigmoid */
    check("sigmoid_zero",  sigmoid(0.0f),  0.5f);
    check("sigmoid_large", sigmoid(100.0f), 1.0f);
    check("sigmoid_small", sigmoid(-100.0f), 0.0f);
    check("sigmoid_prime_zero", sigmoid_prime(0.0f), 0.25f);

    /* Tanh */
    check("tanh_zero",  tanh_s(0.0f),  0.0f);
    check("tanh_large", tanh_s(100.0f), 1.0f);
    check("tanh_prime_zero", tanh_prime(0.0f), 1.0f);

    printf("\nAll scalar tests passed.\n");
    return 0;
}
