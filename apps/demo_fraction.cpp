#include <iostream>
#include "ratexpr/fraction.hpp"
#include <stdexcept>
using namespace ratexpr;
int main(){
    std::cout << Fraction(6, -8) << " " << Fraction(10, 4) << std::endl;
    std::cout << Fraction(1, 2) + Fraction(1, 3) << std::endl;
    std::cout << Fraction(1, 2) - Fraction(1, 3) << std::endl;
    std::cout << Fraction(1, 2) * Fraction(1, 3) << std::endl;
    std::cout << Fraction(1, 2) / Fraction(1, 3) << std::endl;
    std::cout << Fraction(1, 2) + 2u << std::endl;
    std::cout << 2u + Fraction(1, 2) << std::endl;
    std::cout << Fraction(1, 2) - 2u << std::endl;
    std::cout << 2u - Fraction(1, 2) << std::endl;
    std::cout << Fraction(1, 2) / 2u << std::endl;
    std::cout << 2u / Fraction(1, 2) << std::endl;
    Fraction acc(0);
    acc += Fraction(1, 2);
    acc += Fraction(1, 3);
    acc *= 6u;
    try {
        std::cout << Fraction(1, 0);
    } 
    catch (const std::invalid_argument& e){
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << Fraction(1, 2) / 0u;
    } 
    catch (const std::invalid_argument& e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}