#include "OrderManagement.h"
#include "util.h"

void OrderManagement::place_order() {
    order_id = order_count++;
    std::cout << "Enter the name of the item: ";
    std::cin >> name;
    std::cout << "Enter the customer name: ";
    std::cin >> customer_name;
    is_delivered = false;
    is_cancelled = false;
    order_date = std::chrono::system_clock::now();
    std::cout << "Order placed" << std::endl;
}

void OrderManagement::cancel_order() {
    if (is_delivered) {
        std::cout << "Order already delivered" << std::endl;
        return;
    }
    is_cancelled = true;
    std::cout << "Order cancelled" << std::endl;
}

void OrderManagement::update_status() {
    if (is_delivered) {
        std::cout << "Order already delivered" << std::endl;
        return;
    }
    is_delivered = true;
    delivery_date = std::chrono::system_clock::now();
    std::cout << "Order status updated" << std::endl;
}

long int OrderManagement::order_count = 0;

std::ostream& operator<<(std::ostream& os, const OrderManagement& order) {
    os << "Order ID: " << order.order_id << std::endl;
    os << "Item: " << order.name << std::endl;
    os << "Customer Name: " << order.customer_name << std::endl;
    os << "Is delivered: " << order.is_delivered << std::endl;
    os << "Is cancelled: " << order.is_cancelled << std::endl;
    os << "Order Date: " << get_printable_date(order.order_date) << std::endl;
    if (order.is_delivered)
        os << "Delivery Date: " << get_printable_date(order.delivery_date) << std::endl;

    return os;
}