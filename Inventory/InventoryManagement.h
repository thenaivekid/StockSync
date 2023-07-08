#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H
#include <iostream>
#include <string>
#include <vector>
#include "Warehouse.h"
#include "OrderManagement.h"
#include "SupplyManagement.h"

class InventoryManagement{
private:
    std::vector <Warehouse> warehouses;

public:
    void add_warehouse();
    void remove_warehouse();
};
#endif