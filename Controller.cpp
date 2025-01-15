// Controller.cpp
#include "Controller.h"
#include <iostream>
#include "Payment.hpp"

Controller::Controller() {
    loadMenuItems();
}

void Controller::loadMenuItems() {
    // Example: Load menu items (this could be replaced by file/database loading)
    menu.addMenuItem({1, "Vegan Salad", 8.50, {"Gluten"}});
    menu.addMenuItem({2, "Grilled Chicken", 12.00, {"Dairy"}});
    menu.addMenuItem({3, "Seafood Pasta", 15.50, {"Shellfish"}});
}

void Controller::displayMenu(const std::string& customerID) const {
    std::vector<MenuItem> filteredMenu;
    if (!customerID.empty()) {
        auto allergens = allergyFilter.getCustomerAllergens(customerID);
        filteredMenu = menu.getFilteredMenu(allergens);
    } else {
        filteredMenu = menu.getAllItems();
    }

    std::cout << "--- Menu ---\n";
    for (const auto& item : filteredMenu) {
        std::cout << item.id << ": " << item.name << " ($" << item.price << ")\n";
    }
}

void Controller::registerCustomer(const std::string& name, const std::string& phone, const std::string& email) {
    std::string customerID = "C" + std::to_string(customers.size() + 1);
    customers[customerID] = Customer(customerID, name, phone, email);
    std::cout << "Customer registered: " << name << " (ID: " << customerID << ")\n";
}

Customer& Controller::getCustomer(const std::string& customerID) {
    if (customers.find(customerID) == customers.end()) {
        throw std::runtime_error("Customer not found!");
    }
    return customers.at(customerID);
}

void Controller::placeOrder(const std::string& customerID, const std::vector<int>& itemIDs, const std::string& orderType, int tableNo, const std::string& address) {
    Customer& customer = getCustomer(customerID);
    std::vector<MenuItem> items;

    for (int id : itemIDs) {
        for (const auto& item : menu.getAllItems()) {
            if (item.id == id) {
                items.push_back(item);
                break;
            }
        }
    }

    std::shared_ptr<Order> order;
    if (orderType == "DineIn") {
        order = std::make_shared<DineInOrder>(orders.size() + 1, tableNo);
    } else if (orderType == "Delivery") {
        order = std::make_shared<DeliveryOrder>(orders.size() + 1, address);
    } else {
        throw std::runtime_error("Invalid order type!");
    }

    for (const auto& item : items) {
        order->addItem(item);
    }
    order->calculateTotal();
    orders.push_back(order);

    std::cout << "Order placed successfully for customer: " << customer.getName() << "\n";
    order->displayOrderDetails();
}

void Controller::createReservation(const std::string& customerID, const std::string& date, const std::string& time, int tableNo, const std::string& paymentStatus) {
    Customer& customer = getCustomer(customerID);
    std::shared_ptr<Reservation> reservation;

    if (!paymentStatus.empty()) {
        reservation = std::make_shared<OnlineReservation>("R" + std::to_string(reservations.size() + 1), customerID, date, time, tableNo, paymentStatus);
    } else {
        reservation = std::make_shared<WalkInReservation>("R" + std::to_string(reservations.size() + 1), customerID, date, time, tableNo);
    }

    reservations.push_back(reservation);
    std::cout << "Reservation created successfully for customer: " << customer.getName() << "\n";
    reservation->displayReservationDetails();
}

void Controller::sendNotification(const std::string& recipient, const std::string& content, const std::string& method) const {
    std::unique_ptr<Notification> notification;

    if (method == "Email") {
        notification = std::make_unique<EmailNotification>();
    } else if (method == "SMS") {
        notification = std::make_unique<SMSNotification>();
    } else {
        throw std::runtime_error("Invalid notification method!");
    }

    notification->sendNotification(recipient, content);
}

void Controller::processPayment(int orderID, double amount, const std::string& paymentMethod) const {
    std::unique_ptr<Payment> payment;

    if (paymentMethod == "Cash") {
        payment = std::make_unique<CashPayment>();
    } else if (paymentMethod == "CreditCard") {
        payment = std::make_unique<CreditCardPayment>();
    } else {
        throw std::runtime_error("Invalid payment method!");
    }

    payment->processPayment(orderID, amount);
}
