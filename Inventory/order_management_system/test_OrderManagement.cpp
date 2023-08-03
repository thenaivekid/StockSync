//g++ .\test_OrderManagement.cpp .\OrderManagement.cpp ..\util.cpp .\Order.cpp -o .\test_OrderManagement.exe
#include <iostream>
#include <string>
#include <vector>
#include "OrderManagement.h"
#include "Order.h"

int main(){
    // OrderManagement order_management;
    // order_management.get_order_by_id(0);
    // order_management.place_order();
    // // order_management.place_order();

    // order_management.cancel_order(0);
    // order_management.update_delivery_status(0);


    // std::cout << "showing orders" << std::endl;
    // std::cout << order_management << std::endl;

    OrderManagement order_management;
    order_management.place_order("customer1", "product1", 1);
    std::cout << "hello" << std::endl;
    Order order1 = order_management.read_order_file(0);
    std::cout << order1 << std::endl;

    
    order_management.place_order("customer1", "product1", 1);
    std::cout << "hello" << std::endl;
    order1 = order_management.read_order_file(0);
    std::cout << order1 << std::endl;

    order_management.place_order("customer1", "product1", 1);
    std::cout << "hello" << std::endl;
    order1 = order_management.read_order_file(0);
    std::cout << order1 << std::endl;

}