#ifndef SUPPLY_H
#define SUPPLY_H

#include <iostream>
#include <string>
#include <chrono>
#include <Item.h>
#include <vector>
#include "util.h"

class SupplyManagement {
private:
    static long int supply_count;
    int supply_id;
    std::string name;
    //TODO add functionality to add multiple item objects to an supply 
    std::vector <Item> items;
    //TODO add functionality to use user object instead of name
    std::string supplier_name;
    //TODO add functionality to use address object instead of address
    bool is_delivered;
    bool is_accepted;
    bool is_cancelled;
    std::chrono::system_clock::time_point delivery_date;

public:
    void offer_supply();
    void cancel_supply();
    void update_status();
    void accept_supply();

    ~SupplyManagement(){};

    friend std::ostream& operator<<(std::ostream& os, const SupplyManagement& supply);
};
#endif