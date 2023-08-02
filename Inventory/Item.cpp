#include "Item.h"
#include "util.h"

Item::Item(std::string name_, std::string description_, float weight_, int price_, int quantity_, std::string category_, std::chrono::system_clock::time_point expiration_date_)
: name(name_), description(description_), weight(weight_), price(price_), quantity(quantity_), category(category_), expiration_date(expiration_date_) {
    item_id = item_count++;
    listed_date = std::chrono::system_clock::now();
    save_to_file();
}

void Item::set_item() {
    item_id = item_count++;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
    std::cout << "Enter weight (in kg): ";
    std::cin >> weight;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cout << "Enter category: ";
    std::cin >> category;
    listed_date = std::chrono::system_clock::now();
    std::cout << "Enter expiry date (YYYY-MM-DD): ";
    expiration_date = get_date();
    std::cout << get_printable_date(expiration_date) << std::endl;
    std::cout << "Item added" << std::endl;
    save_to_file();
}

void Item::set_item(std::string name_, std::string description_, float weight_, int price_, int quantity_, std::string category_){
    item_id = item_count++;
    name = name_;
    description = description_;
    weight = weight_;
    price = price_;
    quantity = quantity_;
    category = category_;
    listed_date = std::chrono::system_clock::now();
    save_to_file();
}

long int Item::get_id() {
    return item_id;
}

long int Item::item_count = 0;

float Item::get_weight(){
    return weight;
}

int Item::get_price(){
    return price;
}

int Item::get_quantity(){
    return quantity;
}

std::string Item::get_category(){
    return category;
}

std::chrono::system_clock::time_point Item::get_listed_date(){
    return listed_date;
}

std::chrono::system_clock::time_point Item::get_expiration_date(){
    return expiration_date;
}

void Item::save_to_file(){
    std::ofstream file;
    file.open("items/" + std::to_string(item_id) + ".txt", std::ios::binary);
    if(!file){
        std::cout << "Error opening file" << std::endl;
        return;
    }
    file.write(reinterpret_cast <char*>(this), sizeof(Item));
    file.close();
    std::cout << "Item saved to file" << std::endl;
}

Item Item::read_item_file(long int item_id_){
    std::cout << "Reading item file " << item_id_ << std::endl;
    std::ifstream file;
    Item item;
    file.open("items/" + std::to_string(item_id_) + ".txt", std::ios::binary);
    if(!file){
        std::cout << "Error opening file" << std::endl;
        return item;
    }
    file.read(reinterpret_cast <char*> (&item), sizeof(Item));
    file.close();
    std::cout << item << std::endl;
    return item;
}

std::ostream& operator<<(std::ostream &os, const Item& item){
    os << "Item ID: " << item.item_id << std::endl;
    os << "Name: " << item.name << std::endl;
    os << "Description: " << item.description << std::endl;
    os << "Weight: " << item.weight << std::endl;
    os << "Price: " << item.price << std::endl;
    os << "Quantity: " << item.quantity << std::endl;
    os << "Category: " << item.category << std::endl;
    os << "Listed Date: " << get_printable_date(item.listed_date) << std::endl;
    os << "Expiration Date: " << get_printable_date(item.expiration_date) << std::endl;
    return os;
}
