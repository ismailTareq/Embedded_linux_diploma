#include "poly.hpp"


int main(){
    int order;
    std::cout << "Enter the order of the polynomial: ";
    std::cin >> order;
    float *coeffs = new float[order];
    for (int i = 0 ; i < order ; i++)
        std::cin >> coeffs[i];
    Poly p1(order, coeffs);
    std::cout << "Polynomial P1: " << p1;
    std::cout << "------------------------------------------------------------" << std::endl;
    float x;
    std::cout << "Enter a value for x: ";
    std::cin >> x;
    std::cout << "P1(" << x << ") = " << p1.compute(x) << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    int order2 = 3;
    float coeffs2[] = {1.0f, 2.0f, 3.0f, 0.0f};
    Poly p2(order2, coeffs2);
    std::cout << "Polynomial P2: " << p2;
    std::cout << "------------------------------------------------------------" << std::endl;
    Poly p3;
    p3 = p1 + p2;
    std::cout << "Polynomial P3 (P1 + P2): " << p3;
    std::cout << "------------------------------------------------------------" << std::endl;
    Poly p4;
    p4 = p3;
    std::cout << "Polynomial P4 (P3): " << p4;
    p3.add_1_to_all_coeffs();
    std::cout << "Polynomial P3 after adding 1 to all coefficients: " << p4;
    std::cout << "Polynomial P3 after adding 1 to all coefficients: " << p3;
    return 0;
}
