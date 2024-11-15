#include <cassert>
#include "../units/passengers.hpp"
#include <iostream>
#include <memory>
#include <cmath>


// g++ --coverage -g -O0 -fsanitize=address -std=c++2a     -Wall -Werror -Wextra units/passengers.cpp     tests/test_passengers.cpp -o     test_passengers
void testEconomy(){
    int idSmall=0,idLarge=1;
    int handLuggageSmall = 10, handLuggageLarge = 11;
    int luggageSmall = 24, luggageLarge = 25;
    std::unique_ptr<Economy> economySmallLuggage = std::make_unique<Economy>(idSmall, handLuggageSmall, luggageSmall);
    assert (economySmallLuggage->getId() == idSmall);
    assert ( economySmallLuggage->getHandLuggageWeight()==handLuggageSmall);
    // std::cout<<economySmallLuggage->getLuggageWeight()<<" " << luggageSmall<<std::endl;
    assert (economySmallLuggage->getLuggageWeight()==luggageSmall);
    assert (economySmallLuggage->getType() =="ECONOMY");
    assert(economySmallLuggage->canAddHandLuggage() == true);
    assert(economySmallLuggage->canAddLuggage() == true);


    std::unique_ptr<Economy> economyLargeLuggage = std::make_unique<Economy>(idLarge, handLuggageLarge, luggageLarge);
    assert (economyLargeLuggage->getId() == idLarge);
    assert ( economyLargeLuggage->getHandLuggageWeight()==handLuggageLarge);
    assert (economyLargeLuggage->getLuggageWeight()==luggageLarge);
    assert (economyLargeLuggage->getType() =="ECONOMY");
    assert(economyLargeLuggage->canAddHandLuggage() == false);
    assert(economyLargeLuggage->canAddLuggage() == false);

};

void testBusiness(){
    int idSmall=0,idLarge=1;
    int handLuggageSmall = 24, handLuggageLarge = 25;
    int luggageSmall = 40, luggageLarge = 41;
    std::unique_ptr<Business> businessSmallLuggage = std::make_unique<Business>(idSmall, handLuggageSmall, luggageSmall);
    assert (businessSmallLuggage->getId() == idSmall);
    assert ( businessSmallLuggage->getHandLuggageWeight()==handLuggageSmall);
    assert (businessSmallLuggage->getLuggageWeight()==luggageSmall);
    assert (businessSmallLuggage->getType() =="BUSINESS");
    assert(businessSmallLuggage->canAddHandLuggage() == true);
    assert(businessSmallLuggage->canAddLuggage() == true);


    std::unique_ptr<Business> businessLargeLuggage = std::make_unique<Business>(idLarge, handLuggageLarge, luggageLarge);
    assert (businessLargeLuggage->getId() == idLarge);
    assert ( businessLargeLuggage->getHandLuggageWeight()==handLuggageLarge);
    assert (businessLargeLuggage->getLuggageWeight()==luggageLarge);
    assert (businessLargeLuggage->getType() =="BUSINESS");
    assert(businessLargeLuggage->canAddHandLuggage() == false);
    assert(businessLargeLuggage->canAddLuggage() == false);

};

void testFirstClass(){
    int idSmall=0,idLarge=1;
    int handLuggageSmall = 60, handLuggageLarge = 61;
    int luggage = std::pow(2,10);
    std::unique_ptr<FirstClass> firstClassSmallLuggage = std::make_unique<FirstClass>(idSmall, handLuggageSmall, luggage);
    assert (firstClassSmallLuggage->getId() == idSmall);
    assert ( firstClassSmallLuggage->getHandLuggageWeight()==handLuggageSmall);
    assert (firstClassSmallLuggage->getLuggageWeight()==luggage);
    // std::cout<<firstClassSmallLuggage->getType()<<std::endl;
    assert (firstClassSmallLuggage->getType() == "FIRST CLASS");
    assert(firstClassSmallLuggage->canAddHandLuggage() == true);
    assert(firstClassSmallLuggage->canAddLuggage() == true);


    std::unique_ptr<FirstClass> firstClassLargeLuggage = std::make_unique<FirstClass>(idLarge, handLuggageLarge, luggage);
    assert (firstClassLargeLuggage->getId() == idLarge);
    assert ( firstClassLargeLuggage->getHandLuggageWeight()==handLuggageLarge);
    assert (firstClassLargeLuggage->getLuggageWeight()==luggage);
    assert (firstClassLargeLuggage->getType() == "FIRST CLASS" );
    assert(firstClassLargeLuggage->canAddHandLuggage() == false);
    assert(firstClassLargeLuggage->canAddLuggage() == true);

};



int main(){


     testEconomy();
     testBusiness();
     testFirstClass();


    std::cout<<"Tests passed"<<std::endl;
     
    return 0;
}