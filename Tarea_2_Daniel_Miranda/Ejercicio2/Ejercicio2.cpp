#include <iostream>

int TurnToPositive(int *pointer, int iter = 0){
    if (iter != 10){
        std::cout << "Before: " << *pointer << std::endl;
        if (*pointer < 0){
            *pointer = *pointer * -1;
            std::cout << "After: " << *pointer << std::endl;
        }
        pointer++;
        iter++;
        TurnToPositive(pointer, iter);
    }
    return 0;

}

int main(){
    int *ptr = new int[10];
    *ptr = 10;
    *(ptr+1) = -1 ;
    *(ptr+2) = -2 ;
    *(ptr+3) = -3 ;
    *(ptr+4) = -4 ;
    *(ptr+5) = -5 ;
    *(ptr+6) = -6 ;
    *(ptr+7) = -7 ;
    *(ptr+8) = -8 ;
    *(ptr+9) = -9 ;
    TurnToPositive(ptr);
    delete[] ptr;
}