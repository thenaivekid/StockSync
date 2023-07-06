#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "util.h"
// #include "OrderManagement.h"

class ItemClient{
private:
    std::string name;
    int quantity;

public:
    ItemClient(){};

    ItemClient(std::string name_, int quantity_):name(name_), quantity(quantity_){};

    void set_item();

    std::string get_name();

    int get_quantity();

    ~ItemClient(){};
};


class Order {
private:
    static long int order_count;
    long int order_id;
    std::vector <ItemClient> items;
    //TODO add functionality to use user object instead of name
    std::string customer_name;
    bool is_delivered;
    bool is_cancelled;
    std::chrono::system_clock::time_point order_date;
    std::chrono::system_clock::time_point delivery_date;

public:
    Order(){};

    Order(std::vector <ItemClient> items_, std::string customer_name_, std::vector <ItemClient> itmes_)
    :order_id(order_count++), items(items_), customer_name(customer_name_), is_delivered(false), is_cancelled(false), order_date(std::chrono::system_clock::now()){
        delivery_date = std::chrono::system_clock::now() + std::chrono::hours(24 * 5);
    };

    void set_order();

    long int get_order_id();

    std::vector <ItemClient> get_items();

    std::string get_customer_name();

    bool get_is_delivered();

    bool get_is_cancelled();

    std::chrono::system_clock::time_point get_order_date();

    std::chrono::system_clock::time_point get_delivery_date();

    void set_is_delivered(bool b);

    void set_is_cancelled(bool b);

    void set_delivery_date();

    friend class OrderManagement;
    
    friend std::ostream& operator<<(std::ostream& os, const Order& order);

    ~Order(){};
};

#endif