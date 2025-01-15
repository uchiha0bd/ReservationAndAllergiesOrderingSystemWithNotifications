#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <iostream>
#include <string>

class Payment {
public:
    virtual ~Payment() = default;
    virtual void processPayment(int orderID, double amount) const = 0;
};

class CashPayment : public Payment {
public:
    void processPayment(int orderID, double amount) const override {
        std::cout << "Processed cash payment for Order #" << orderID << " - Amount: $" << amount << "\n";
    }
};

class CreditCardPayment : public Payment {
public:
    void processPayment(int orderID, double amount) const override {
        std::cout << "Processed credit card payment for Order #" << orderID << " - Amount: $" << amount << "\n";
    }
};

#endif // PAYMENT_HPP
