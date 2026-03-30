#include "vector.hpp"
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
    Vector a(3), b(3);
    a[0] = 1.0f; a[1] = 2.0f; a[2] = 3.0f;
    b[0] = 4.0f; b[1] = 5.0f; b[2] = 6.0f;

    // dot
    check("dot", a.dot(b), 32.0f);

    // norm
    check("norm", a.norm(), std::sqrt(14.0f));

    // add
    Vector c = a + b;
    check("add[0]", c[0], 5.0f);
    check("add[1]", c[1], 7.0f);
    check("add[2]", c[2], 9.0f);

    // sub
    Vector d = b - a;
    check("sub[0]", d[0], 3.0f);
    check("sub[1]", d[1], 3.0f);
    check("sub[2]", d[2], 3.0f);

    // element-wise mul
    Vector e = a * b;
    check("mul[0]", e[0],  4.0f);
    check("mul[1]", e[1], 10.0f);
    check("mul[2]", e[2], 18.0f);

    // scale
    Vector f = a * 2.0f;
    check("scale[0]", f[0], 2.0f);
    check("scale[1]", f[1], 4.0f);
    check("scale[2]", f[2], 6.0f);

    // axpy: b += 2 * a  →  [6, 9, 12]
    Vector g = b;
    vec_axpy(g.data, 2.0f, a.data, 3);
    check("axpy[0]", g[0],  6.0f);
    check("axpy[1]", g[1],  9.0f);
    check("axpy[2]", g[2], 12.0f);

    // apply
    Vector h = a.apply([](float x) { return x * x; });
    check("apply[0]", h[0], 1.0f);
    check("apply[1]", h[1], 4.0f);
    check("apply[2]", h[2], 9.0f);

    // zeros
    Vector z = Vector::zeros(3);
    check("zeros[0]", z[0], 0.0f);

    // operator<<
    std::cout << "operator<<: " << a << "\n";

    std::cout << "\nall vector tests passed.\n";
    return 0;
}
