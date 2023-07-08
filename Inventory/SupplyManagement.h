#ifndef SUPPLYMANAGEMENT_H
#define SUPPLYMANAGEMENT_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "util.h"
#include "Item.h"
#include "Supply.h"


// FIXME MAKE A SUPPLY CLASS AND USE THIS CLASS TO MANAGE SUPPLIES
class SupplyManagement {
private:
    std::vector <Supply> supplies;

public:
    SupplyManagement(){};

    void offer_supply();

    Supply get_supply_by_id(long int supply_id);

    void cancel_supply(long int supply_id);

    void update_delivery_status(long int supply_id);

    void accept_supply(long int supply_id);

    ~SupplyManagement(){};

    friend std::ostream& operator<<(std::ostream& os, const SupplyManagement& supply);
};
#endif