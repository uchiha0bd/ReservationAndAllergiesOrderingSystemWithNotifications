#include "Payment.hpp"
#include <iostream>

void CashPayment::processPayment(int orderID, double amount) const {
    std::cout << "[Cash Payment] Order ID: " << orderID
              << " | Amount: $" << amount
              << " | Status: Paid in Cash\n";
}

void CashPayment::refundPayment(int paymentID) const {
    std::cout << "[Cash Refund] Payment ID: " << paymentID
              << " | Status: Refunded in Cash\n";
}

void CreditCardPayment::processPayment(int orderID, double amount) const {
    std::cout << "[Credit Card Payment] Order ID: " << orderID
              << " | Amount: $" << amount
              << " | Status: Charged to Credit Card\n";
}

void CreditCardPayment::refundPayment(int paymentID) const {
    std::cout << "[Credit Card Refund] Payment ID: " << paymentID
              << " | Status: Refunded to Credit Card\n";
}
