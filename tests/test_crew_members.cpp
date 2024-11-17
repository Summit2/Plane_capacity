#include "../units/crew_members.hpp"
#include <cassert>
#include <iostream>
#include <memory>

//g++ --coverage -g -O0 -fsanitize=address -std=c++2a     -Wall -Werror -Wextra units/crew_members.cpp     tests/test_crew_members.cpp -o     test_crew_members

int Unit::idCounter = 0;

void testPilot()
{

    std::unique_ptr<Pilot> pilot = std::make_unique<Pilot>();
    assert(pilot->getId() == 0);
    assert(pilot->getHandLuggageWeight() == 0);
    assert(pilot->getLuggageWeight() == 0);
    assert(pilot->getType() == "PILOT");
    assert(pilot->canAddHandLuggage() == true);
    assert(pilot->canAddLuggage() == true);
};
void testFlightAttendant()
{

    std::unique_ptr<FlightAttendant> attendant = std::make_unique<FlightAttendant>();
    assert(attendant->getId() == 1);
    assert(attendant->getHandLuggageWeight() == 0);
    assert(attendant->getLuggageWeight() == 0);
    assert(attendant->getType() == "FLIGHT ATTENDANT");
    assert(attendant->canAddHandLuggage() == true);
    assert(attendant->canAddLuggage() == true);
};

int main()
{

    testPilot();

    testFlightAttendant();

    std::cout << "Crew members tests passed" << std::endl;

    return 0;
}