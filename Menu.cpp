// Menu.cpp
#include "menu.h"
#include <algorithm>

Menu::Menu() {}

void Menu::addMenuItem(const MenuItem& item) {
    items.push_back(item);
}

std::vector<MenuItem> Menu::getFilteredMenu(const std::vector<std::string>& allergens) const {
    std::vector<MenuItem> filteredMenu;

    for (const auto& item : items) {
        bool containsAllergen = false;
        for (const auto& allergen : allergens) {
            if (std::find(item.allergens.begin(), item.allergens.end(), allergen) != item.allergens.end()) {
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

const std::vector<MenuItem>& Menu::getAllItems() const {
    return items;
}
