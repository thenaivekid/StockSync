#include "Order.h"

std::string ItemClient::get_name(){
    return name;
}

int ItemClient::get_quantity(){
    return quantity;
}

void ItemClient::set_item(){
    std::cout << "Enter the name of the item: ";
    std::cin >> name;
    std::cout << "Enter the quantity of the item: ";
    std::cin >> quantity;
}

long int Order::order_count = 0;

void Order::set_order(){
    order_id = order_count++;
    is_cancelled = false;
    is_delivered = false;
    order_date = std::chrono::system_clock::now();
    delivery_date = std::chrono::system_clock::now() + std::chrono::hours(24 * 5);
    std::cout << "Enter the name of the customer: ";
    std::cin >> customer_name;
    std::cout << "Enter the items: " << std::endl;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        ItemClient item;
        item.set_item();
        items.push_back(item);
        std::cout << "Do you want to add more items? (y/n): ";
        std::cin >> ch;
    }
}

long int Order::get_order_id(){
    return order_id;
}

std::vector <ItemClient> Order::get_items(){
    return items;
}

std::string Order::get_customer_name(){
    return customer_name;
}

bool Order::get_is_delivered(){
    return is_delivered;
}

bool Order::get_is_cancelled(){
    return is_cancelled;
}

std::chrono::system_clock::time_point Order::get_order_date(){
    return order_date;
}

std::chrono::system_clock::time_point Order::get_delivery_date(){
    return delivery_date;
}

void Order::set_is_delivered(bool b){
    is_delivered = b;
}

void Order::set_is_cancelled(bool b){
    is_cancelled = b;
}

void Order::set_delivery_date(){
    delivery_date = get_date();
}

std::ostream& operator<<(std::ostream& os, const Order& order){
    os << "Order ID: " << order.order_id << std::endl;
    os << "Customer Name: " << order.customer_name << std::endl;
    os << "Is delivered: " << order.is_delivered << std::endl;
    os << "Is cancelled: " << order.is_cancelled << std::endl;
    os << "Order Date: " << get_printable_date(order.order_date) << std::endl;
    os << "Delivery Date: " << get_printable_date(order.delivery_date) << std::endl;
    os << "Items: " << std::endl;
    for (auto item : order.items){
        os << item.get_name() << std::endl;
        os << item.get_quantity() << std::endl;
    }
    return os;
}