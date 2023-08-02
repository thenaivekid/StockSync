#include "Order.h"

std::string ItemClient::get_name(){
    return name;
}

std::string ItemClient::get_category(){
    return category;
}


int ItemClient::get_quantity(){
    return quantity;
}

void ItemClient::set_item(){
    std::cout << "Enter the name of the item: ";
    std::cin >> name;
    std::cout << "Enter the category of the item: ";
    std::cin >> category;
    std::cout << "Enter the quantity of the item[only integers]: ";
    int number;
    std::cin >> number;
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid integer. Set to 1 by default" << std::endl;
        std::cin.clear();
        quantity = 1;


    } else {
        quantity = number;
    }
}

void ItemClient::set_item(std::string name_, std::string category_, int quantity_){
    name = name_;
    category = category_;
    quantity = quantity_;
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
    // std::cout << "Enter the items: " << std::endl;
    item.set_item();
    std::cout << "new order created" << std::endl;

    save_as_file();

}

void Order::set_order(std::string customer_name_, std::string name_, std::string category_, int quantity_){
    order_id = order_count++;
    is_cancelled = false;
    is_delivered = false;
    order_date = std::chrono::system_clock::now();
    delivery_date = std::chrono::system_clock::now() + std::chrono::hours(24 * 5);
    customer_name = customer_name_;
    item.set_item(name_, category_, quantity_);
    std::cout << "new order created" << std::endl;

    save_as_file();

}

long int Order::get_order_id(){
    return order_id;
}

ItemClient Order::get_item(){
    return item;
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
    std::cout << "is_delivered set to " << b << std::endl;
    save_as_file();
}

void Order::set_is_cancelled(bool b){
    is_cancelled = b;
    std::cout << "is_cancelled set to " << b << std::endl;
    save_as_file();
}

void Order::set_delivery_date(){
    delivery_date = get_date();
    save_as_file();
}


void Order::save_as_file() {
    std::ofstream file;
    file.open("orders/" + std::to_string(order_id) + ".txt", std::ios::binary);
    if(!file){
        std::cout << "Error opening file" << std::endl;
        return;
    }
    file.write(reinterpret_cast <char*> (this), sizeof(Order));
    file.close();
    std::cout << "Order saved to file" << std::endl;
}

Order Order::read_order_file(long int order_id){
    std::cout << "reading order of id " << order_id << std::endl;
    Order order;
    std::ifstream file;
    file.open("orders/" + std::to_string(order_id) + ".txt", std::ios::binary);
    if(!file){
        std::cout << "Error opening file" << std::endl;
        return order;
    }
    file.read(reinterpret_cast <char*> (&order), sizeof(order));
    file.close();       
    std::cout << order;
    return order;
    }


std::ostream& operator<<(std::ostream& os, const Order& order){
    os << "Order ID: " << order.order_id << std::endl;
    os << "Customer Name: " << order.customer_name << std::endl;
    os << "Is delivered: " << order.is_delivered << std::endl;
    os << "Is cancelled: " << order.is_cancelled << std::endl;
    os << "Order Date: " << get_printable_date(order.order_date) << std::endl;
    os << "Delivery Date: " << get_printable_date(order.delivery_date) << std::endl;
    os << "Items: " << std::endl;
    // for (auto item : order.items){
    //     os << "name: " << item.get_name() << std::endl;
    //     os << "quantity: " << item.get_quantity() << std::endl;
    // }
    ItemClient item = order.item;
    os << item.get_name() << std::endl;
    os << item.get_category() << std::endl;
    os << item.get_quantity() << std::endl;
    return os;
}

// std::ostream& operator<<(std::ostream& os, const Order& order){
//     os << "Order ID: " << order.order_id << std::endl;
// }