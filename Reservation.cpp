#include "Reservation.h"
#include <iostream>
using namespace std;

Reservation::Reservation(string id, string customerID, string date, string time, int tableNum)
    : _reservationID(id), _customerID(customerID), _date(date), _time(time), _tableNumber(tableNum), _status("Active") {}

void Reservation::createReservation() {
    cout << "Reservation created for customer " << _customerID << " on " << _date << " at " << _time << "\n";
}

void Reservation::updateReservation(string updatedDetails) {
    cout << "Reservation updated with details: " << updatedDetails << "\n";
}

void Reservation::cancelReservation() {
    _status = "Cancelled";
    cout << "Reservation " << _reservationID << " has been cancelled." << endl;
}

Reservation::~Reservation() {}

vector<string> Reservation::getAvailableDays() {
    return {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
}

vector<string> Reservation::getAvailableTimes() {
    return {"12:00 PM", "1:00 PM", "2:00 PM", "3:00 PM", "4:00 PM", "5:00 PM", "6:00 PM", "7:00 PM", "8:00 PM"};
}

OnlineReservation::OnlineReservation(string id, string customerID, string date, string time, int tableNum, string paymentStatus)
    : Reservation(id, customerID, date, time, tableNum), _paymentStatus(paymentStatus) {}

void OnlineReservation::createReservation() {
    cout << "Online reservation created for customer " << _customerID
         << " on " << _date << " at " << _time << " with payment status: " << _paymentStatus << "\n";
}

void OnlineReservation::updateReservation(string updatedDetails) {
    cout << "Online reservation updated with details: " << updatedDetails << "\n";
}

WalkInReservation::WalkInReservation(string id, string customerID, string date, string time, int tableNum)
    : Reservation(id, customerID, date, time, tableNum) {}

void WalkInReservation::createReservation() {
    cout << "Walk-in reservation created for customer " << _customerID
         << " on " << _date << " at " << _time << "\n";
}
