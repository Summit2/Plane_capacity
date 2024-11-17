#pragma once
#include "unit.hpp"
#include <string>

class Economy : public Unit {
public:
    Economy(int hand_weight, int luggage_weight);
    bool canAddHandLuggage() override;
    bool canAddLuggage() override;
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;

private:
    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};

class Business : public Unit {
public:
    Business(int hand_weight, int luggage_weight);

    bool canAddHandLuggage() override;
    bool canAddLuggage() override;
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;

private:
    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};

class FirstClass : public Unit {
public:
    FirstClass(int hand_weight, int luggage_weight);
    bool canAddHandLuggage() override;
    bool canAddLuggage() override;
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;

private:
    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};
