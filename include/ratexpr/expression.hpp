#pragma once
#include <iostream>
#include <memory>
#include "fraction.hpp"
namespace ratexpr {
class Expression {
    public:
    virtual ~Expression() = default;
    virtual Fraction evaluate() const = 0;
    virtual void print(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Expression& e);
class Const : public Expression {
public:
    explicit Const(const Fraction& value);
};

class Negative : public Expression {
public:
    explicit Negative(std::unique_ptr<Expression> operand);
};

class BinaryExpression : public Expression {
    public:
        BinaryExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs);
};

    class Add : public BinaryExpression {};
} 