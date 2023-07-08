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
    std::cout << "Enter the items: " << std::endl;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        Item item;
        item.set_item();
        items.push_back(item);
        std::cout << "Do you want to add more items? (y/n): ";
        std::cin >> ch;
    }
}

void Supply::set_is_delivered(bool is_delivered_){
    is_delivered = is_delivered_;
}

void Supply::set_is_cancelled(bool is_cancelled_){
    is_cancelled = is_cancelled_;
}

void Supply::set_is_accepted(bool is_accepted_){
    is_accepted = is_accepted_;
}

std::vector <Item> Supply::get_items(){
    return items;
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
}

void Supply::set_delivery_date(std::chrono::system_clock::time_point date){
    delivery_date = date;
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

std::ostream& operator<<(std::ostream& os, const Supply& supply){
    os << "Supply ID: " << supply.supply_id << std::endl;
    os << "Supplier Name: " << supply.supplier_name << std::endl;
    os << "Supply Date: " << get_printable_date(supply.supply_date) << std::endl;
    os << "Delivery Date: " << get_printable_date(supply.delivery_date) << std::endl;
    os << "Items: " << std::endl;
    for (auto item: supply.items){
        os << item;
    }
}
