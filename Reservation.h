// Reservation.h
#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <string>

class Reservation {
protected:
    std::string reservationID;
    std::string customerID;
    std::string date;
    std::string time;

public:
    Reservation(const std::string& id, const std::string& customer, const std::string& date, const std::string& time);
    virtual ~Reservation() = default;

    virtual void displayReservationDetails() const = 0;
};

class OnlineReservation : public Reservation {
private:
    int tableNumber; // Add tableNumber here
    std::string paymentStatus;

public:
    OnlineReservation(const std::string& id, const std::string& customer, const std::string& date,
                      const std::string& time, int tableNo, const std::string& paymentStatus);
    void displayReservationDetails() const override;
};

class WalkInReservation : public Reservation {
private:
    int tableNumber; // Add tableNumber here

public:
    WalkInReservation(const std::string& id, const std::string& customer, const std::string& date,
                      const std::string& time, int tableNo);
    void displayReservationDetails() const override;
};

#endif // RESERVATION_HPP
