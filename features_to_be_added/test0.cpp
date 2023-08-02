#include <iostream>
#include <fstream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    // Default constructor
    Person() : name(""), age(0) {}

    // Parameterized constructor
    Person(const std::string& name, int age) : name(name), age(age) {}
};

// Function to write a Person object to a file
void writeToFile(const std::string& filename, const Person& person) {
    std::ofstream outputFile(filename, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    // Write the object to the file
    outputFile.write(reinterpret_cast<const char*>(&person), sizeof(Person));

    outputFile.close();
}

// Function to read a Person object from a file
bool readFromFile(const std::string& filename, Person& person) {
    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
        return false;
    }

    // Read the object from the file
    inputFile.read(reinterpret_cast<char*>(&person), sizeof(Person));

    inputFile.close();
    return true;
}

int main() {
    // Create a Person object
    Person person1("John Doe", 30);

    // Write the object to a file
    writeToFile("person_data.dat", person1);

    // Read the object from the file
    Person person2;
    if (readFromFile("person_data.dat", person2)) {
        // Display the read data
        std::cout << "Name: " << person2.name << ", Age: " << person2.age << std::endl;
    }

    return 0;
}
