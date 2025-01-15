#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Menu {
private:
    unordered_map<int, string> items;

public:
    // Constructor
    Menu();

    // Adds a new menu item
    void addMenuItem(int itemID, const string& itemDetails);

    // Updates the details of an existing menu item
    void updateMenuItem(int itemID, const string& updatedDetails);

    // Retrieves the details of a menu item by ID
    string getMenuItemDetails(int itemID) const;

    // Filters the menu based on allergens
    vector<pair<int, string>> filterMenu(const vector<string>& allergens) const;

    // Displays the menu
    void displayMenu(const vector<pair<int, string>>& menuToDisplay) const;
};

#endif // MENU_HPP
