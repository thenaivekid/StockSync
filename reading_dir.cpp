// g++ -std=c++17 .\reading_dir.cpp -o .\reading_dir.exe

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>
#include "Inventory/util.h"

namespace fs = std::filesystem;

std::vector <std::string> get_file_names(std::string directory_path) {
    std::vector <std::string> file_names;
    for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
        file_names.push_back(entry.path().string());
    }
    return file_names;
}


int main() {
    std::vector<std::string> file_names;
    std::string directory_path = "./Inventory/order_management_system/orders";

    file_names = get_file_names(directory_path);

    for (const auto& file_name : file_names) {
        std::cout << file_name << std::endl;
        std::fstream file(file_name, std::ios::binary | std::ios::in);

         std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
}

    return 0;
}
