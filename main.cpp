#include <iostream>
#include <vector>
#include <string>
#include "Controller.h"

void showMainMenu() {
    std::cout << "\n--- Welcome to the HelloThere Restaurant System ---\n";
    std::cout << "1. Register Customer\n";
    std::cout << "2. View Menu\n";
    std::cout << "3. Place Order\n";
    std::cout << "4. Create Reservation\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Controller controller;
    std::string customerID;

    while (true) {
        showMainMenu();

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // To handle newline characters in input.

        switch (choice) {
            case 1: { // Register Customer
                std::string name, phone, email;
                std::cout << "Enter customer name: ";
                std::getline(std::cin, name);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phone);
                std::cout << "Enter email: ";
                std::getline(std::cin, email);
                controller.registerCustomer(name, phone, email);
                break;
            }

            case 2: { // View Menu
                if (customerID.empty()) {
                    std::cout << "You must register or select a customer first.\n";
                    break;
                }
                controller.displayMenu(customerID);
                break;
            }

            case 3: { // Place Order
                if (customerID.empty()) {
                    std::cout << "You must register or select a customer first.\n";
                    break;
                }

                controller.displayMenu(customerID);

                std::cout << "\nEnter item IDs separated by spaces (0 to finish): ";
                std::vector<int> itemIDs;
                int id;
                while (std::cin >> id && id != 0) {
                    itemIDs.push_back(id);
                }
                std::cin.ignore();

                std::string orderType;
                std::cout << "Order type (DineIn/Delivery): ";
                std::getline(std::cin, orderType);

                if (orderType == "DineIn") {
                    int tableNo;
                    std::cout << "Enter table number: ";
                    std::cin >> tableNo;
                    std::cin.ignore();
                    controller.placeOrder(customerID, itemIDs, orderType, tableNo);
                } else if (orderType == "Delivery") {
                    std::string address;
                    std::cout << "Enter delivery address: ";
                    std::getline(std::cin, address);
                    controller.placeOrder(customerID, itemIDs, orderType, -1, address);
                } else {
                    std::cout << "Invalid order type.\n";
                }
                break;
            }

            case 4: { // Create Reservation
                if (customerID.empty()) {
                    std::cout << "You must register or select a customer first.\n";
                    break;
                }

                std::string date, time, paymentStatus;
                int tableNo;

                std::cout << "Enter reservation date (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                std::cout << "Enter reservation time (HH:MM): ";
                std::getline(std::cin, time);
                std::cout << "Enter table number: ";
                std::cin >> tableNo;
                std::cin.ignore();
                std::cout << "Enter payment status (Leave blank for Walk-In): ";
                std::getline(std::cin, paymentStatus);

                controller.createReservation(customerID, date, time, tableNo, paymentStatus);
                break;
            }

            case 5: { // Exit
                std::cout << "Thank you for using the HelloThere Restaurant System. Goodbye!\n";
                return 0;
            }

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
