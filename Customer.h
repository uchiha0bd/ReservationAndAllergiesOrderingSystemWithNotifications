// Customer.h
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>

class Customer {
private:
    std::string customerID;
    std::string name;
    std::string phone;
    std::string email;
    std::vector<std::string> preferences;

public:
    Customer() = default; // Default constructor
    Customer(const std::string& id, const std::string& name, const std::string& phone, const std::string& email);
    void updatePreferences(const std::vector<std::string>& newPreferences);
    const std::string& getName() const;
    const std::vector<std::string>& getPreferences() const;
};

#endif // CUSTOMER_HPP
