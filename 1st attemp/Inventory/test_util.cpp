#include "util.h"
std::string get_(){
    return get_printable_date(get_date());
}

int main() {
    std::cout << get_printable_date(get_date()) << std::endl;

    std::cout << get_() << std::endl;

    return 0;
}