// Order.h
#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <vector>
#include "MenuItem.h"

class Order {
protected:
    int orderID;
    std::vector<MenuItem> items;
    double totalAmount;

public:
    Order(int id);
    virtual ~Order() = default;

    void addItem(const MenuItem& item);
    double calculateTotal();
    const std::vector<MenuItem>& getItems() const;
    virtual void displayOrderDetails() const = 0;
};

class DineInOrder : public Order {
private:
    int tableNumber;

public:
    DineInOrder(int id, int tableNo);
    void displayOrderDetails() const override;
};

class DeliveryOrder : public Order {
private:
    std::string deliveryAddress;

public:
    DeliveryOrder(int id, const std::string& address);
    void displayOrderDetails() const override;
};

#endif // ORDER_HPP
