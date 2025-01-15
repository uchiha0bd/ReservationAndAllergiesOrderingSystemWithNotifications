#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

#include <string>
using namespace std;

class Notification {
public:
    // Gets the current timestamp
    string getCurrentTime();

    // Virtual destructor for proper cleanup
    virtual ~Notification() = default;

    // Pure virtual method to send a notification
    virtual void sendNotification(const string& recipient, const string& content) = 0;
};

class EmailNotification : public Notification {
public:
    // Sends an email notification
    void sendNotification(const string& email, const string& content) override;
};

class SMSNotification : public Notification {
public:
    // Sends an SMS notification
    void sendNotification(const string& phoneNumber, const string& content) override;
};

#endif // NOTIFICATION_HPP
