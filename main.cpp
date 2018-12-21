#include <cstdlib>
#include <iostream>

#include "Trapeze.h"
#include "Vector.h"

void navigate();

int main(){
    int key;
    int index;
    int a = 0;
    int b = 0;
    int h = 0;
    Trapeze tmp;

    TVector vector(5);
    do{
        navigate();
        std::cin >> key;
        switch(key){
            case 1:
                std::cout << "Введите стороны трапеции" << std::endl;
                std::cin >> a >> b >> h;
                tmp.SetSides(a, b, h);
                vector.Push(tmp);
                break;
            case 2:
                std::cout << "Введите индекс Трапеции" << std::endl;
                std::cin >> index;
                if(index >= vector.GetSize()){
                    std::cout << "Трапеции нет" << std::endl;
                } else {
                    std::cout << vector.Get(index) << std::endl;
                    std::cout << vector.Get(index).Square() << std::endl;
                }
                break;
            case 3:
                std::cout << "Введите индекс" << std::endl;
                std::cin >> index;
                vector.Delete(index);
                break;
            case 4:
                vector.~TVector();
                key = 0;
                break;
            case 5:
                std::cout << vector << std::endl;
                break;
            case 0:
                break;
            default:
                std::cout << "Такой команды нет" << std::endl;
                break;    
        }
    } while(key);
    return 0;
}

void navigate(){
    std::cout << "Введите команду" << std::endl;
    std::cout << "1) Добавить трапеция" << std::endl;
    std::cout << "2) Введите индекс" << std::endl;
    std::cout << "3) Введите индекс для удаления" << std::endl;
    std::cout << "4) Удалить" << std::endl;
    std::cout << "5) Напечатать все трапеции" << std::endl;
    std::cout << "0) Выход" << std::endl;
}