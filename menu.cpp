#include "menu.h"
#include <iostream>
#include <algorithm>
using namespace std;

Menu::Menu() {}

void Menu::addMenuItem(int itemID, const string& itemDetails) {
    items[itemID] = itemDetails;
    cout << "Menu Item Added: " << itemID << " - " << itemDetails << "\n";
}

void Menu::updateMenuItem(int itemID, const string& updatedDetails) {
    if (items.find(itemID) != items.end()) {
        items[itemID] = updatedDetails;
        cout << "Menu Item Updated: " << itemID << " - " << updatedDetails << "\n";
    } else {
        cout << "Menu Item ID not found!\n";
    }
}

string Menu::getMenuItemDetails(int itemID) const {
    if (items.find(itemID) != items.end()) {
        return items.at(itemID);
    }
    return "Item not found!";
}

vector<pair<int, string>> Menu::filterMenu(const vector<string>& allergens) const {
    vector<pair<int, string>> filteredMenu;
    for (const auto& item : items) {
        bool containsAllergen = false;
        for (const auto& allergen : allergens) {
            if (item.second.find(allergen) != string::npos) {
                containsAllergen = true;
                break;
            }
        }
        if (!containsAllergen) {
            filteredMenu.push_back(item);
        }
    }
    return filteredMenu;
}

void Menu::displayMenu(const vector<pair<int, string>>& menuToDisplay) const {
    for (const auto& item : menuToDisplay) {
        cout << item.first << ": " << item.second << "\n";
    }
}
