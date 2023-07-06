#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Rack.h"

class Warehouse{
    private:
        static int warehouse_count;
        int id;
        std::string name;
        std::vector<Rack> racks;

    public:
        Warehouse(){};

        Warehouse(std::string name_, std::vector<Rack> racks_) : name(name_), racks(racks_){
            id = warehouse_count++;
        }

        void add_rack(Rack rack);

        void remove_rack(Rack rack);
        
        int get_id();

        std::vector <Rack> get_racks();

        ~Warehouse(){};
    // TODO getter

    friend std::ostream& operator<<(std::ostream& os, const Warehouse& warehouse);

};

#endif