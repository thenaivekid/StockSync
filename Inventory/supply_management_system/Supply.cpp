#include "Supply.h"

long int Supply::supply_count = 0;

void Supply::set_supply(){
    supply_id = supply_count++;
    is_cancelled = false;
    is_delivered = false;
    is_accepted = false;
    supply_date = std::chrono::system_clock::now();
    delivery_date = std::chrono::system_clock::now() + std::chrono::hours(24 * 5);
    std::cout << "Enter the name of the supplier: ";
    std::cin >> supplier_name;
    item.set_item();
    // std::cout << "Enter the items: " << std::endl;
    // char ch = 'y';
    // while(ch == 'y' || ch == 'Y'){
    //     Item item;
    //     item.set_item();
    //     items.push_back(item);
    //     std::cout << "Do you want to add more items? (y/n): ";
    //     std::cin >> ch;
    // }
    save_as_file();
}

void Supply::set_is_delivered(bool is_delivered_){
    is_delivered = is_delivered_;
    save_as_file();
}

void Supply::set_is_cancelled(bool is_cancelled_){
    is_cancelled = is_cancelled_;
    save_as_file();
}

void Supply::set_is_accepted(bool is_accepted_){
    is_accepted = is_accepted_;
    save_as_file();
}

Item Supply::get_item(){
    return item;
}

bool Supply::get_is_delivered(){
    return is_delivered;
}

bool Supply::get_is_cancelled(){
    return is_cancelled;
}

bool Supply::get_is_accepted(){
    return is_accepted;
}

void Supply::set_delivery_date(){
    delivery_date = get_date();
    save_as_file();
}

void Supply::set_delivery_date(std::chrono::system_clock::time_point date){
    delivery_date = date;
    save_as_file();
}

std::chrono::system_clock::time_point Supply::get_delivery_date(){
    return delivery_date;
}

std::chrono::system_clock::time_point Supply::get_supply_date(){
    return supply_date;
}

long int Supply::get_supply_id(){
    return supply_id;
}

void Supply::save_as_file() {
    std::ofstream file;
    file.open("supplies/" + std::to_string(supply_id) + ".txt", std::ios::binary);
    if(!file){
        std::cout << "Error opening file" << std::endl;
        return;
    }
    file.write(reinterpret_cast <char*> (this), sizeof(Supply));
    file.close();
    std::cout << "Supply saved to file" << std::endl;
}

Supply Supply::read_supply_file(long int supply_id){
    std::cout << "reading supply of id " << supply_id << std::endl;
    Supply supply;
    std::ifstream file;
    file.open("supplies/" + std::to_string(supply_id) + ".txt", std::ios::binary);
    if(!file){
        std::cout << "Error opening file" << std::endl;
        return supply;
    }
    file.read(reinterpret_cast <char*> (&supply), sizeof(Supply));
    file.close();       
    std::cout << supply;
    return supply;
}


std::ostream& operator<<(std::ostream& os, const Supply& supply){
    std::cout << "Supply Details: " << std::endl;
    os << "Supply ID: " << supply.supply_id << std::endl;
    os << "Supplier Name: " << supply.supplier_name << std::endl;
    os << "Supply Date: " << get_printable_date(supply.supply_date) << std::endl;
    os << "Delivery Date: " << get_printable_date(supply.delivery_date) << std::endl;
    os << "Items: " << std::endl;
    // for (auto item: supply.items){
    //     os << item;
    // }
    os << supply.item;
    return os;
}
