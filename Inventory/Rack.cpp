#include "Rack.h"

int Rack::rack_count = 0;

void Rack::add_item(Item item){
    items.push_back(item);
}

void Rack::remove_item(Item item){
    long int id = item.get_id();
    for (int i = 0; i < items.size(); i++){
        if (items[i].get_id() == id){
            items.erase(items.begin() + i);
            break;
        }
    }
}

long int Rack::get_id(){
    return id;
}

std::ostream& operator<<(std::ostream &os, const Rack& rack){
    os << "Rack ID: " << rack.id << std::endl;
    os << "Items: " << std::endl;
    for (int i = 0; i < rack.items.size(); i++){
        os << rack.items[i] << std::endl;
    }
    return os;
}

std::vector <Item> Rack::get_items(){
    return items;
}