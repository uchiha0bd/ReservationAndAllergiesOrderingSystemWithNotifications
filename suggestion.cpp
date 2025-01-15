#include "suggestion.h"
#include <iostream>
using namespace std;

// Base class constructor
SuggestionBase::SuggestionBase() {
    suggestionID = "";
    customerID = "";
}

// Derived class constructor
Suggestion::Suggestion() : SuggestionBase() {
    suggestedItems = {};
}

// Method to generate suggestions for a customer
void Suggestion::generateSuggestions(const string& customerID) {
    this->customerID = customerID;

    // Example: Generate dynamic suggestions based on customer preferences
    suggestedItems = {"Pizza", "Pasta", "Salad"}; // Replace with real logic

    cout << "Generated suggestions for customer " << customerID << ": ";
    for (const auto& item : suggestedItems) {
        cout << item << " ";
    }
    cout << endl;
}

// Method to update suggestions based on new preferences
void Suggestion::updateSuggestions(const string& customerID, const vector<string>& newPreferences) {
    this->customerID = customerID;

    // Update the suggested items
    suggestedItems = newPreferences;

    cout << "Updated suggestions for customer " << customerID << ": ";
    for (const auto& item : suggestedItems) {
        cout << item << " ";
    }
    cout << endl;
}

// Getter for encapsulation
vector<string> Suggestion::getSuggestedItems() const {
    return suggestedItems;
}
