#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H
#include <iostream>
#include <string>
#include <vector>
#include <Warehouse.h>
#include <OrderManagement.h>
#include 

class InventoryManagement{
private:
    std::vector <Warehouse> warehouses;
    std::vector <OrderManagement> orders;
    std::vector <SupplyManagement> supply;

    void add_warehouse();
    void remove_warehouse();
    void add_supply();
    void remove_supply();
    void add_order();
    void remove_order();
};
#endif