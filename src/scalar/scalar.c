#include "scalar.h"
#include <math.h>

Scalar scalar_add(Scalar a, Scalar b) { return a + b; }
Scalar scalar_sub(Scalar a, Scalar b) { return a - b; }
Scalar scalar_mul(Scalar a, Scalar b) { return a * b; }
Scalar scalar_div(Scalar a, Scalar b) { return a / b; }

Scalar relu(Scalar x)       { return x > 0.0f ? x : 0.0f; }
Scalar relu_prime(Scalar x) { return x > 0.0f ? 1.0f : 0.0f; }

Scalar sigmoid(Scalar x) {
    return 1.0f / (1.0f + expf(-x));
}

Scalar sigmoid_prime(Scalar x) {
    Scalar s = sigmoid(x);
    return s * (1.0f - s);
}

Scalar tanh_s(Scalar x)     { return tanhf(x); }
Scalar tanh_prime(Scalar x) { Scalar t = tanhf(x); return 1.0f - t * t; }
