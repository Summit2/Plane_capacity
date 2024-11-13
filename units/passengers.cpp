#include <iostream>
#include "unit.hpp"

class Economy : public Unit
{
 public:
  Economy(int id, int hand_weight, int luggage_weight) : id(id), HandLuggageWeight(hand_weight), LuggageWeight(luggage_weight) { };

    bool canAddHandLuggage() override{
        return false ? (HandLuggageWeight>10) : true;
    };

    bool canAddLuggage() override {
        return LuggageWeight<=24;
    }
    int getHandLuggageWeight() const override {
        return HandLuggageWeight;
    }
    int getLuggageWeight() const override {
        return LuggageWeight;
    }

    std::string getType() const override{
    return "ECONOMY";
  };
  int getId() const override{
    return id;
  }

    private:

    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};



class Business : public Unit {
public:
    Business(int id, int hand_weight, int luggage_weight) : id(id), HandLuggageWeight(hand_weight), LuggageWeight(luggage_weight) { };

    bool canAddHandLuggage() override{
        return false ? (HandLuggageWeight>24) : true;
    };

    bool canAddLuggage() override {
        return LuggageWeight<=40;
    }
    int getHandLuggageWeight() const override {
        return HandLuggageWeight;
    }
    int getLuggageWeight() const override {
        return LuggageWeight;
    }

    int getId() const override{
    return id;
  }

    std::string getType() const override{
    return "BUSINESS";
  };
    private:

    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};


class FirstClass : public Unit {
public:
    FirstClass(int id, int hand_weight, int luggage_weight) : id(id), HandLuggageWeight(hand_weight), LuggageWeight(luggage_weight) { };

    bool canAddHandLuggage() override{
        return false ? (HandLuggageWeight>60) : true;
    };
    bool canAddLuggage() override {
        return true;
    };
    int getHandLuggageWeight() const override {
        return HandLuggageWeight;
    }
    int getLuggageWeight() const override {
        return LuggageWeight;
    }
    std::string getType() const override{
    return "FIRST CLASS";
  };
  int getId() const override{
    return id;
  }
    private:

    int id;
    int HandLuggageWeight;
    int LuggageWeight;
};

 