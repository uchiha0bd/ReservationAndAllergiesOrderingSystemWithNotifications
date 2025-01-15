#ifndef SUGGESTION_HPP
#define SUGGESTION_HPP

#include <string>
#include <vector>
using namespace std;

class SuggestionBase {
protected:
    string suggestionID;
    string customerID;

public:
    // Constructor
    SuggestionBase();

    // Pure virtual method
    virtual void generateSuggestions(const string& customerID) = 0;

    // Virtual destructor
    virtual ~SuggestionBase() = default;
};

class Suggestion : public SuggestionBase {
private:
    vector<string> suggestedItems;

public:
    // Constructor
    Suggestion();

    // Methods
    void generateSuggestions(const string& customerID) override;
    void updateSuggestions(const string& customerID, const vector<string>& newPreferences);

    // Getter for encapsulation
    vector<string> getSuggestedItems() const;
};

#endif // SUGGESTION_HPP
