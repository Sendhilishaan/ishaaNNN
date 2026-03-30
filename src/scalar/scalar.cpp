#include "scalar.hpp"

Scalar relu(Scalar x)       { return Scalar(x.val > 0.0f ? x.val : 0.0f); }
Scalar relu_prime(Scalar x) { return Scalar(x.val > 0.0f ? 1.0f : 0.0f); }

Scalar sigmoid(Scalar x) {
    return Scalar(1.0f / (1.0f + std::exp(-x.val)));
}

Scalar sigmoid_prime(Scalar x) {
    Scalar s = sigmoid(x);
    return Scalar(s.val * (1.0f - s.val));
}

Scalar tanh_s(Scalar x)     { return Scalar(std::tanh(x.val)); }
Scalar tanh_prime(Scalar x) { float t = std::tanh(x.val); return Scalar(1.0f - t * t); }
