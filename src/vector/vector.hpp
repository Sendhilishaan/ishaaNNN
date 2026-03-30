#pragma once
#include <cstdlib>
#include <ostream>

class Vector {
public:
    float* data;
    int size;

    explicit Vector(int n);
    Vector(const Vector& o);
    Vector(Vector&& o) noexcept;
    Vector& operator=(const Vector& o);
    Vector& operator=(Vector&& o) noexcept;
    ~Vector();

    float& operator[](int i)       { return data[i]; }
    float  operator[](int i) const { return data[i]; }

    Vector operator+(const Vector& o) const;
    Vector operator-(const Vector& o) const;
    Vector operator*(const Vector& o) const; // element-wise
    Vector operator*(float s)         const; // scale

    float dot(const Vector& o) const;
    float norm()               const;
    // applies fn element-wise, returns new vector
    Vector apply(float (*fn)(float)) const;

    static Vector zeros(int n);
    static Vector randn(int n);

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

// ops — swap bodies for cuda later
void vec_dot  (float* out, const float* a, const float* b, int n);
void vec_axpy (float* y, float alpha, const float* x, int n); // y += alpha * x
void vec_norm (float* out, const float* a, int n);
void vec_scale(float* out, const float* a, float s, int n);
void vec_add  (float* out, const float* a, const float* b, int n);
void vec_sub  (float* out, const float* a, const float* b, int n);
void vec_mul  (float* out, const float* a, const float* b, int n);
