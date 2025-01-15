#include "Payment.hpp"
#include <iostream>
using namespace std;

void CreditCardPayment::processPayment(int orderID, double amount) {
    cout << "[Credit Card Payment Processed] Order ID: " << orderID << " | Amount: $" << amount << " | Status: Processed with Credit Card" << endl;
}

void CreditCardPayment::refundPayment(int paymentID) {
    cout << "[Credit Card Payment Refunded] Payment ID: " << paymentID << " | Status: Refunded to Credit Card" << endl;
}

void CashPayment::processPayment(int orderID, double amount) {
    cout << "[Cash Payment Processed] Order ID: " << orderID << " | Amount: $" << amount << " | Status: Paid in Cash" << endl;
}

void CashPayment::refundPayment(int paymentID) {
    cout << "[Cash Payment Refunded] Payment ID: " << paymentID << " | Status: Refunded in Cash" << endl;
}
