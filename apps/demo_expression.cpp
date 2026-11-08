#include "ratexpr/expression.hpp"
#include <iostream>
using namespace ratexpr;
int main(){
    auto e = std::make_unique<Mul>(std::make_unique<Add>(std::make_unique<Const>(Fraction(1, 2)),
    std::make_unique<Const>(Fraction(1, 3))),
    std::make_unique<Sub>(std::make_unique<Const>(Fraction(3)), 
    std::make_unique<Const>(Fraction(1, 4))));
    std::cout << e->evaluate() << std::endl;
    auto b = std::make_unique<Negative>(std::make_unique<Const>(Fraction(2, 3)));
    std::cout << b->evaluate();
}