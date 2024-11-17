#include "../units/passengers.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <memory>

// g++ --coverage -g -O0 -fsanitize=address -std=c++2a     -Wall -Werror -Wextra units/passengers.cpp     tests/test_passengers.cpp -o     test_passengers

int Unit::idCounter = 0;

void testEconomy()
{

    int handLuggageSmall = 10, handLuggageLarge = 11;
    int luggageSmall = 24, luggageLarge = 25;
    std::unique_ptr<Economy> economySmallLuggage = std::make_unique<Economy>(handLuggageSmall, luggageSmall);
    assert(economySmallLuggage->getId() == 0);
    assert(economySmallLuggage->getHandLuggageWeight() == handLuggageSmall);

    assert(economySmallLuggage->getLuggageWeight() == luggageSmall);
    assert(economySmallLuggage->getType() == "ECONOMY");
    assert(economySmallLuggage->canAddHandLuggage() == true);
    assert(economySmallLuggage->canAddLuggage() == true);

    std::unique_ptr<Economy> economyLargeLuggage = std::make_unique<Economy>(handLuggageLarge, luggageLarge);
    assert(economyLargeLuggage->getId() == 1);
    assert(economyLargeLuggage->getHandLuggageWeight() == handLuggageLarge);
    assert(economyLargeLuggage->getLuggageWeight() == luggageLarge);
    assert(economyLargeLuggage->getType() == "ECONOMY");
    assert(economyLargeLuggage->canAddHandLuggage() == false);
    assert(economyLargeLuggage->canAddLuggage() == false);
};

void testBusiness()
{

    int handLuggageSmall = 24, handLuggageLarge = 25;
    int luggageSmall = 40, luggageLarge = 41;
    std::unique_ptr<Business> businessSmallLuggage = std::make_unique<Business>(handLuggageSmall, luggageSmall);
    assert(businessSmallLuggage->getId() == 2);
    assert(businessSmallLuggage->getHandLuggageWeight() == handLuggageSmall);
    assert(businessSmallLuggage->getLuggageWeight() == luggageSmall);
    assert(businessSmallLuggage->getType() == "BUSINESS");
    assert(businessSmallLuggage->canAddHandLuggage() == true);
    assert(businessSmallLuggage->canAddLuggage() == true);

    std::unique_ptr<Business> businessLargeLuggage = std::make_unique<Business>(handLuggageLarge, luggageLarge);
    assert(businessLargeLuggage->getId() == 3);
    assert(businessLargeLuggage->getHandLuggageWeight() == handLuggageLarge);
    assert(businessLargeLuggage->getLuggageWeight() == luggageLarge);
    assert(businessLargeLuggage->getType() == "BUSINESS");
    assert(businessLargeLuggage->canAddHandLuggage() == false);
    assert(businessLargeLuggage->canAddLuggage() == false);
};

void testFirstClass()
{

    int handLuggageSmall = 60, handLuggageLarge = 61;
    int luggage = std::pow(2, 10);
    std::unique_ptr<FirstClass> firstClassSmallLuggage = std::make_unique<FirstClass>(handLuggageSmall, luggage);
    assert(firstClassSmallLuggage->getId() == 4);
    assert(firstClassSmallLuggage->getHandLuggageWeight() == handLuggageSmall);
    assert(firstClassSmallLuggage->getLuggageWeight() == luggage);

    assert(firstClassSmallLuggage->getType() == "FIRST CLASS");
    assert(firstClassSmallLuggage->canAddHandLuggage() == true);
    assert(firstClassSmallLuggage->canAddLuggage() == true);

    std::unique_ptr<FirstClass> firstClassLargeLuggage = std::make_unique<FirstClass>(handLuggageLarge, luggage);
    assert(firstClassLargeLuggage->getId() == 5);
    assert(firstClassLargeLuggage->getHandLuggageWeight() == handLuggageLarge);
    assert(firstClassLargeLuggage->getLuggageWeight() == luggage);
    assert(firstClassLargeLuggage->getType() == "FIRST CLASS");
    assert(firstClassLargeLuggage->canAddHandLuggage() == false);
    assert(firstClassLargeLuggage->canAddLuggage() == true);
};

int main()
{

    testEconomy();
    testBusiness();
    testFirstClass();

    std::cout << "Passengers tests passed" << std::endl;

    return 0;
}