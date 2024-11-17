#pragma once

#include <string>

//abstract class
class Unit {

public:
    virtual int getId() const = 0;
    virtual int getHandLuggageWeight() const = 0;
    virtual int getLuggageWeight() const = 0;
    virtual bool canAddLuggage() = 0;
    virtual bool canAddHandLuggage() = 0;
    virtual std::string getType() const = 0;
};
