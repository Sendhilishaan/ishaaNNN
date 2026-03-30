#pragma once
#include <cmath>
#include <ostream>

class Scalar {
public:
    float val;

    Scalar() : val(0.0f) {}
    explicit Scalar(float v) : val(v) {}

    Scalar operator+(const Scalar& o) const { return Scalar(val + o.val); }
    Scalar operator-(const Scalar& o) const { return Scalar(val - o.val); }
    Scalar operator*(const Scalar& o) const { return Scalar(val * o.val); }
    Scalar operator/(const Scalar& o) const { return Scalar(val / o.val); }

    Scalar& operator+=(const Scalar& o) { val += o.val; return *this; }
    Scalar& operator-=(const Scalar& o) { val -= o.val; return *this; }
    Scalar& operator*=(const Scalar& o) { val *= o.val; return *this; }

    bool operator>(const Scalar& o) const { return val > o.val; }
    bool operator<(const Scalar& o) const { return val < o.val; }

    friend std::ostream& operator<<(std::ostream& os, const Scalar& s) {
        return os << s.val;
    }
};

// activations + derivatives — swap these bodies for cuda kernels later
Scalar relu(Scalar x);
Scalar relu_prime(Scalar x);

Scalar sigmoid(Scalar x);
Scalar sigmoid_prime(Scalar x);

Scalar tanh_s(Scalar x);
Scalar tanh_prime(Scalar x);
