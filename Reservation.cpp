// Reservation.cpp
#include "Reservation.h"
#include <iostream>

Reservation::Reservation(const std::string& id, const std::string& customer, const std::string& date, const std::string& time)
    : reservationID(id), customerID(customer), date(date), time(time) {}

OnlineReservation::OnlineReservation(const std::string& id, const std::string& customer, const std::string& date,
                                     const std::string& time, int tableNo, const std::string& paymentStatus)
    : Reservation(id, customer, date, time), tableNumber(tableNo), paymentStatus(paymentStatus) {}

void OnlineReservation::displayReservationDetails() const {
    std::cout << "Online Reservation #" << reservationID
              << "\nCustomer: " << customerID
              << "\nDate: " << date
              << "\nTime: " << time
              << "\nTable Number: " << tableNumber
              << "\nPayment Status: " << paymentStatus
              << "\n";
}

WalkInReservation::WalkInReservation(const std::string& id, const std::string& customer, const std::string& date,
                                     const std::string& time, int tableNo)
    : Reservation(id, customer, date, time), tableNumber(tableNo) {}

void WalkInReservation::displayReservationDetails() const {
    std::cout << "Walk-In Reservation #" << reservationID
              << "\nCustomer: " << customerID
              << "\nDate: " << date
              << "\nTime: " << time
              << "\nTable Number: " << tableNumber
              << "\n";
}