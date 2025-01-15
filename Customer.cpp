// Customer.cpp
#include "Customer.h"

Customer::Customer(const std::string& id, const std::string& name, const std::string& phone, const std::string& email)
    : customerID(id), name(name), phone(phone), email(email) {}

void Customer::updatePreferences(const std::vector<std::string>& newPreferences) {
    preferences = newPreferences;
}

const std::string& Customer::getName() const {
    return name;
}

const std::vector<std::string>& Customer::getPreferences() const {
    return preferences;
}
