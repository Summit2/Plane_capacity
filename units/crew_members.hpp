#pragma once
#include "unit.hpp"
#include <string>

class Pilot : public Unit {
public:
    Pilot(int id);
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;
    int getId() const override;

    bool canAddHandLuggage() override;
    bool canAddLuggage() override;

private:
    int id;
};

class FlightAttendant : public Unit {
public:
    FlightAttendant(int id);
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;
    int getId() const override;

    bool canAddHandLuggage() override;
    bool canAddLuggage() override;

private:
    int id;
};
