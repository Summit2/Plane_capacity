#include "../units/crew_members.hpp"
#include <cassert>
#include <iostream>
#include <memory>

//g++ --coverage -g -O0 -fsanitize=address -std=c++2a     -Wall -Werror -Wextra units/plane.cpp     units/passengers.cpp units/crew_members.cpp     tests/test_plane.cpp -o test_plane

void testPilot()
{
    int id = 0;
    std::unique_ptr<Pilot> pilot = std::make_unique<Pilot>(id);
    assert(pilot->getId() == 0);
    assert(pilot->getHandLuggageWeight() == 0);
    assert(pilot->getLuggageWeight() == 0);
    assert(pilot->getType() == "PILOT");
};
void testFlightAttendant()
{
    int id = 0;
    std::unique_ptr<FlightAttendant> pilot = std::make_unique<FlightAttendant>(id);
    assert(pilot->getId() == 0);
    assert(pilot->getHandLuggageWeight() == 0);
    assert(pilot->getLuggageWeight() == 0);
    assert(pilot->getType() == "FLIGHT ATTENDANT");
};

int main()
{

    testPilot();

    testFlightAttendant();

    std::cout << "Crew members tests passed" << std::endl;

    return 0;
}