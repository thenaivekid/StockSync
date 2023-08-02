#ifndef ORDERMANAGEMENT_H
#define ORDERMANAGEMENT_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "Order.h"

class OrderManagement {
private:
    // std::vector <Order> orders;

public:
    OrderManagement(){};

    static Order read_order_file(long int order_id);
    
    void place_order(); 

    void place_order(std::string customer_name_, std::string name_, std::string category_, int quantity_);

    void cancel_order(long int order_id);

    void update_delivery_status(long int order_id);
    
    friend std::ostream& operator<<(std::ostream& os, const OrderManagement& order);

    ~OrderManagement(){};
};

#endif