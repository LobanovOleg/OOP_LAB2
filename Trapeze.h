#ifndef TRAPEZE_H
#define	TRAPEZE_H
#include <cstdlib>
#include <iostream>

class Trapeze {
public:
    Trapeze();
    Trapeze(size_t i,size_t j,size_t k);
    Trapeze(const Trapeze& orig);

    Trapeze& operator++();
    double Square();
    friend Trapeze operator+(const Trapeze& left, const Trapeze& right);
    friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
    friend std::istream& operator>>(std::istream& is, Trapeze& obj);
    Trapeze& operator=(const Trapeze& right);

    ~Trapeze();

    void SetSides (int a, int b, int h);
    friend class TVector;
private:
    size_t side_a;
    size_t side_b;
    size_t side_h;
};

#endif	/* TRAPEZE_H */