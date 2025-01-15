#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <string>
using namespace std;

class Payment {
public:
    // Virtual destructor for proper cleanup
    virtual ~Payment() = default;

    // Pure virtual methods for processing and refunding payments
    virtual void processPayment(int orderID, double amount) = 0;
    virtual void refundPayment(int paymentID) = 0;
};

class CreditCardPayment : public Payment {
public:
    // Process and refund using credit card
    void processPayment(int orderID, double amount) override;
    void refundPayment(int paymentID) override;
};

class CashPayment : public Payment {
public:
    // Process and refund using cash
    void processPayment(int orderID, double amount) override;
    void refundPayment(int paymentID) override;
};

#endif // PAYMENT_HPP
