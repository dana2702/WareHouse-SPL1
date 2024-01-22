#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Customer {
    std::string name;
    std::string type;
    int distance;
    int maxOrders;
};

struct Volunteer {
    std::string name;
    std::string role;
    int cooldown;
    int maxDistance;
    int distancePerStep;
    int maxOrders;
};

void parseConfigFile(const std::string& filename, std::vector<Customer>& customers, std::vector<Volunteer>& volunteers) {
    std::ifstream configFile(filename);
    std::string line;

    while (std::getline(configFile, line)) {
        std::istringstream iss(line);
        std::string keyword;

        if (!(iss >> keyword)) {
            continue; // Skip empty lines
        }

        if (keyword == "customer") {
            Customer customer;
            iss >> customer.name >> customer.type >> customer.distance >> customer.maxOrders;
            customers.push_back(customer);
        } else if (keyword == "volunteer") {
            Volunteer volunteer;
            iss >> volunteer.name >> volunteer.role >> volunteer.cooldown;

            // Check if the volunteer is a driver (has additional parameters)
            if (volunteer.role == "driver" || volunteer.role == "limited_driver") {
                iss >> volunteer.maxDistance >> volunteer.distancePerStep;
            }

            // Check if maxOrders is provided
            if (iss >> volunteer.maxOrders) {
                // MaxOrders is provided
            } else {
                // MaxOrders is not provided, set to a default value
                volunteer.maxOrders = -1; // You can set it to any default value or handle it differently
            }

            volunteers.push_back(volunteer);
        }
    }
}

int main() {
    std::vector<Customer> customers;
    std::vector<Volunteer> volunteers;

    parseConfigFile("configFileExample.txt", customers, volunteers);

    // Print parsed customers
    std::cout << "Customers:\n";
    for (const auto& customer : customers) {
        std::cout << "Name: " << customer.name << ", Type: " << customer.type
                  << ", Distance: " << customer.distance << ", Max Orders: " << customer.maxOrders << "\n";
    }

    // Print parsed volunteers
    std::cout << "\nVolunteers:\n";
    for (const auto& volunteer : volunteers) {
        std::cout << "Name: " << volunteer.name << ", Role: " << volunteer.role
                  << ", Cooldown: " << volunteer.cooldown;

        if (volunteer.role == "driver" || volunteer.role == "limited_driver") {
            std::cout << ", Max Distance: " << volunteer.maxDistance
                      << ", Distance Per Step: " << volunteer.distancePerStep;
        }

        std::cout << ", Max Orders: " << volunteer.maxOrders << "\n";
    }

    return 0;
}
