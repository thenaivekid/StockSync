//  g++ .\test_Supply.cpp ..\Item.cpp .\Supply.cpp ..\util.cpp -o .\test_Supply.exe
#include <iostream>
#include "Supply.h"

int main() {
    Supply sup1;
    sup1.set_supply();
    Supply::read_supply_file(0);
    // std::cout << sup1 << std::endl;
    return 0;
}
