//g++ .\test_OrderManagement.cpp .\Order.cpp .\OrderManagement.cpp .\util.cpp  -o .\test_OrderManagement.exe
#include <iostream>
#include <string>
#include <vector>
#include "OrderManagement.h"

int main(){
    OrderManagement order_management;
    order_management.place_order();
    order_management.place_order();

    order_management.cancel_order(1);
    order_management.update_delivery_status(2);

    std::cout << order_management << std::endl;
}