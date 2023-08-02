#ifndef SUPPLY_H
#define SUPPLY_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <fstream>
#include "../util.h"
#include "../Item.h"

class Supply {
private:
    static long int supply_count;
    long int supply_id;
    bool is_delivered;
    bool is_cancelled;
    bool is_accepted;
    // TODO: Add a supplier class
    std::string supplier_name;
    std::chrono::system_clock::time_point supply_date;
    std::chrono::system_clock::time_point delivery_date;
    // std::vector<Item> items;
    Item item;

public:
    Supply(){};

    Supply(Item item_)
    : item(item_) {
        supply_id = supply_count++;
        is_delivered = false;
        is_cancelled = false;
        is_accepted = false;
    }

    void set_supply();

    void set_is_delivered(bool is_delivered_);
    
    void set_is_cancelled(bool is_cancelled_);

    void set_is_accepted(bool is_accepted_);

    Item get_item();

    bool get_is_delivered();

    bool get_is_cancelled();

    bool get_is_accepted();

    void set_delivery_date();

    void set_delivery_date(std::chrono::system_clock::time_point date);

    std::chrono::system_clock::time_point get_delivery_date();

    std::chrono::system_clock::time_point get_supply_date();

    long int get_supply_id();

    void save_as_file();

    static Supply read_supply_file(long int supply_id);

    friend std::ostream& operator<<(std::ostream& os, const Supply& supply);

    ~Supply(){};

};

#endif