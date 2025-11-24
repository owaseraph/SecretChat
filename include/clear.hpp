#ifndef CLEAR_HPP
#define CLEAR_HPP

#include <iostream>

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


#endif //CLEAR_HPP