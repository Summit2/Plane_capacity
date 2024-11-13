#pragma once
#include "unit.hpp"
#include <string>

class Economy : public Unit {
public:
    Economy(int id, int hand_weight, int luggage_weight);
    bool canAddLuggage(int luggage_weight) override;
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;

    int getId() const override;
private:
    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};

class Business : public Unit {
public:
    Business(int id, int hand_weight, int luggage_weight);
    bool canAddLuggage(int luggage_weight) override;
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;
    int getId() const override;

private:
    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};

class FirstClass : public Unit {
public:
    FirstClass(int id, int hand_weight, int luggage_weight);
    bool canAddLuggage(int luggage_weight) override;
    int getHandLuggageWeight() const override;
    int getLuggageWeight() const override;
    std::string getType() const override;
    int getId() const override;

private:
    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};
