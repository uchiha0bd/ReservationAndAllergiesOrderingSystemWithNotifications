// Notification.cpp
#include "Notification.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>

std::string Notification::getCurrentTimestamp() const {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void EmailNotification::sendNotification(const std::string& email, const std::string& content) const {
    std::cout << "[Email Notification] Email: " << email << "\nMessage: " << content
              << "\nTimestamp: " << getCurrentTimestamp() << "\n";
}

void SMSNotification::sendNotification(const std::string& phoneNumber, const std::string& content) const {
    std::cout << "[SMS Notification] Phone: " << phoneNumber << "\nMessage: " << content
              << "\nTimestamp: " << getCurrentTimestamp() << "\n";
}
