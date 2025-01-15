#include <iostream>
#include "Customer.h"
#include "allergy.h"
#include "menu.h"
#include "order.h"
#include "Notification.hpp"
#include "Reservation.h"
#include "suggestion.h"
#include "Payment.hpp"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string reserveOption;
    cout << "Welcome in helloThere restaurant application, how do you want to start?"<<endl<<endl;
    cout << "Do you want to reserve a table at the restaurant? (Yes/No): ";
    cin >> reserveOption;
    cin.ignore(); // Clear newline from input buffer

    if (reserveOption == "Yes" || reserveOption == "yes") {
    cout << "Available Days:\n";
    vector<string> availableDays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (size_t i = 0; i < availableDays.size(); ++i) {
        cout << i + 1 << ". " << availableDays[i] << "\n";
    }

    int dayChoice;
    cout << "Choose a day (enter the number): ";
    cin >> dayChoice;
    cin.ignore();

    if (dayChoice < 1 || dayChoice > availableDays.size()) {
        cout << "Invalid choice. Please restart the application.\n";
        return 1; // Exit due to invalid input
    }

    string chosenDay = availableDays[dayChoice - 1];
    cout << "You chose " << chosenDay << ".\n";

    vector<string> availableTimes = {"12:00 PM", "1:00 PM", "2:00 PM", "3:00 PM", "4:00 PM", "5:00 PM"};
    cout << "Available Times:\n";
    for (size_t i = 0; i < availableTimes.size(); ++i) {
        cout << i + 1 << ". " << availableTimes[i] << "\n";
    }

    int timeChoice;
    cout << "Choose a time (enter the number): ";
    cin >> timeChoice;
    cin.ignore();

    if (timeChoice < 1 || timeChoice > availableTimes.size()) {
        cout << "Invalid choice. Please restart the application.\n";
        return 1; // Exit due to invalid input
    }

    string chosenTime = availableTimes[timeChoice - 1];
    cout << "You chose " << chosenTime << " on " << chosenDay << ". Your reservation is confirmed!\n";


    } else {
        // Proceed to ordering options
        string orderOption;
        cout << "Do you want to pick up, takeaway, or have delivery? (Pick up/Takeaway/Delivery): ";
        cin >> orderOption;
        cin.ignore(); // Clear newline from input buffer

        string name, phone, email, address, preferences;
        char deliveryOption;

        // Collect customer details
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your phone number: ";
        getline(cin, phone);
        cout << "Enter your email address: ";
        getline(cin, email);

        if (orderOption == "Delivery" || orderOption == "delivery") {
            cout << "Enter your delivery address: ";
            getline(cin, address);
        }

        cout << "Enter your food preferences (e.g., Vegan, Vegetarian, etc.): ";
        getline(cin, preferences);

        // Generate unique customer ID (Example: C###)
        static int customerCounter = 1;
        string customerID = "C" + to_string(customerCounter++);

        // Create customer instance
        Customer customer(customerID, name, phone, email, preferences, address);

        // Display customer details
        cout << "\n--- Customer Details ---\n";
        customer.displayCustomerDetails();

        // Collect allergen information
        char isAllergic;
        AllergyFilter allergyFilter;
        cout << "\nAre you allergic to any food? (Y/N): ";
        cin >> isAllergic;
        cin.ignore(); // Clear newline from input buffer

        // Define a full menu with 30 items and their prices
        vector<pair<int, pair<string, double>>> fullMenu = {
            {1, {"Vegan Salad: Gluten-Free", 8.50}}, {2, {"Peanut Butter Sandwich", 5.00}},
            {3, {"Grilled Chicken: Dairy-Free", 12.00}}, {4, {"Shrimp Pasta: Contains Shellfish", 15.50}},
            {5, {"Soy Burger", 9.00}}, {6, {"Gluten-Free Pizza", 14.00}},
            {7, {"Tofu Stir Fry", 10.00}}, {8, {"Mango Smoothie", 6.00}},
            {9, {"Seafood Paella", 18.00}}, {10, {"Eggplant Parmesan", 11.00}},
            {11, {"Pasta Alfredo: Contains Dairy", 13.00}}, {12, {"Clam Chowder", 14.50}},
            {13, {"Caesar Salad: Contains Gluten", 8.00}}, {14, {"Turkey Sandwich", 7.50}},
            {15, {"Quinoa Bowl", 10.50}}, {16, {"Fruit Salad", 5.50}},
            {17, {"Grilled Salmon", 16.00}}, {18, {"Cheeseburger: Contains Dairy", 9.50}},
            {19, {"Lobster Bisque", 19.50}}, {20, {"Vegetable Soup", 6.50}},
            {21, {"Avocado Toast", 7.00}}, {22, {"Chickpea Curry", 9.00}},
            {23, {"Steak Tacos", 12.50}}, {24, {"Chicken Parmesan", 15.00}},
            {25, {"Shrimp Tacos", 14.50}}, {26, {"BBQ Ribs", 17.00}},
            {27, {"Stuffed Bell Peppers", 10.00}}, {28, {"Egg Salad", 5.50}},
            {29, {"Mushroom Risotto", 11.50}}, {30, {"Beef Stroganoff", 14.00}}
        };

        vector<pair<int, pair<string, double>>> availableMenu;
        if (isAllergic == 'Y' || isAllergic == 'y') {
            vector<string> commonAllergens = {"Peanuts", "Dairy", "Gluten", "Shellfish", "Soy"};
            vector<string> flaggedAllergens;
            cout << "Select allergens from the list below (enter 0 to stop):\n";
            for (size_t i = 0; i < commonAllergens.size(); ++i) {
                cout << i + 1 << ". " << commonAllergens[i] << "\n";
            }

            int allergenChoice;
            do {
                cout << "Enter allergen number: ";
                cin >> allergenChoice;
                cin.ignore(); // Clear newline from input buffer
                if (allergenChoice > 0 && allergenChoice <= static_cast<int>(commonAllergens.size())) {
                    flaggedAllergens.push_back(commonAllergens[allergenChoice - 1]);
                }
            } while (allergenChoice != 0);

            allergyFilter.flagAllergens(customerID, flaggedAllergens);
            vector<string> allergensForCustomer = allergyFilter.getAllergensForCustomer(customerID);

            for (const auto& item : fullMenu) {
                bool containsAllergen = false;
                for (const auto& allergen : allergensForCustomer) {
                    if (item.second.first.find(allergen) != string::npos) {
                        containsAllergen = true;
                        break;
                    }
                }
                if (containsAllergen) {
                    availableMenu.push_back({item.first, {item.second.first + " {it is allergic to you}", item.second.second}});
                } else {
                    availableMenu.push_back(item);
                }
            }

            cout << "\n--- Filtered Menu Based on Allergies ---\n";
        } else {
            availableMenu = fullMenu;
            cout << "\n--- Full Menu ---\n";
        }

        // Display the menu
        for (const auto& item : availableMenu) {
            cout << item.first << ": " << item.second.first << " ($" << item.second.second << ")\n";
        }

        // Allow the customer to choose items
        vector<pair<string, double>> selectedItems;
        int itemChoice;
        cout << "\nSelect items from the menu (enter 0 when done):\n";
        do {
            cout << "Enter item number: ";
            cin >> itemChoice;
            cin.ignore(); // Clear newline from input buffer
            if (itemChoice > 0 && itemChoice <= static_cast<int>(availableMenu.size())) {
                if (availableMenu[itemChoice - 1].second.first.find("{it is allergic to you}") == string::npos) {
                    selectedItems.push_back(availableMenu[itemChoice - 1].second);
                    cout << availableMenu[itemChoice - 1].second.first << " added to your order.\n";
                } else {
                    cout << "You cannot select this item due to your allergies.\n";
                }
            }
        } while (itemChoice != 0);

        // Calculate the total
        double totalAmount = 0.0;
        cout << "\n--- Your Order ---\n";
        for (const auto& item : selectedItems) {
            cout << "- " << item.first << " ($" << item.second << ")\n";
            totalAmount += item.second;
        }
        cout << "Total Amount: $" << totalAmount << "\n";

        // Payment Method
        string paymentMethod;
        cout << "\nEnter payment method (Cash/Credit): ";
        cin >> paymentMethod;

        if (paymentMethod == "Cash" || paymentMethod == "cash") {
            CashPayment cashPayment;
            cashPayment.processPayment(customerCounter, totalAmount);
        } else if (paymentMethod == "Credit" || paymentMethod == "credit") {
            CreditCardPayment creditPayment;
            creditPayment.processPayment(customerCounter, totalAmount);
        } else {
            cout << "Invalid payment method selected.\n";
        }

        // Notification Preferences
        string notificationPreference;
        cout << "\nWould you like to receive notifications by Email or SMS? (Email/SMS): ";
        cin >> notificationPreference;

        if (notificationPreference == "Email" || notificationPreference == "email") {
            EmailNotification emailNotif;
            emailNotif.sendNotification(email, "Your order has been placed successfully.");
        } else if (notificationPreference == "SMS" || notificationPreference == "sms") {
            SMSNotification smsNotif;
            smsNotif.sendNotification(phone, "Your order has been placed successfully.");
        } else {
            cout << "No notification preference selected.\n";
        }

        // Display Receipt
        cout << "\n--- Receipt ---\n";
        cout << "Customer Name: " << name << "\n";
        cout << "Phone Number: " << phone << "\n";
        if (!address.empty()) {
            cout << "Delivery Address: " << address << "\n";
        }
        cout << "\nItems Ordered:\n";
        for (const auto& item : selectedItems) {
            cout << "- " << item.first << " ($" << item.second << ")\n";
        }
        cout << "\nTotal Amount Paid: $" << totalAmount << "\n";
        cout << "Payment Method: " << paymentMethod << "\n";
        cout << "Notification Preference: " << notificationPreference << "\n";

        cout << "\nThank you for your order! Your receipt has been generated.\n";
    }

    return 0;
}
