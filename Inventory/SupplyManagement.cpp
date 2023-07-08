#include "SupplyManagement.h"

void SupplyManagement::offer_supply(){
    Supply supply;
    supply.set_supply();
    supplies.push_back(supply);
    std::cout << "Supply offered" << std::endl;
}

void SupplyManagement::cancel_supply(long int supply_id){
    Supply supply = get_supply_by_id(supply_id);
    if (supply.get_is_delivered()){
        std::cout << "Supply already delivered" << std::endl;
        return;
    }
    supply.set_is_cancelled(true);
    std::cout << "Supply cancelled" << std::endl;
}

void SupplyManagement::update_delivery_status(long int supply_id){
    Supply supply = get_supply_by_id(supply_id);
    if(supply.get_is_cancelled()){
        std::cout << "Supply already delivered" << std::endl;
        return;
    }
    supply.set_is_delivered(true);
    supply.set_delivery_date(std::chrono::system_clock::now());
    std::cout << "Supply delivered" << std::endl;
}

void SupplyManagement::accept_supply(long int supply_id){
    Supply supply = get_supply_by_id(supply_id);
    if(supply.get_is_cancelled()){
        std::cout << "Supply already cancelled" << std::endl;
        return;
        }
    supply.set_is_accepted(true);
    std::cout << "Supply accepted" << std::endl;
}

Supply SupplyManagement::get_supply_by_id(long int supply_id){
    for (int i = 0; i < supplies.size(); i++){
        if (supplies[i].get_supply_id() == supply_id){
            return supplies[i];
        }
    }
}

std::ostream& operator<<(std::ostream& os, const SupplyManagement& supply_management) {
    for (auto supply: supply_management.supplies) {
        os << supply;
    }
    return os;
}