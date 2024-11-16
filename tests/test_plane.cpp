#include <cassert>
#include "../units/plane.hpp"
#include <cassert>
#include <iostream>

//g++ --coverage -g -O0 -fsanitize=address -std=c++2a     -Wall -Werror -Wextra units/plane.cpp     units/passengers.cpp units/crew_members.cpp     tests/test_plane.cpp -o test_plane
void testLuggageValues(){
    
    int maxWeightEconomySegment = 100;
    int maxWeightBusinessSegment = 200;
    int maxWeightFirstClassSegment =300;
    Plane plane{maxWeightEconomySegment,maxWeightBusinessSegment,maxWeightFirstClassSegment};
    assert (plane.getCurrentLuggageWeightEconomy() == 0);
    assert (plane.getCurrentLuggageWeightBusiness() == 0);
    assert (plane.getCurrentLuggageWeightFirstClass() == 0);

    //добавим грузы новых пассажиров
    std::shared_ptr<Economy> econom = std::make_shared<Economy>(1,10,24);
    std::shared_ptr<Business> business = std::make_shared<Business>(2, 24,40);
    std::shared_ptr<FirstClass> firstClass = std::make_shared<FirstClass>(3, 60,100);
    plane.addPassenger(econom);
    assert (plane.getCurrentLuggageWeightEconomy() == 34);
    
    plane.addPassenger(business);
    assert (plane.getCurrentLuggageWeightBusiness() == 64 );

    plane.addPassenger(firstClass);
    assert (plane.getCurrentLuggageWeightFirstClass() == 160);

    assert ( plane.getTotalLuggageWeight() == (34+64+160));
}



int main(){


     


    std::cout<<"Plane tests passed"<<std::endl;
     
    return 0;
}