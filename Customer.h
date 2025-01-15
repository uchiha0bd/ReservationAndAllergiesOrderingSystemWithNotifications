#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <vector>
using namespace std;

class Customer {
private:
    string _customerID;
    string _name;
    string _phoneNumber;
    string _email;
    string _preferences;
    string _address;
    vector<string> _orderHistory;

public:
    // Constructor
    Customer(string id, string name, string phone, string email, string prefs, string address = "");

    // Methods
    void updateProfile(string updatedInfo);
    void viewOrderHistory();
    void addOrderHistory(string order);

    // Getters
    string getCustomerID() const;
    string getAddress() const;

    // Setters
    void setAddress(const string& address);

    // Display Details
    void displayCustomerDetails() const;
};

#endif // CUSTOMER_HPP
