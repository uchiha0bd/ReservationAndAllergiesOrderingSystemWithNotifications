cmake_minimum_required(VERSION 3.10)
project(ReservationAndAllergiesOrderingSystem)

set(CMAKE_CXX_STANDARD 17)

# Add all source files
set(SOURCES
        main.cpp
        Allergy.cpp
        Customer.cpp
        Menu.cpp
        Notification.cpp
        Order.cpp
        Payment.cpp
        Reservation.cpp
        suggestion.cpp
)

#add_executable(main ${SOURCES})
add_executable(main main.cpp Controller.cpp Menu.cpp Customer.cpp Order.cpp Reservation.cpp Notification.cpp Allergy.cpp)
