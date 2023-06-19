#ifndef ORDERMANAGEMENT_H
#define ORDERMANAGEMENT_H

#include <iostream>
#include <string>
#include <chrono>
#include <Item.h>
#include <vector>

class OrderManagement {
private:
    static long int order_count;
    int order_id;
    std::string name;
    //TODO add functionality to add multiple item objects to an order 
    std::vector <Item> items;
    //TODO add functionality to use user object instead of name
    std::string customer_name;
    bool is_delivered;
    bool is_cancelled;
    std::chrono::system_clock::time_point order_date;
    std::chrono::system_clock::time_point delivery_date;

public:
    OrderManagement(){};
    
    void place_order(); 
    void cancel_order();
    void update_status();
    
    friend std::ostream& operator<<(std::ostream& os, const OrderManagement& order);

    ~OrderManagement(){};
};

#endif