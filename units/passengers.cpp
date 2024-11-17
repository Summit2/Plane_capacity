#include "passengers.hpp"
#include "unit.hpp"
#include <iostream>

Economy::Economy(int hand_weight, int luggage_weight)
    : HandLuggageWeight(hand_weight)
    , LuggageWeight(luggage_weight) {};

bool Economy::canAddHandLuggage()
{

    return HandLuggageWeight <= 10;
};

bool Economy::canAddLuggage()
{
    return LuggageWeight <= 24;
}
int Economy::getHandLuggageWeight() const
{
    return HandLuggageWeight;
}
int Economy::getLuggageWeight() const
{
    return LuggageWeight;
}

std::string Economy::getType() const
{
    return "ECONOMY";
};

Business::Business(int hand_weight, int luggage_weight)
    : HandLuggageWeight(hand_weight)
    , LuggageWeight(luggage_weight) {};

bool Business::canAddHandLuggage()
{
    return (HandLuggageWeight <= 24);
};

bool Business::canAddLuggage()
{
    return LuggageWeight <= 40;
}
int Business::getHandLuggageWeight() const
{
    return HandLuggageWeight;
}
int Business::getLuggageWeight() const
{
    return LuggageWeight;
}

std::string Business::getType() const
{
    return "BUSINESS";
};

FirstClass::FirstClass(int hand_weight, int luggage_weight)
    : HandLuggageWeight(hand_weight)
    , LuggageWeight(luggage_weight) {};

bool FirstClass::canAddHandLuggage()
{
    return (HandLuggageWeight <= 60);
};
bool FirstClass::canAddLuggage()
{
    return true;
};
int FirstClass::getHandLuggageWeight() const
{
    return HandLuggageWeight;
}
int FirstClass::getLuggageWeight() const
{
    return LuggageWeight;
}
std::string FirstClass::getType() const
{
    return "FIRST CLASS";
};
