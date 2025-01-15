// Allergy.hpp
#ifndef ALLERGY_HPP
#define ALLERGY_HPP

#include <string>
#include <vector>
#include <map>

class AllergyFilter {
private:
    std::map<std::string, std::vector<std::string>> customerAllergens;

public:
    void addCustomerAllergens(const std::string& customerID, const std::vector<std::string>& allergens);
    bool hasAllergen(const std::string& customerID, const std::string& itemDescription) const;
    std::vector<std::string> getCustomerAllergens(const std::string& customerID) const;
};

#endif // ALLERGY_HPP
