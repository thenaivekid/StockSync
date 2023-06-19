//g++ .\test_OrderManagement.cpp .\OrderManagement.cpp .\util.cpp  -o .\test_OrderManagement.exe
#include <iostream>
#include <string>
#include <vector>
#include "OrderManagement.h"

int main(){
    OrderManagement order1;
    order1.place_order();
    std::cout << order1 << std::endl;
    order1.update_status();
    std::cout << order1 << std::endl;
    order1.cancel_order();
    std::cout << order1 << std::endl;
}