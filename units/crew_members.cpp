#include "crew_members.hpp"
#include "unit.hpp"

Pilot::Pilot() {};

int Pilot::getHandLuggageWeight() const
{
    return 0;
};
int Pilot::getLuggageWeight() const
{
    return 0;
};

std::string Pilot::getType() const
{
    return "PILOT";
};

bool Pilot::canAddHandLuggage()
{

    return true;
}
bool Pilot::canAddLuggage()
{

    return true;
}

FlightAttendant::FlightAttendant() {};

int FlightAttendant::getHandLuggageWeight() const
{
    return 0;
};
int FlightAttendant::getLuggageWeight() const
{
    return 0;
};
std::string FlightAttendant::getType() const
{
    return "FLIGHT ATTENDANT";
};

bool FlightAttendant::canAddHandLuggage()
{

    return true;
}
bool FlightAttendant::canAddLuggage()
{

    return true;
}
