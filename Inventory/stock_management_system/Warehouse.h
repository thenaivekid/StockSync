#ifndef Warehouse_H
#define Warehouse_H

#include <iostream>
#include <string>
#include <vector>
#include "..\Item.h"
// #include "Rack.h"

class Warehouse{
    private:
        // static int warehouse_count;
        // int id;
        std::string name;
        // std::vector<Rack> racks;

    public:
        Warehouse(){};

        // Warehouse(std::string name_, std::vector<Rack> racks_) : name(name_), racks(racks_){
        //     // id = warehouse_count++;
        // }
    void add_item(Item item);
    void remove_item(Item item);

    Item get_item_by_id(long int id);

    int get_id();

// TODO
    std::vector <Item> get_items_by_category();


        // void add_rack(Rack rack);

        // void remove_rack(Rack rack);
        

        // std::vector <Rack> get_racks();

        // Rack get_rack_by_id(long int id);

        ~Warehouse(){};

    friend std::ostream& operator<<(std::ostream& os, const Warehouse& warehouse);

};

#endif