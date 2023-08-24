#include "Order.h"

long int Order::order_count = 0;

// void Order::set_order(){
//     order_id = order_count++;
//     is_cancelled = false;
//     is_delivered = false;
//     order_date = std::chrono::system_clock::now();
//     delivery_date = std::chrono::system_clock::now() + std::chrono::hours(24 * 5);
//     std::cout << "Enter the name of the customer: ";
//     std::cin >> customer_name;
//     // std::cout << "Enter the items: " << std::endl;
//     item.set_item();
//     std::cout << "new order created" << std::endl;

//     save_to_file();

// }

void Order::set_order(std::string customer_name_, std::string product_name_, int quantity_){
    order_id = order_count++;
    is_cancelled = false;
    is_delivered = false;
    order_date = std::chrono::system_clock::now();
    delivery_date = std::chrono::system_clock::now() + std::chrono::hours(24 * 5);
    customer_name = customer_name_;
    product_name = product_name_;
    quantity = quantity_;
    std::cout << "new order created" << std::endl;
    save_to_file();
}

long int Order::get_order_id(){
    return order_id;
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
    save_to_file();
}

void Order::set_is_cancelled(bool b){
    is_cancelled = b;
    std::cout << "is_cancelled set to " << b << std::endl;
    save_to_file();
}

void Order::set_delivery_date(){
    delivery_date = get_date();
    save_to_file();
}


void Order::save_to_file() {
    std::ofstream file;
    file.open("orders/" + std::to_string(order_id) + ".txt", std::ios::binary);
    if(!file){
        std::cout << "Error opening file" << std::endl;
        return;
    }
    // file.write(reinterpret_cast <char*> (this), sizeof(Order));

    std::string::size_type customerNameSize = customer_name.size();
    file.write(reinterpret_cast<const char*>(&customerNameSize), sizeof(customerNameSize));
    file.write(customer_name.c_str(), customerNameSize);

    file.write(reinterpret_cast<const char*>(&is_delivered), sizeof(is_delivered));
    file.write(reinterpret_cast<const char*>(&is_cancelled), sizeof(is_cancelled));

    file.write(reinterpret_cast<const char*>(&order_date), sizeof(order_date));
    file.write(reinterpret_cast<const char*>(&delivery_date), sizeof(delivery_date));

    std::string::size_type productNameSize = product_name.size();
    file.write(reinterpret_cast<const char*>(&productNameSize), sizeof(productNameSize));
    file.write(product_name.c_str(), productNameSize);

    file.write(reinterpret_cast<const char*>(&quantity), sizeof(quantity));

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
    // file.read(reinterpret_cast <char*> (&order), sizeof(order));
    
        // Read customer_name
    
    std::string::size_type customerNameSize;
    file.read(reinterpret_cast<char*>(&customerNameSize), sizeof(customerNameSize));
    char customerNameBuffer[100];
    file.read(customerNameBuffer, customerNameSize);
    customerNameBuffer[customerNameSize] = '\0';
    order.customer_name = std::string(customerNameBuffer);



    file.read(reinterpret_cast<char*>(&order.is_delivered), sizeof(order.is_delivered));
    file.read(reinterpret_cast<char*>(&order.is_cancelled), sizeof(order.is_cancelled));


    // Read order_date and delivery_date
    file.read(reinterpret_cast<char*>(&order.order_date), sizeof(order.order_date));
    file.read(reinterpret_cast<char*>(&order.delivery_date), sizeof(order.delivery_date));


    // Read product_name
    std::string::size_type productNameSize;
    file.read(reinterpret_cast<char*>(&productNameSize), sizeof(productNameSize));
    char productNameBuffer[100];
    file.read(productNameBuffer, productNameSize);
    productNameBuffer[productNameSize] = '\0';
    order.product_name = std::string(productNameBuffer);

    file.read(reinterpret_cast<char*>(&order.quantity), sizeof(order.quantity));

    file.close(); 
    std::cout << "Order read from file from order" << std::endl;      
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
    os << "Product Name: " << order.product_name << std::endl;
    os << "Quantity: " << order.quantity << std::endl;
    return os;
}

// std::ostream& operator<<(std::ostream& os, const Order& order){
//     os << "Order ID: " << order.order_id << std::endl;
// }


int main() {
    Order order1;
    order1.set_order("ashok","nitro5", 69);
    std::cout << order1;
    return 0;

}