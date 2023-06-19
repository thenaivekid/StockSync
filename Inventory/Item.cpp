#include "Item.h"
#include "util.h"

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
}

long int Item::item_count = 0;

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
