#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string id, string name, string phone, string email, string prefs, string address)
    : _customerID(id), _name(name), _phoneNumber(phone), _email(email), _preferences(prefs), _address(address) {}

void Customer::updateProfile(string updatedInfo) {
    cout << "Profile updated: " << updatedInfo << endl;
}

void Customer::viewOrderHistory() {
    cout << "Order History for " << _name << ":\n";
    for (const auto& order : _orderHistory) {
        cout << "- " << order << endl;
    }
}

void Customer::addOrderHistory(string order) {
    _orderHistory.push_back(order);
}

string Customer::getCustomerID() const {
    return _customerID;
}

string Customer::getAddress() const {
    return _address;
}

void Customer::setAddress(const string& address) {
    _address = address;
}

void Customer::displayCustomerDetails() const {
    cout << "Customer ID: " << _customerID << endl;
    cout << "Name: " << _name << endl;
    cout << "Phone: " << _phoneNumber << endl;
    cout << "Email: " << _email << endl;
    cout << "Preferences: " << _preferences << endl;
    if (!_address.empty()) {
        cout << "Address: " << _address << endl;
    }
}
