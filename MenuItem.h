// MenuItem.h
#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <string>
#include <vector>

struct MenuItem {
    int id;
    std::string name;
    double price;
    std::vector<std::string> allergens;

    MenuItem(int id, const std::string& name, double price, const std::vector<std::string>& allergens)
        : id(id), name(name), price(price), allergens(allergens) {}
};

#endif // MENUITEM_HPP
