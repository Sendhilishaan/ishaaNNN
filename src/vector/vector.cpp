#include "vector.hpp"
#include <cmath>
#include <cstring>
#include <cassert>
#include <random>

void vec_dot(float* out, const float* a, const float* b, int n) {
    float s = 0.0f;
    for (int i = 0; i < n; i++) s += a[i] * b[i];
    *out = s;
}

void vec_axpy(float* y, float alpha, const float* x, int n) {
    for (int i = 0; i < n; i++) y[i] += alpha * x[i];
}

void vec_norm(float* out, const float* a, int n) {
    float s = 0.0f;
    for (int i = 0; i < n; i++) s += a[i] * a[i];
    *out = std::sqrt(s);
}

void vec_scale(float* out, const float* a, float s, int n) {
    for (int i = 0; i < n; i++) out[i] = a[i] * s;
}

void vec_add(float* out, const float* a, const float* b, int n) {
    for (int i = 0; i < n; i++) out[i] = a[i] + b[i];
}

void vec_sub(float* out, const float* a, const float* b, int n) {
    for (int i = 0; i < n; i++) out[i] = a[i] - b[i];
}

void vec_mul(float* out, const float* a, const float* b, int n) {
    for (int i = 0; i < n; i++) out[i] = a[i] * b[i];
}

// lifecycle

Vector::Vector(int n) : size(n) {
    data = static_cast<float*>(std::malloc(n * sizeof(float)));
    std::memset(data, 0, n * sizeof(float));
}

Vector::Vector(const Vector& o) : size(o.size) {
    data = static_cast<float*>(std::malloc(size * sizeof(float)));
    std::memcpy(data, o.data, size * sizeof(float));
}

Vector::Vector(Vector&& o) noexcept : data(o.data), size(o.size) {
    o.data = nullptr;
    o.size = 0;
}

Vector& Vector::operator=(const Vector& o) {
    if (this == &o) return *this;
    std::free(data);
    size = o.size;
    data = static_cast<float*>(std::malloc(size * sizeof(float)));
    std::memcpy(data, o.data, size * sizeof(float));
    return *this;
}

Vector& Vector::operator=(Vector&& o) noexcept {
    if (this == &o) return *this;
    std::free(data);
    data = o.data;
    size = o.size;
    o.data = nullptr;
    o.size = 0;
    return *this;
}

Vector::~Vector() { std::free(data); }

// operators

Vector Vector::operator+(const Vector& o) const {
    assert(size == o.size);
    Vector out(size);
    vec_add(out.data, data, o.data, size);
    return out;
}

Vector Vector::operator-(const Vector& o) const {
    assert(size == o.size);
    Vector out(size);
    vec_sub(out.data, data, o.data, size);
    return out;
}

Vector Vector::operator*(const Vector& o) const {
    assert(size == o.size);
    Vector out(size);
    vec_mul(out.data, data, o.data, size);
    return out;
}

Vector Vector::operator*(float s) const {
    Vector out(size);
    vec_scale(out.data, data, s, size);
    return out;
}

// methods

float Vector::dot(const Vector& o) const {
    assert(size == o.size);
    float result;
    vec_dot(&result, data, o.data, size);
    return result;
}

float Vector::norm() const {
    float result;
    vec_norm(&result, data, size);
    return result;
}

Vector Vector::apply(float (*fn)(float)) const {
    Vector out(size);
    for (int i = 0; i < size; i++) out.data[i] = fn(data[i]);
    return out;
}

// factories

Vector Vector::zeros(int n) {
    return Vector(n); // constructor already zeroes
}

Vector Vector::randn(int n) {
    static std::mt19937 rng(42);
    static std::normal_distribution<float> dist(0.0f, 1.0f);
    Vector v(n);
    for (int i = 0; i < n; i++) v.data[i] = dist(rng);
    return v;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (int i = 0; i < v.size; i++) {
        os << v.data[i];
        if (i < v.size - 1) os << ", ";
    }
    return os << "]";
}
