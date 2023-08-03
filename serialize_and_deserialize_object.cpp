#include <iostream>
#include <fstream>
#include <string>

class Person {
private:
    std::string name;
    std::string petName;
    int age;
    std::string phone;
    std::string address;

public:
    Person() : name(""), age(0) {}
    Person(std::string name_, std::string petName_, int age_, std::string phone_, std::string address_) : name(name_), petName(petName_), age(age_), phone(phone_), address(address_) {}

    // Serialization method
    void serialize(std::ofstream& ofs) const {
        std::string::size_type nameSize = name.size();
        std::string::size_type petNameSize = petName.size();
        std::string::size_type phoneSize = phone.size();
        std::string::size_type addressSize = address.size();

        ofs.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        ofs.write(name.c_str(), nameSize);

        ofs.write(reinterpret_cast<const char *> (&petNameSize), sizeof(petNameSize));
        ofs.write(petName.c_str(), petNameSize);

        ofs.write(reinterpret_cast<const char*>(&age), sizeof(age));

        ofs.write(reinterpret_cast<const char*>(&phoneSize), sizeof(phoneSize));
        ofs.write(phone.c_str(), phoneSize);

        ofs.write(reinterpret_cast<const char*>(&addressSize), sizeof(addressSize));
        ofs.write(address.c_str(), addressSize);
    }

    // Deserialization method
    void deserialize(std::ifstream& ifs) {
        std::string::size_type nameSize;
        std::string::size_type petNameSize;
        std::string::size_type phoneSize;
        std::string::size_type addressSize;

        ifs.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        // char buffer[nameSize];
        char buffer[nameSize + 1];
        ifs.read(buffer, nameSize);
        buffer[nameSize] = '\0'; // Null-terminate the string
        name = std::string(buffer);

        ifs.read(reinterpret_cast<char*>(&petNameSize), sizeof(petNameSize));
        ifs.read(buffer, petNameSize);
        buffer[petNameSize] = '\0';
        petName = std::string(buffer);

        ifs.read(reinterpret_cast<char*>(&age), sizeof(age));

        ifs.read(reinterpret_cast<char*>(&phoneSize), sizeof(phoneSize));
        ifs.read(buffer, phoneSize);
        buffer[phoneSize] = '\0'; // Null-terminate the string
        phone = std::string(buffer);

        ifs.read(reinterpret_cast<char*>(&addressSize), sizeof(addressSize));
        ifs.read(buffer, addressSize);
        buffer[addressSize] = '\0'; // Null-terminate the string
        address = std::string(buffer);
    }

    void print() const {
        std::cout << "Name: " << name << "pet name: " << petName << ", Age: " << age << ", Phone: " << phone << ", Address: " << address << std::endl;
    }
};

int main() {
    // Create a Person object and serialize it to a file
    Person person1("John donkey is a bad ass.", "Winner", 30, "9823594372", "Mandan Deupur");
    std::ofstream outFile("person_data.dat", std::ios::binary);
    person1.serialize(outFile);
    outFile.close();

    // Deserialize the object from the file and read it back
    Person person2;
    std::ifstream inFile("person_data.dat", std::ios::binary);
    person2.deserialize(inFile);
    inFile.close();

    // Print the deserialized object
    person2.print();

    return 0;
}
