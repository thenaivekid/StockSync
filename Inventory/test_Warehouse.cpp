// g++ .\Item.cpp .\Rack.cpp .\Warehouse.cpp .\test_Warehouse.cpp util.cpp -o .\test_Warehouse.exe
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "Warehouse.h"
#include "Item.h"
#include "Rack.h"

int main(){
    Rack rack1;
    Item item1("Item 1", "Item 1 description", 10, 100, 1, "Category 1", std::chrono::system_clock::now());
    rack1.add_item(item1);

    Item item2("Item 2", "Item 2 description", 20, 200, 2, "Category 2", std::chrono::system_clock::now());
    rack1.add_item(item2);

    Rack rack2;
    Item item3("Item 1", "Item 1 description", 10, 100, 1, "Category 1", std::chrono::system_clock::now());
    rack2.add_item(item3);

    Item item4("Item 2", "Item 2 description", 20, 200, 2, "Category 2", std::chrono::system_clock::now());
    rack2.add_item(item4);

    Warehouse warehouse1("Warehouse 1", {rack1, rack2});

    std::cout << warehouse1 << std::endl;
}