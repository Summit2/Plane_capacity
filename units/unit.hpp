#pragma once

#include <string>

//abstract class
class Unit {

private:
    static int idCounter;
    int id;

protected:
    Unit()
        : id(idCounter++) {};

public:
    virtual int getId() const
    {
        return id;
    };
    virtual int getHandLuggageWeight() const = 0;
    virtual int getLuggageWeight() const = 0;
    virtual bool canAddLuggage() = 0;
    virtual bool canAddHandLuggage() = 0;
    virtual std::string getType() const = 0;
};
