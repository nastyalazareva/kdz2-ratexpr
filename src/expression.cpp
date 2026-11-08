#include "ratexpr/expression.hpp"
#include "ratexpr/fraction.hpp"
#include <iostream>

namespace ratexpr{

    std::ostream& operator<<(std::ostream& os, const Expression& e){
        e.print(os);
        return os;
    }
    Const::Const(const Fraction& value){
        n = value;
    }
    void Const::print(std::ostream& os) const{
        os << n;
    }
    Fraction Const::evaluate() const{
        return n;
    }


    Negative::Negative(std::unique_ptr<Expression> operand){
        val = std::move(operand);
    }
    void Negative::print(std::ostream& os) const{
        os << "(-" << *val << ")";
    }
    Fraction Negative::evaluate() const{
        return -(val->evaluate());
    }

    BinaryExpression::BinaryExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs){
        left = std::move(lhs);
        right = std::move(rhs);
    }

    Add::Add(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs): BinaryExpression(std::move(lhs), std::move(rhs)){}
    void Add::print(std::ostream& os) const{
        os << "(" << *left << " + " << *right << ")";
    }
    Fraction Add::evaluate() const{
        return left->evaluate() + right->evaluate();
    } 

    Sub::Sub(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs): BinaryExpression(std::move(lhs), std::move(rhs)){}
    void Sub::print(std::ostream& os) const{
        os << "(" << *left << " - " << *right << ")";
    }
    Fraction Sub::evaluate() const{
        return left->evaluate() - right->evaluate();
    } 

    Mul::Mul(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs): BinaryExpression(std::move(lhs), std::move(rhs)){}
    void Mul::print(std::ostream& os) const{
        os << "(" << *left << " * " << *right << ")";
    }
    Fraction Mul::evaluate() const{
        return left->evaluate() * right->evaluate();
    } 

    Div::Div(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs): BinaryExpression(std::move(lhs), std::move(rhs)){}
    void Div::print(std::ostream& os) const{
        os << "(" << *left << " / " << *right << ")";
    }
    Fraction Div::evaluate() const{
        return left->evaluate() / right->evaluate();
    } 
}