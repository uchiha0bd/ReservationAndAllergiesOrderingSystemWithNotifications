#include "Notification.hpp"
#include <iostream>
#include <ctime>
using namespace std;

string Notification::getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

void EmailNotification::sendNotification(const string& email, const string& content) {
    cout << "[Email Notification] Email: " << email << " | Message: " << content << " | Timestamp: " << getCurrentTime() << endl;
}

void SMSNotification::sendNotification(const string& phoneNumber, const string& content) {
    cout << "[SMS Notification] Phone: " << phoneNumber << " | Message: " << content << " | Timestamp: " << getCurrentTime() << endl;
}
