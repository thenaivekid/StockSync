// g++ -std=c++17 ..\Item.cpp .\Warehouse.cpp .\WarehouseItem.cpp .\test_Warehouse.cpp ..\util.cpp -o .\test_Warehouse.exe
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "Warehouse.h"
#include "../Item.h"

int main(){
//     Rack rack1;
//     Item item1("Item 1", "Item 1 description", 10, 100, 1, "Category 1", std::chrono::system_clock::now());
//     rack1.add_item(item1);

//     Item item2("Item 2", "Item 2 description", 20, 200, 2, "Category 2", std::chrono::system_clock::now());
//     rack1.add_item(item2);

//     Rack rack2;
//     Item item3("Item 1", "Item 1 description", 10, 100, 1, "Category 1", std::chrono::system_clock::now());
//     rack2.add_item(item3);

//     Item item4("Item 2", "Item 2 description", 20, 200, 2, "Category 2", std::chrono::system_clock::now());
//     rack2.add_item(item4);

//     Warehouse warehouse1("Warehouse 1", {rack1, rack2});

//     std::cout << warehouse1 << std::endl;
    Warehouse warehouse1;
    warehouse1.add_item("Item 1", "Item 1 description", 10, 100, 1, "Category 1");
    WarehouseItem item = warehouse1.read_item_file(0);
    std::cout << item << std::endl;

    warehouse1.add_item("Item 2", "Item 2description", 10, 69, 1, "Category 1");
    item = warehouse1.read_item_file(1);
    std::cout << item << std::endl;

    warehouse1.add_item("Item x", "Item on", 10, 100, 1, "cat 2");
    item = warehouse1.read_item_file(2);
    std::cout << item << std::endl;

    std::vector <std::string> file_names = warehouse1.get_all_item_files();
    for (int i = 0; i < file_names.size(); i++){
        std::cout << file_names[i] << std::endl;
    }

    std::cout << "all test passed" << std::endl;
}