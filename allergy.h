#ifndef ALLERGY_HPP
#define ALLERGY_HPP

#include <string>
#include <vector>
#include <map>
using namespace std;

class AllergyBase {
protected:
    vector<string> allergenList;

public:
    // Constructor
    AllergyBase();

    // Pure virtual method
    virtual void flagAllergens(const string& customerID, const vector<string>& allergens) = 0;
    virtual bool checkAllergens(const string& menuItem, const string& customerID) const = 0;

    // Virtual destructor
    virtual ~AllergyBase() = default;
};

class AllergyFilter : public AllergyBase {
private:
    map<string, vector<string>> customerAllergens;

public:
    // Constructor
    AllergyFilter();

    // Methods
    void flagAllergens(const string& customerID, const vector<string>& allergens) override;
    bool checkAllergens(const string& menuItem, const string& customerID) const override;

    // Getter for customer allergens
    vector<string> getAllergensForCustomer(const string& customerID) const;
};

#endif // ALLERGY_HPP
