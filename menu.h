// Menu.h
#ifndef MENU_HPP
#define MENU_HPP

#include "MenuItem.h"
#include <vector>

class Menu {
private:
    std::vector<MenuItem> items;

public:
    Menu();
    void addMenuItem(const MenuItem& item);
    std::vector<MenuItem> getFilteredMenu(const std::vector<std::string>& allergens) const;
    const std::vector<MenuItem>& getAllItems() const;
};

#endif // MENU_HPP
