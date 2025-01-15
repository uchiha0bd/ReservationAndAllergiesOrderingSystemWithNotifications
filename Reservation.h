#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <string>
#include <vector>
using namespace std;

class Reservation {
protected:
    string _reservationID;
    string _date;
    string _time;
    int _tableNumber;
    string _status;
    string _customerID;

public:
    // Constructor
    Reservation(string id, string customerID, string date, string time, int tableNum);

    // Methods
    virtual void createReservation();
    virtual void updateReservation(string updatedDetails);
    virtual void cancelReservation();

    // Dynamic availability
    static vector<string> getAvailableDays();
    static vector<string> getAvailableTimes();

    // Virtual destructor
    virtual ~Reservation();
};

class OnlineReservation : public Reservation {
private:
    string _paymentStatus;

public:
    // Constructor
    OnlineReservation(string id, string customerID, string date, string time, int tableNum, string paymentStatus);

    // Override methods
    void createReservation() override;
    void updateReservation(string updatedDetails) override;
};

class WalkInReservation : public Reservation {
public:
    // Constructor
    WalkInReservation(string id, string customerID, string date, string time, int tableNum);

    // Override methods
    void createReservation() override;
};

#endif // RESERVATION_HPP
