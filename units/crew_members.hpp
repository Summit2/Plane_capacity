#pragma once
#include "unit.hpp"
#include <string>

class Pilot : public Unit {
public:
    Pilot();
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;

    bool canAddHandLuggage() override;
    bool canAddLuggage() override;
};

class FlightAttendant : public Unit {
public:
    FlightAttendant();
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;

    bool canAddHandLuggage() override;
    bool canAddLuggage() override;
};
