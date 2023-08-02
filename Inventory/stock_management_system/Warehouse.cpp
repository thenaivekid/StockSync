#include "Warehouse.h"

int Warehouse::warehouse_count = 0;

void Warehouse::add_rack(Rack rack){
    racks.push_back(rack);
}

void Warehouse::remove_rack(Rack rack){
    int rack_id = rack.get_id();
    for(int i = 0; i < racks.size(); i++){
        if(racks[i].get_id() == rack_id){
            racks.erase(racks.begin() + i);
            break;
        }
    }
}

int Warehouse::get_id(){
    return id;
}

std::vector <Rack> Warehouse::get_racks(){
    return racks;
}

Rack Warehouse::get_rack_by_id(long int id){
    for(int i = 0; i < racks.size(); i++){
        if(racks[i].get_id() == id){
            return racks[i];
        }
    }
}
std::ostream& operator<<(std::ostream& os, const Warehouse& warehouse){
    os << "Warehouse ID: " << warehouse.id << std::endl;
    os << "Warehouse Name: " << warehouse.name << std::endl;
    os << "Racks: " << std::endl;
    for(int i = 0; i < warehouse.racks.size(); i++){
        os << warehouse.racks[i] << std::endl;
    }
    return os;
}