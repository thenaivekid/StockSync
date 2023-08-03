// g++ .\Order.cpp ..\util.cpp .\test_Order.cpp -o .\test_Order.exe

#include "Order.h"

int main(){
    // Order o1;

    Order o2;
    o2.set_order("x", "product2", 2);
    std::cout << o2;

    Order::read_order_file(0);

    // std::cout << "Order ID: " << o1.get_order_id() << std::endl;
    // std::cout << "Customer Name: " << o1.get_customer_name() << std::endl;
    // std::cout << "Order date: " << get_printable_date(o1.get_order_date()) << std::endl;

    // o1.set_is_delivered(true);
    // // o1.set_delivery_date();
    // o1.set_is_cancelled(true);

    // std::cout << o1;
    std::cout << "order test done" << std::endl;

    return 0;
}