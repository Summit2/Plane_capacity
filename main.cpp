#include "units/crew_members.hpp"
#include "units/passengers.hpp"
#include "units/plane.hpp"
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
// g++ -std=c++2a -O2 -fsanitize=address -Wall -Werror -Wextra -Wno-maybe-uninitialized -I ./units/ main.cpp units/crew_members.cpp units/passengers.cpp units/plane.cpp -o main

int main()
{
    // Сначала вводятся сегменты самолета
    int economySegmentCapacity = 0, businessSegmentCapacity = 0, firstClassSegmentCapacity = 0;
    for (int i = 0; i < 3; i++) {
        std::string tempSegmentName;
        int tempSegmentCapacity;
        std::cin >> tempSegmentName >> tempSegmentCapacity;

        if (tempSegmentName == "ECONOMY_CLASS_SEGMENT") {
            economySegmentCapacity = tempSegmentCapacity;
        } else if (tempSegmentName == "BUSINESS_CLASS_SEGMENT") {
            businessSegmentCapacity = tempSegmentCapacity;
        } else if (tempSegmentName == "FIRST_CLASS_SEGMENT") {
            firstClassSegmentCapacity = tempSegmentCapacity;
        }
    }

    Plane plane(economySegmentCapacity, businessSegmentCapacity, firstClassSegmentCapacity);
    // Plane plane(1000, 2000, 3000);
    // Общий счетчик ID
    int idCounter = 0;

    //     // Вводятся пилоты - 2 шт.
    for (int i = 0; i < 2; i++) {
        std::string tempLabel;
        int tempHandLuggage, tempLuggage;
        std::cin >> tempLabel >> tempHandLuggage >> tempLuggage;

        std::shared_ptr<Pilot> pilot = std::make_shared<Pilot>(idCounter);
        plane.addPassenger(pilot);

        // std::cout << "Pilot ID: " << pilot->getId() << std::endl;
        //
        idCounter++;
    }

    // Вводятся бортпроводники - 6 шт.
    for (int i = 0; i < 6; i++) {
        std::string tempLabel;
        int tempHandLuggage, tempLuggage;
        // std::cout<<"Введите бортпроводника:";
        std::cin >> tempLabel >> tempHandLuggage >> tempLuggage;

        std::shared_ptr<FlightAttendant> attendant = std::make_shared<FlightAttendant>(idCounter);
        plane.addPassenger(attendant);

        // std::cout << "Flight Attendant ID: " << attendant->getId() << std::endl;

        idCounter++;
    }

    //Теперь вводятся пассажиры
    std::string line;
    std::getline(std::cin, line);
    while (std::getline(std::cin, line)) {

        std::stringstream ss(line);

        std::string tempPassengerLabel;
        std::vector<int> allTempLuggage;
        int handLuggage1, handLuggage2 = 0, luggage1 = 0, luggage2 = 0;

        // Считываем тип класса и вес ручной клади
        ss >> tempPassengerLabel >> handLuggage1;

        allTempLuggage.push_back(handLuggage1);
        // Считываем второй вес ручной клади, если есть
        if (ss >> handLuggage2) {
            // Считываем первый вес багажа, если есть
            allTempLuggage.push_back(handLuggage2);
            if (ss >> luggage1) {
                allTempLuggage.push_back(luggage1);
                // Считываем второй вес багажа, если есть
                if (ss >> luggage2) {
                    allTempLuggage.push_back(luggage2);
                }
            }
        }

        int finalHandLuggage = 0, finalLuggage = 0;

        switch (allTempLuggage.size()) {
        case 1:

            finalHandLuggage = allTempLuggage[0];
            break;
        case 2:

            if (tempPassengerLabel == "ECONOMY") {
                finalHandLuggage = allTempLuggage[0];
                finalLuggage = allTempLuggage[1];
            } else {
                finalHandLuggage = allTempLuggage[0] + allTempLuggage[1];
            }
            break;

        case 3:
            finalHandLuggage = allTempLuggage[0] + allTempLuggage[1];
            finalLuggage = allTempLuggage[2];
            break;

        case 4:
            finalHandLuggage = allTempLuggage[0] + allTempLuggage[1];
            finalLuggage = allTempLuggage[2] + allTempLuggage[3];
            break;
        }

        std::shared_ptr<Unit> tempPassenger;

        if (tempPassengerLabel == "ECONOMY")
            tempPassenger = std::make_shared<Economy>(idCounter, finalHandLuggage, finalLuggage);
        else if (tempPassengerLabel == "BUSINESS")
            tempPassenger = std::make_shared<Business>(idCounter, finalHandLuggage, finalLuggage);
        else if (tempPassengerLabel == "FIRST_CLASS")
            tempPassenger = std::make_shared<FirstClass>(idCounter, finalHandLuggage, finalLuggage);

        // std::cout<<tempPassenger->getId()<<std::endl;

        bool canAddPassenger = plane.addPassenger(tempPassenger);

        if (canAddPassenger == false) {
            std::cout << "!!CANT REGISTER " << tempPassenger->getType() << " PASSENGER, ID = " << tempPassenger->getId() << "!!";
        }

        idCounter++;
    }

    return 0;
}
