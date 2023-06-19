// g++ .\test_Item.cpp .\Item.cpp .\util.cpp -o .\test_Item.exe
#include <iostream>
#include <string>
#include <chrono>
#include "Item.h"

int main(){
    Item item;
    item.set_item();
    std::cout << item << std::endl;
    return 0;
}