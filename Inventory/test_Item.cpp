// g++ .\test_Item.cpp .\Item.cpp .\util.cpp -o .\test_Item.exe
#include <iostream>
#include <string>
#include <chrono>
#include "Item.h"
#include "util.h"

int main(){
    Item item;
    item.set_item();
    std::cout << item << std::endl;
    
    // Item item2("Item 2", "Item 2 description", 20, 200, 2, "Category 2", std::chrono::system_clock::now());
    // std::cout << item2 << std::endl;
    // std::cout << get_printable_date(item2.get_listed_date()) << std::endl;
    std::cout << "reading file" << std::endl;
    Item item3 = Item::read_item_file(0);

    return 0;
}