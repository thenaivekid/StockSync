#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "../util.h"
#include <fstream>
// #include "Payment.h"
#include <limits>

class ItemClient{
    // TODO: inherit from the item class
private:
    std::string name;
    std::string category;
    int quantity;

public:
    ItemClient(){};

    ItemClient(std::string name_, int quantity_):name(name_), quantity(quantity_){};

    void set_item();

    void set_item(std::string name_, std::string category_, int quantity_);

    std::string get_name();

    std::string get_category();

    int get_quantity();

    ~ItemClient(){};
};


class Order {
private:
    static long int order_count;
    long int order_id;
    // std::vector <ItemClient> items;
    ItemClient item;
    //TODO add functionality to use user object instead of name
    std::string customer_name;
    bool is_delivered;
    bool is_cancelled;
    std::chrono::system_clock::time_point order_date;
    std::chrono::system_clock::time_point delivery_date;

public:
    Order(){};

    Order(ItemClient item_, std::string customer_name_)
    :order_id(order_count++), item(item_), customer_name(customer_name_), is_delivered(false), is_cancelled(false), order_date(std::chrono::system_clock::now()){
        delivery_date = std::chrono::system_clock::now() + std::chrono::hours(24 * 5);
    };

    void set_order();

    void set_order(std::string customer_name_, std::string name_, std::string category_, int quantity_); 

    long int get_order_id();

    ItemClient get_item();

    std::string get_customer_name();

    bool get_is_delivered();

    bool get_is_cancelled();

    std::chrono::system_clock::time_point get_order_date();

    std::chrono::system_clock::time_point get_delivery_date();

    void set_is_delivered(bool b);

    void set_is_cancelled(bool b);

    void set_delivery_date();

    void save_as_file();

    static Order read_order_file(long int order_id);
    
    friend std::ostream& operator<<(std::ostream& os, const Order& order);

    ~Order(){};
};

#endif