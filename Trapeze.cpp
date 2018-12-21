#include "Trapeze.h"
#include <iostream>
#include <cmath>

Trapeze::Trapeze() : Trapeze(0, 0, 0) {
}

Trapeze::Trapeze(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_h(k) {
    std::cout << "Trapeze created: " << side_a << ", " << side_b << ", " << side_h << std::endl;
}

Trapeze::Trapeze(const Trapeze& orig){
    std::cout << "Trapeze copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_h = orig.side_h;
}

double Trapeze::Square() {
     return ((side_a + side_b)*side_h);

}

Trapeze& Trapeze::operator=(const Trapeze& right){
    if (this == &right) return *this;

    std::cout << "Trapeze copied" << std::endl;
    side_a = right.side_a;
    side_b = right.side_b;
    side_h = right.side_h;

    return *this; 
}

Trapeze& Trapeze::operator++(){
    side_a++;
    side_b++;
    side_h++;

    return *this;
}

Trapeze operator+(const Trapeze& left, const Trapeze& right){
    return Trapeze(left.side_a+right.side_a, left.side_b+right.side_b, left.side_h+right.side_h);
}

Trapeze::~Trapeze(){
    std::cout << "Trapeze deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj){
    os << "a=" << obj.side_a << ", b=" << obj.side_b << ", h=" << obj.side_h << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Trapeze& obj){
    is >> obj.side_a;
    is >> obj.side_b;
    is >> obj.side_h;

    return is;
}

void Trapeze::SetSides(int a, int b, int h){
    side_a = a;
    side_b = b;
    side_h = h;
}