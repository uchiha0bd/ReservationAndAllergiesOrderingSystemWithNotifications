// Order.cpp
#include "order.h"
#include <iostream>
#include <iomanip>

Order::Order(int id) : orderID(id), totalAmount(0.0) {}

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}

double Order::calculateTotal() {
    totalAmount = 0.0;
    for (const auto& item : items) {
        totalAmount += item.price;
    }
    return totalAmount;
}

const std::vector<MenuItem>& Order::getItems() const {
    return items;
}

DineInOrder::DineInOrder(int id, int tableNo) : Order(id), tableNumber(tableNo) {}

void DineInOrder::displayOrderDetails() const {
    std::cout << "Dine-In Order #" << orderID << "\nTable Number: " << tableNumber << "\nItems:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.name << " ($" << std::fixed << std::setprecision(2) << item.price << ")\n";
    }
    std::cout << "Total: $" << totalAmount << "\n";
}

DeliveryOrder::DeliveryOrder(int id, const std::string& address) : Order(id), deliveryAddress(address) {}

void DeliveryOrder::displayOrderDetails() const {
    std::cout << "Delivery Order #" << orderID << "\nDelivery Address: " << deliveryAddress << "\nItems:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.name << " ($" << std::fixed << std::setprecision(2) << item.price << ")\n";
    }
    std::cout << "Total: $" << totalAmount << "\n";
}
