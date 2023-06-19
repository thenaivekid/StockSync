#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Rack.h"

class Warehouse{
private:
    static int WarehouseCount;
    int id;
    std::string name;
    std::vector<Rack> racks;

    #TODO

};

#endif