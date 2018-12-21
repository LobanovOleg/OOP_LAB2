#ifndef VECTOR_H
#define VECTOR_H

#include "Trapeze.h"

class TVector{
    public:

    TVector(int vector);
    void Push(Trapeze &tmp);
    Trapeze& Get(int index);
    void Delete();
    void Delete(int index);
    friend std::ostream& operator<<(std::ostream& os, const TVector& vector);
    ~TVector();
    int GetSize();

    private:
    Trapeze *ResizeVector(Trapeze *array);
    int size;
    int capacity;
    Trapeze *array;
};
#endif