#include "ratexpr/fraction.hpp"
#include <numeric>
#include <stdexcept>
#include <iostream>
namespace ratexpr{
    Fraction::Fraction(){
        chisl = 0;
        zn = 1;
    }
    Fraction::Fraction(std::int64_t numerator, std::int64_t denominator){
        if(denominator == 0){
            throw std::invalid_argument("Division by zero");
        }
        std::int64_t nod = std::gcd(numerator, denominator);
        chisl = numerator / nod;
        zn = denominator / nod;
        if (zn < 0){
            zn = zn * (-1);
            chisl = chisl * (-1);
        }
    }
    Fraction& Fraction::operator+=(const Fraction& o){
        chisl = chisl * o.zn + o.chisl * zn;
        zn = zn * o.zn;
        std::int64_t nod = std::gcd(chisl, zn);
        chisl = chisl / nod;
        zn = zn / nod;
        return *this;
    }
    Fraction& Fraction::operator-=(const Fraction& o){
        chisl = chisl * o.zn - o.chisl * zn;
        zn = zn * o.zn;
        std::int64_t nod = std::gcd(chisl, zn);
        chisl = chisl / nod;
        zn = zn / nod;
        return *this;
    }
    Fraction& Fraction::operator*=(const Fraction& o){
        chisl *= o.chisl;
        zn *= o.zn;
        std::int64_t nod = std::gcd(chisl, zn);
        chisl = chisl / nod;
        zn = zn / nod;
        return *this;
    }
    Fraction& Fraction::operator/=(const Fraction& o){
        if (o.chisl == 0){
            throw std::invalid_argument("Division by zero");
        }
        chisl *= o.zn;
        zn *= o.chisl;
        std::int64_t nod = std::gcd(chisl, zn);
        chisl = chisl / nod;
        zn = zn / nod;
        return *this;
    }
    Fraction& Fraction::operator+=(std::uint32_t k){
        *this += Fraction(k);
        return *this;
    }
    Fraction& Fraction::operator-=(std::uint32_t k){
        *this -= Fraction(k);
        return *this;
    }
    Fraction& Fraction::operator*=(std::uint32_t k){
        *this *= Fraction(k);
        return *this;
    }
    Fraction& Fraction::operator/=(std::uint32_t k){
        if (k == 0){
            throw std::invalid_argument("Division by zero");
        }
        *this /= Fraction(k);
        return *this;
    }
    Fraction Fraction::operator-() const{
        return Fraction(-chisl, zn);
    }
    Fraction operator+(const Fraction& a, const Fraction& b){
        Fraction c = a;
        c += b;
        return c;
    }
    Fraction operator-(const Fraction& a, const Fraction& b){
        Fraction c = a;
        c -= b;
        return c;
    }
    Fraction operator*(const Fraction& a, const Fraction& b){
        Fraction c = a;
        c *= b;
        return c;
    }
    Fraction operator/(const Fraction& a, const Fraction& b){
        if(b.chisl == 0){
            throw std::invalid_argument("Division by zero");
        }
        Fraction c = a;
        c /= b;
        return c;
    }

    Fraction operator+(const Fraction& a, std::uint32_t k){
        Fraction c = a;
        Fraction b(k);
        c += b;
        return c;
    }
    Fraction operator-(const Fraction& a, std::uint32_t k){
        Fraction c = a;
        Fraction b(k);
        c -= b;
        return c;
    }
    Fraction operator*(const Fraction& a, std::uint32_t k){
        Fraction c = a;
        Fraction b(k);
        c *= b;
        return c;
    }
    Fraction operator/(const Fraction& a, std::uint32_t k){
        if(k == 0){
            throw std::invalid_argument("Division by zero");
        }
        Fraction c = a;
        Fraction b(k);
        c /= b;
        return c;
    }

    Fraction operator+(std::uint32_t k, const Fraction& b){
        Fraction c = b;
        Fraction h(k);
        c += h;
        return c;
    }
    Fraction operator-(std::uint32_t k, const Fraction& b){
        Fraction c = b;
        Fraction h(k);
        h -= c;
        return h;
    }
    Fraction operator*(std::uint32_t k, const Fraction& b){
        Fraction c = b;
        Fraction h(k);
        c *= h;
        return c;
    }
    Fraction operator/(std::uint32_t k, const Fraction& b){
        if(b.chisl == 0){
            throw std::invalid_argument("Division by zero");
        }
        Fraction c = b;
        Fraction h(k);
        h /= c;
        return h;
    }
    std::ostream& operator<<(std::ostream& os, const Fraction& f){
        std::int64_t z, c;
        if (f.zn < 0){
            z = f.zn * (-1);
            c = f.chisl * (-1);
        }
        else {
            z = f.zn;
            c = f.chisl;
        }
        if (f.zn == 1){
            return os << c;
        }
        return os << c << "/" << z;
    }
}