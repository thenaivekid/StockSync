#include <iostream>
#include <string>
#include <chrono>

int main() {
    // Prompt the user for input
    std::cout << "Enter the date (YYYY-MM-DD): ";
    std::string userInput;
    std::cin >> userInput;

    // Parse the user input and create a time_point
    std::chrono::system_clock::time_point date;
    try {
        // Extract year, month, and day from the user input
        int year = std::stoi(userInput.substr(0, 4));
        int month = std::stoi(userInput.substr(5, 2));
        int day = std::stoi(userInput.substr(8, 2));

        // Create the time_point using the parsed values
        std::tm timeInfo{};
        timeInfo.tm_year = year - 1900; // Years since 1900
        timeInfo.tm_mon = month - 1;    // Months since January (0-based)
        timeInfo.tm_mday = day;

        // Convert tm struct to time_t
        std::time_t time = std::mktime(&timeInfo);

        // Create the time_point from the time_t value
        date = std::chrono::system_clock::from_time_t(time);
    } catch (const std::exception& e) {
        std::cerr << "Invalid date input: " << e.what() << std::endl;
        return 1;
    }

    // Convert the time_point to time_t
    std::time_t time = std::chrono::system_clock::to_time_t(date);

    // Display the entered date
    std::cout << "Entered date: " << std::ctime(&time);

    return 0;
}
