#include "scalar.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

static constexpr float EPS = 1e-5f;

static void check(const char* name, float got, float expected) {
    if (std::fabs(got - expected) > EPS) {
        std::cout << "FAIL " << name << ": got " << got << ", expected " << expected << "\n";
        assert(false);
    }
    std::cout << "PASS " << name << ": " << got << "\n";
}

int main() {
    check("add",  (Scalar(2.0f) + Scalar(3.0f)).val,  5.0f);
    check("sub",  (Scalar(5.0f) - Scalar(3.0f)).val,  2.0f);
    check("mul",  (Scalar(3.0f) * Scalar(4.0f)).val, 12.0f);
    check("div",  (Scalar(10.0f) / Scalar(4.0f)).val, 2.5f);

    check("relu_pos",       relu(Scalar(2.5f)).val,   2.5f);
    check("relu_neg",       relu(Scalar(-1.0f)).val,  0.0f);
    check("relu_zero",      relu(Scalar(0.0f)).val,   0.0f);
    check("relu_prime_pos", relu_prime(Scalar(1.0f)).val,  1.0f);
    check("relu_prime_neg", relu_prime(Scalar(-1.0f)).val, 0.0f);

    check("sigmoid_zero",       sigmoid(Scalar(0.0f)).val,   0.5f);
    check("sigmoid_large",      sigmoid(Scalar(100.0f)).val, 1.0f);
    check("sigmoid_small",      sigmoid(Scalar(-100.0f)).val, 0.0f);
    check("sigmoid_prime_zero", sigmoid_prime(Scalar(0.0f)).val, 0.25f);

    check("tanh_zero",       tanh_s(Scalar(0.0f)).val,   0.0f);
    check("tanh_large",      tanh_s(Scalar(100.0f)).val, 1.0f);
    check("tanh_prime_zero", tanh_prime(Scalar(0.0f)).val, 1.0f);

    std::cout << "operator<<: " << Scalar(3.14f) << "\n";

    std::cout << "\nAll scalar tests passed.\n";
    return 0;
}
