// g++ ..\Item.cpp .\test_SupplyManagement.cpp .\Supply.cpp .\SupplyManagement.cpp ..\util.cpp  -o .\test_SupplyManagement.exe
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
    supplyManager1.offer_supply("supplier1", "item1", "item1 description", 1.0, 100, 10, "category1");
    Supply supply1 = SupplyManagement::read_supply_file(0);
    return 0;
}
