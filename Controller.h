// Controller.h
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "menu.h"
#include "order.h"
#include "Customer.h"
#include "Reservation.h"
#include "Notification.hpp"
#include "allergy.h"
#include <map>
#include <memory>

class Controller {
private:
    Menu menu;
    AllergyFilter allergyFilter;
    std::map<std::string, Customer> customers;
    std::vector<std::shared_ptr<Order>> orders;
    std::vector<std::shared_ptr<Reservation>> reservations;

public:
    Controller();

    // Menu Management
    void loadMenuItems();
    void displayMenu(const std::string& customerID) const;

    // Customer Management
    void registerCustomer(const std::string& name, const std::string& phone, const std::string& email);
    Customer& getCustomer(const std::string& customerID);

    // Order Management
    void placeOrder(const std::string& customerID, const std::vector<int>& itemIDs, const std::string& orderType, int tableNo = -1, const std::string& address = "");

    // Reservation Management
    void createReservation(const std::string& customerID, const std::string& date, const std::string& time, int tableNo, const std::string& paymentStatus = "");

    // Notification Management
    void sendNotification(const std::string& recipient, const std::string& content, const std::string& method) const;

    void processPayment(int orderID, double amount, const std::string& paymentMethod) const;

};

#endif // CONTROLLER_HPP
