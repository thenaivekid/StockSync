#ifndef Item_h
#define Item_h

#include <iostream>
#include <string>
#include <chrono>

class Item {
private:
    static long int item_count;
    long int item_id;
    std::string name;
    std::string description;
    float weight;
    int price;
    int quantity;
    std::string category;
    std::chrono::system_clock::time_point listed_date;
    std::chrono::system_clock::time_point expiration_date;

public:
    Item(){};    

    void set_item(); 

    ~Item(){};

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};


#endif