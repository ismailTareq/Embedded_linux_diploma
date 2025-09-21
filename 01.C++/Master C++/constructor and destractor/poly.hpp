#ifndef POLY_HPP
#define POLY_HPP

#include <iostream>
#include <cmath>

class Poly {

private:
    int order;
    float *coeffs;
    void show (std::ostream &out) const;
public:
    Poly();
    Poly(int order, float coeffs[]);
    ~Poly();
    float compute(float x) const;
    void operator=(const Poly &poly);
    void add_1_to_all_coeffs();
    friend Poly operator+(const Poly &p1, const Poly &p2);
    friend std::ostream &operator<<(std::ostream &out, const Poly &poly);
};
Poly operator+(const Poly &p1, const Poly &p2);
std::ostream &operator<<(std::ostream &out, const Poly &poly);

#endif // POLY_HPP