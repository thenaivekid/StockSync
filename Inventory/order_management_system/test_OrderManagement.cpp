//g++ .\test_OrderManagement.cpp .\Order.cpp .\OrderManagement.cpp ..\util.cpp  -o .\test_OrderManagement.exe
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
    order_management.place_order("customer1", "item1", "category1", 1);
    Order order1 = OrderManagement::read_order_file(0);
    std::cout << order1 << std::endl;

    std::cout << "showing orders 1" << std::endl;

    order_management.place_order("xx", "2324d", "category1", 3);
    order1 = OrderManagement::read_order_file(1);
    std::cout << order1 << std::endl;

    order_management.place_order("yy", "4", "cat3", 1);
    order1 = OrderManagement::read_order_file(2);
    std::cout << order1 << std::endl;

}