// g++ .\Item.cpp .\Rack.cpp .\test_Rack.cpp util.cpp -o .\test_Rack.exe

#include "Rack.h"

int main() {
    Rack rack;
    Item item1("Item 1", "Item 1 description", 10, 100, 1, "Category 1", std::chrono::system_clock::now());
    rack.add_item(item1);

    Item item2("Item 2", "Item 2 description", 20, 200, 2, "Category 2", std::chrono::system_clock::now());
    rack.add_item(item2);

    std::cout << rack << std::endl;
    return 0;
}