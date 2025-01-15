#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <vector>
using namespace std;

class Order {
protected:
    int orderID;
    vector<string> items;
    double totalAmount;
    string status;

public:
    // Constructor
    Order(int id, const vector<string>& orderItems);

    // Virtual Destructor
    virtual ~Order() = default;

    // Getters
    int getOrderID() const;
    vector<string> getItems() const;
    double getTotalAmount() const;
    string getStatus() const;

    // Operations
    void updateOrder(const vector<string>& newItems);
    void cancelOrder();

    // Virtual function to display order details
    virtual void displayOrderDetails() const;
};

class DineInOrder : public Order {
private:
    int tableNumber;

public:
    // Constructor
    DineInOrder(int id, const vector<string>& orderItems, int tableNo);

    // Override display method
    void displayOrderDetails() const override;
};

class DeliveryOrder : public Order {
private:
    string deliveryAddress;

public:
    // Constructor
    DeliveryOrder(int id, const vector<string>& orderItems, const string& address);

    // Override display method
    void displayOrderDetails() const override;
};

#endif // ORDER_HPP
