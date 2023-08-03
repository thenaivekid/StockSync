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

    Order read_order_file(long int order_id);
    
    void place_order(std::string customer_name_, std::string product_name_, int quantity_);
    // void place_order(); 


    // void cancel_order(long int order_id);

    // void update_delivery_status(long int order_id);
    
    friend std::ostream& operator<<(std::ostream& os, const OrderManagement& order);

    ~OrderManagement(){};
};

#endif