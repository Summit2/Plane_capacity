#include "../units/crew_members.hpp"
#include "../units/plane.hpp"
#include <cassert>
#include <iostream>

//g++ --coverage -g -O0 -fsanitize=address -std=c++2a     -Wall -Werror -Wextra units/plane.cpp     units/passengers.cpp units/crew_members.cpp     tests/test_plane.cpp -o test_plane
// ./test_plane
// gcov test_plane.cpp
void testLuggageValues()
{

    int maxWeightEconomySegment = 100;
    int maxWeightBusinessSegment = 200;
    int maxWeightFirstClassSegment = 300;
    Plane plane { maxWeightEconomySegment, maxWeightBusinessSegment, maxWeightFirstClassSegment };
    assert(plane.getCurrentLuggageWeightEconomy() == 0);
    assert(plane.getCurrentLuggageWeightBusiness() == 0);
    assert(plane.getCurrentLuggageWeightFirstClass() == 0);

    //добавим грузы новых пассажиров
    std::shared_ptr<Economy> econom = std::make_shared<Economy>(1, 10, 24);
    std::shared_ptr<Business> business = std::make_shared<Business>(2, 24, 40);
    std::shared_ptr<FirstClass> firstClass = std::make_shared<FirstClass>(3, 60, 100);
    plane.addPassenger(econom);
    assert(plane.getCurrentLuggageWeightEconomy() == 34);

    plane.addPassenger(business);
    assert(plane.getCurrentLuggageWeightBusiness() == 64);

    plane.addPassenger(firstClass);
    assert(plane.getCurrentLuggageWeightFirstClass() == 160);

    assert(plane.getTotalLuggageWeight() == (34 + 64 + 160));
}
void testAddLuggageLogic()
{

    // int maxWeightEconomySegment = 100;
    // int maxWeightBusinessSegment = 200;
    // int maxWeightFirstClassSegment =300;
    Plane plane1 { 1, 1, 1 };

    std::shared_ptr<Pilot> pilot = std::make_shared<Pilot>(1);
    std::shared_ptr<FlightAttendant> flightAttendant = std::make_shared<FlightAttendant>(2);

    assert(plane1.addPassenger(pilot) == true);
    assert(plane1.addPassenger(flightAttendant) == true);

    int maxWeightEconomySegment = 100;
    int maxWeightBusinessSegment = 50;
    int maxWeightFirstClassSegment = 50;
    Plane plane2 { maxWeightEconomySegment, maxWeightBusinessSegment, maxWeightFirstClassSegment };

    plane2.addPassenger(std::make_shared<Economy>(3, 10, 24)); //34
    plane2.addPassenger(std::make_shared<Economy>(4, 10, 24)); //68
    assert(plane2.addPassenger(std::make_shared<Economy>(5, 10, 24)) == true); //102 > 100 -> пассажир добавится, но без багажа
    assert(plane2.getCurrentLuggageWeightEconomy() == (68 + 10)); //78 , так как прошлый пассажир сел, но его багаж сняли

    //теперь сажаем бизнес
    assert(plane2.addPassenger(std::make_shared<Business>(6, 24, 27)) == true); //51>50 -> переносим в эконом
    assert(plane2.getCurrentLuggageWeightEconomy() == 57); //здесь из-за бизнес пассажира ссадили 2 багажа 24+24 = 48, но добавили 27 ->78 - 48 + 27 = 57 в экономе
    assert(plane2.getCurrentLuggageWeightBusiness() == 24); //24 кг -> теперь в бизнесе только ручная кладь пассажира

    assert(plane2.addPassenger(std::make_shared<Business>(7, 20, 0)) == true);
    assert(plane2.getCurrentLuggageWeightBusiness() == 44); //теперь в бизнесе будет 44 кг
    assert(plane2.addPassenger(std::make_shared<Business>(8, 7, 1)) == false); //добавим бизнес пассажира, чтобы не поместилась ручная кладь 44+7 > 50
    assert(plane2.getCurrentLuggageWeightBusiness() == 44); // в бизнесе все также будет 44 кг

    //теперь сажаем бизнес класс
    assert(plane2.addPassenger(std::make_shared<FirstClass>(9, 0, 50)) == true); //полностью забили допустимый вес
    assert(plane2.addPassenger(std::make_shared<FirstClass>(9, 1, 0)) == false); //теперь не можем посадить даже легкого пассажира
}

int main()
{

    testLuggageValues();
    testAddLuggageLogic();

    std::cout << "Plane tests passed" << std::endl;

    return 0;
}