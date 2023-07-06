// g++ .\Item.cpp .\Order.cpp util.cpp .\test_Order.cpp -o .\test_Order.exe

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "util.h"
#include "Item.h"
#include "OrderManagement.h"
#include "Order.h"

int main(){
    Order o1;
    o1.set_order();
    std::cout << o1;

    std::cout << "Order ID: " << o1.get_order_id() << std::endl;
    std::cout << "Customer Name: " << o1.get_customer_name() << std::endl;
    std::cout << "Order date: " << get_printable_date(o1.get_order_date()) << std::endl;

    o1.set_is_delivered(true);
    o1.set_delivery_date();
    o1.set_is_cancelled(true);

    std::cout << o1;
    return 0;
}