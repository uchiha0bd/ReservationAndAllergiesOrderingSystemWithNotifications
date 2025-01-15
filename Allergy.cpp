// Allergy.cpp
#include "allergy.h"
#include <algorithm>

void AllergyFilter::addCustomerAllergens(const std::string& customerID, const std::vector<std::string>& allergens) {
    customerAllergens[customerID] = allergens;
}

bool AllergyFilter::hasAllergen(const std::string& customerID, const std::string& itemDescription) const {
    auto it = customerAllergens.find(customerID);
    if (it == customerAllergens.end()) {
        return false; // No allergens for this customer
    }

    const auto& allergens = it->second;
    return std::any_of(allergens.begin(), allergens.end(), [&itemDescription](const std::string& allergen) {
        return itemDescription.find(allergen) != std::string::npos;
    });
}

std::vector<std::string> AllergyFilter::getCustomerAllergens(const std::string& customerID) const {
    auto it = customerAllergens.find(customerID);
    if (it != customerAllergens.end()) {
        return it->second;
    }
    return {};
}
