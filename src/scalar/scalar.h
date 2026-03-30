#ifndef SCALAR_H
#define SCALAR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef float Scalar;

/* Basic ops */
Scalar scalar_add(Scalar a, Scalar b);
Scalar scalar_sub(Scalar a, Scalar b);
Scalar scalar_mul(Scalar a, Scalar b);
Scalar scalar_div(Scalar a, Scalar b);

/* Activations */
Scalar relu(Scalar x);
Scalar relu_prime(Scalar x);

Scalar sigmoid(Scalar x);
Scalar sigmoid_prime(Scalar x);

Scalar tanh_s(Scalar x);
Scalar tanh_prime(Scalar x);

#ifdef __cplusplus
}
#endif

#endif /* SCALAR_H */
