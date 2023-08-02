#include "SupplyManagement.h"

void SupplyManagement::offer_supply(){
    Supply supply;
    supply.set_supply();
    // supplies.push_back(supply);
    std::cout << "Supply offered" << std::endl;
}

void SupplyManagement::offer_supply(std::string supplier_name_, std::string name_, std::string description_, float weight_, int price_, int quantity_, std::string category_){
    Supply supply;
    supply.set_supply(supplier_name_, name_, description_, weight_, price_, quantity_, category_);
    std::cout << "Supply offered" << std::endl;
}


void SupplyManagement::cancel_supply(long int supply_id){
    Supply supply = read_supply_file(supply_id);
    if (supply.get_is_delivered()){
        std::cout << "Supply already delivered" << std::endl;
        return;
    }
    supply.set_is_cancelled(true);
    std::cout << "Supply cancelled" << std::endl;
}

void SupplyManagement::update_delivery_status(long int supply_id){
    Supply supply = read_supply_file(supply_id);
    if(supply.get_is_cancelled()){
        std::cout << "Supply already delivered" << std::endl;
        return;
    }
    supply.set_is_delivered(true);
    supply.set_delivery_date(std::chrono::system_clock::now());
    std::cout << "Supply delivered" << std::endl;
}

void SupplyManagement::accept_supply(long int supply_id){
    Supply supply = read_supply_file(supply_id);
    if(supply.get_is_cancelled()){
        std::cout << "Supply already cancelled" << std::endl;
        return;
        }
    supply.set_is_accepted(true);
    std::cout << "Supply accepted" << std::endl;
}

Supply SupplyManagement::read_supply_file(long int supply_id){
    // for (int i = 0; i < supplies.size(); i++){
    //     if (supplies[i].get_supply_id() == supply_id){
    //         return supplies[i];
    //     }
    // }
    std::cout << "reading supply from management " << supply_id << std::endl;
    return Supply::read_supply_file(supply_id);
}

std::ostream& operator<<(std::ostream& os, const SupplyManagement& supply_management) {
    // for (auto supply: supply_management.supplies) {
    //     os << supply;
    // }
    os << "supplies: " << std::endl;
    // read_supply_file(0);
    return os;
}