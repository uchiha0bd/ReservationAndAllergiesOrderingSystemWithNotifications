#include "order.h"
#include <iostream>
using namespace std;

Order::Order(int id, const vector<string>& orderItems)
    : orderID(id), items(orderItems), status("Created") {
    totalAmount = items.size() * 10.0; // Example: each item costs $10.
}

int Order::getOrderID() const {
    return orderID;
}

vector<string> Order::getItems() const {
    return items;
}

double Order::getTotalAmount() const {
    return totalAmount;
}

string Order::getStatus() const {
    return status;
}

void Order::updateOrder(const vector<string>& newItems) {
    items = newItems;
    totalAmount = newItems.size() * 10.0;
    cout << "Order Updated: " << orderID << "\n";
}

void Order::cancelOrder() {
    status = "Cancelled";
    cout << "Order Cancelled: " << orderID << "\n";
}

void Order::displayOrderDetails() const {
    cout << "Order ID: " << orderID << "\nStatus: " << status << "\nItems: ";
    for (size_t i = 0; i < items.size(); ++i) {
        cout << items[i];
        if (i != items.size() - 1) {
            cout << ", ";
        }
    }
    cout << "\nTotal Amount: $" << totalAmount << "\n";
}

DineInOrder::DineInOrder(int id, const vector<string>& orderItems, int tableNo)
    : Order(id, orderItems), tableNumber(tableNo) {}

void DineInOrder::displayOrderDetails() const {
    cout << "Dine-In Order Details:\n";
    Order::displayOrderDetails();
    cout << "Table Number: " << tableNumber << "\n";
}

DeliveryOrder::DeliveryOrder(int id, const vector<string>& orderItems, const string& address)
    : Order(id, orderItems), deliveryAddress(address) {}

void DeliveryOrder::displayOrderDetails() const {
    cout << "Delivery Order Details:\n";
    Order::displayOrderDetails();
    cout << "Delivery Address: " << deliveryAddress << "\n";
}
