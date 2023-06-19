#ifndef RACK_H
#define RACK_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

class Rack{
private:
    static int rack_count;
    int id;
    std::vector <Item> items;

public:
    void add_item(Item item);
    void remove_item(Item item);

    std::vector <Item> get_items();
    int get_id();

    ~Rack(){};
};

#endif