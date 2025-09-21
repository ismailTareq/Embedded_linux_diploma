#include "poly.hpp"

Poly::Poly(){}
Poly::Poly(int order, float coeffs[]): order(order), coeffs(coeffs){}
Poly::~Poly(){delete[] coeffs;}

void Poly::show(std::ostream &out)const{
    out << "Polynomial of order " << order << ": ";
    for (int i = 0; i <= order; ++i) {
        out << coeffs[i] << "x^" << i;
        if (i < order) out << " + ";
    }
    out << "\n\n";
}

float Poly::compute(float x) const {
    float result = 0;
    for (int i = 0; i <= order; ++i) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

void Poly::operator=(const Poly &poly){
    order = poly.order;
    coeffs = new float[order];
    for (int i = 0 ; i < order ; i++)
        coeffs[i] = poly.coeffs[i];
}

void Poly::add_1_to_all_coeffs() {
    for (int i = 0; i <= order; ++i) {
        coeffs[i] += 1;
    }
}

Poly operator+(const Poly &p1, const Poly &p2){
    int new_order = std::max(p1.order, p2.order);
    float *new_coeffs = new float[new_order];
    for (int i = 0 ; i < new_order ; i++)
    {
        if((i < p1.order) && (i < p2.order)){
            new_coeffs[i] = p1.coeffs[i] + p2.coeffs[i];
        } else if(i < p1.order) {
            new_coeffs[i] = p1.coeffs[i];
        } else {
            new_coeffs[i] = p2.coeffs[i];
        }
    }
    return Poly(new_order, new_coeffs);
}

std::ostream &operator<<(std::ostream &out, const Poly &poly){
    poly.show(out);
    return out;
}