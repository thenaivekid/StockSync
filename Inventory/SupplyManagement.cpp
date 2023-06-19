#include "SupplyManagement.h"

long int SupplyManagement::supply_count = 0;

void SupplyManagement::offer_supply(){
    supply_id = supply_count++;
    std::cout << "Enter name of supply: ";
    std::cin >> name;
    is_delivered = false;
    is_cancelled = false;
    std::cout << "Supply offered" << std::endl;
}

void SupplyManagement::cancel_supply(){
    if (is_delivered){
        std::cout << "Supply already delivered" << std::endl;
        return;
    }
    is_cancelled = true;
    std::cout << "Supply cancelled" << std::endl;
}

void SupplyManagement::update_status(){
    if(is_delivered){
        std::cout << "Supply already delivered" << std::endl;
        return;
        }
    is_delivered = true;
    delivery_date = std::chrono::system_clock::now();
    std::cout << "Supply delivered" << std::endl;
}

void SupplyManagement::accept_supply(){
    if(is_delivered){
        std::cout << "Supply already delivered" << std::endl;
        return;
        }
    is_accepted = true;
    std::cout << "Supply accepted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SupplyManagement& supply){
    os << "Supply ID: " << supply.supply_id << std::endl;
    os << "Name: " << supply.name << std::endl;
    os << "Is delivered: " << supply.is_delivered << std::endl;
    os << "Is cancelled: " << supply.is_cancelled << std::endl;
    if (supply.is_delivered)
        os << "Delivery Date: " << get_printable_date(supply.delivery_date) << std::endl;

    return os;
}