#include "allergy.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Base class constructor
AllergyBase::AllergyBase() {
    allergenList = {};
}

// Derived class constructor
AllergyFilter::AllergyFilter() : AllergyBase() {
    customerAllergens = {};
}

// Method to flag allergens for a customer
void AllergyFilter::flagAllergens(const string& customerID, const vector<string>& allergens) {
    customerAllergens[customerID] = allergens;
    cout << "Allergens flagged for customer " << customerID << ": ";
    for (const auto& allergen : allergens) {
        cout << allergen << " ";
    }
    cout << endl;
}

// Method to check if a menu item contains allergens for a customer
bool AllergyFilter::checkAllergens(const string& menuItem, const string& customerID) const {
    if (customerAllergens.find(customerID) == customerAllergens.end()) {
        cout << "No allergens found for customer " << customerID << "." << endl;
        return false;
    }

    const auto& customerAllergenList = customerAllergens.at(customerID);

    for (const auto& allergen : customerAllergenList) {
        if (menuItem.find(allergen) != string::npos) {
            cout << "Allergen detected! Menu item contains " << allergen << ", which customer " << customerID << " is allergic to." << endl;
            return true;
        }
    }

    cout << "No allergens detected for customer " << customerID << " in the menu item." << endl;
    return false;
}

// Getter to retrieve allergens for a specific customer
vector<string> AllergyFilter::getAllergensForCustomer(const string& customerID) const {
    if (customerAllergens.find(customerID) != customerAllergens.end()) {
        return customerAllergens.at(customerID);
    }
    return {};
}
