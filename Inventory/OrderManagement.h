#ifndef ORDERMANAGEMENT_H
#define ORDERMANAGEMENT_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "Order.h"
#include "util.h"

class OrderManagement {
private:
    std::vector <Order> orders;

public:
    OrderManagement(){};

    Order get_order_by_id(long int order_id);
    
    void place_order(); 

    void cancel_order(long int order_id);

    void update_delivery_status(long int order_id);
    
    friend std::ostream& operator<<(std::ostream& os, const OrderManagement& order);

    ~OrderManagement(){};
};

#endif