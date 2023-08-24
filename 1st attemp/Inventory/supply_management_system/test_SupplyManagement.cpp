// g++ -std=c++17 .\test_SupplyManagement.cpp .\Supply.cpp .\SupplyManagement.cpp ..\util.cpp  -o .\test_SupplyManagement.exe
#include <iostream>
#include "SupplyManagement.h"

int main() {
    // SupplyManagement supplyManager;

    // Use the methods of the SupplyManagement class
    // supplyManager.offer_supply();
    // supplyManager.cancel_supply(0);
    // supplyManager.update_delivery_status(0);
    // supplyManager.accept_supply(0);

    // supplyManager.offer_supply();

    // // Retrieve and display supply details
    // Supply supply = supplyManager.read_supply_file(0);
    // std::cout << "Supply details:\n" << supply << std::endl;

    SupplyManagement supplyManager1;
    supplyManager1.offer_supply("hari", "rice", 10, 100, "food");
    Supply supply1 = SupplyManagement::read_supply_file(0);

    supplyManager1.offer_supply("xx", "rice", 10, 100, "food");
    supply1 = SupplyManagement::read_supply_file(1);

    supplyManager1.offer_supply("yy", "rice", 10, 100, "xx");
    supply1 = SupplyManagement::read_supply_file(2);

    std::vector <std::string> file_names = supplyManager1.get_all_supply_files();
    for (int i = 0; i < file_names.size(); i++){
        std::cout << file_names[i] << std::endl;
    }

    std::cout << "all test passed" << std::endl;
    return 0;
}
