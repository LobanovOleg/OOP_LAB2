#include "Vector.h"
#include <stdlib.h>

const int INC = 1.5;

TVector::TVector(int vector){
    array = (Trapeze*)malloc(sizeof(Trapeze) * vector);
    size = 0;
    capacity = vector;
}

Trapeze *TVector::ResizeVector(Trapeze *array){
    return (Trapeze*)realloc(array, sizeof(Trapeze) * INC * capacity);
}

void TVector::Push(Trapeze &temp){
    if(size == capacity){
        array = ResizeVector(array);
    }
    array[size] = temp;
    size++;
    capacity *= INC;
}

Trapeze& TVector::Get(int index){
    return array[index];
}

void TVector::Delete(){
    array[--size].~Trapeze();
}

void TVector::Delete(int index){
    int i;
    int j;
    Trapeze *temp = (Trapeze*)malloc(sizeof(Trapeze) * (size - 1));
    for (j = 0, i = 0; i < size; ++i){
        if(i != index){
            temp[j] = array[i];
            j++;
        }
    }
    free(array);
    array = temp;
    --size;
}

TVector::~TVector(){
    free(array);
    array = NULL;
    capacity = size = 0;
}

std::ostream& operator<<(std::ostream& os, const TVector& vector){
    for(int i = 0; i < vector.size; i++){
        os << vector.array[i];
    }
    return os;
}

int TVector::GetSize(){
    return size;
}