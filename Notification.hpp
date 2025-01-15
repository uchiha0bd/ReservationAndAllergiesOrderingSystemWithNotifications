// Notification.hpp
#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

#include <string>

class Notification {
protected:
    std::string getCurrentTimestamp() const;

public:
    virtual ~Notification() = default;

    // Pure virtual method for sending notifications
    virtual void sendNotification(const std::string& recipient, const std::string& content) const = 0;
};

class EmailNotification : public Notification {
public:
    void sendNotification(const std::string& email, const std::string& content) const override;
};

class SMSNotification : public Notification {
public:
    void sendNotification(const std::string& phoneNumber, const std::string& content) const override;
};

#endif // NOTIFICATION_HPP
