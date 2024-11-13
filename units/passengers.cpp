#include <iostream>
#include "unit.hpp"
#include "passengers.hpp"


  Economy::Economy(int id, int hand_weight, int luggage_weight) : id(id), HandLuggageWeight(hand_weight), LuggageWeight(luggage_weight) { };

    bool Economy::canAddHandLuggage() {
        
        return HandLuggageWeight<=10;
        
    };

    bool Economy::canAddLuggage()  {
        return LuggageWeight<=24;
    }
    int Economy::getHandLuggageWeight() const  {
        return HandLuggageWeight;
    }
    int Economy::getLuggageWeight() const  {
        return LuggageWeight;
    }

    std::string Economy::getType() const {
    return "ECONOMY";
  };
  int Economy::getId() const {
    return id;
  };





    Business::Business(int id, int hand_weight, int luggage_weight) : id(id), HandLuggageWeight(hand_weight), LuggageWeight(luggage_weight) { };

    bool Business::canAddHandLuggage() {
        return  (HandLuggageWeight<=24);
    };

    bool Business::canAddLuggage()  {
        return LuggageWeight<=40;
    }
    int Business::getHandLuggageWeight() const  {
        return HandLuggageWeight;
    }
    int Business::getLuggageWeight() const  {
        return LuggageWeight;
    }

    int Business::getId() const {
    return id;
  }

    std::string Business::getType() const {
    return "BUSINESS";
  };



    FirstClass::FirstClass(int id, int hand_weight, int luggage_weight) : id(id), HandLuggageWeight(hand_weight), LuggageWeight(luggage_weight) { };

    bool FirstClass::canAddHandLuggage() {
        return (HandLuggageWeight<=60);
    };
    bool FirstClass::canAddLuggage()  {
        return true;
    };
    int FirstClass::getHandLuggageWeight() const  {
        return HandLuggageWeight;
    }
    int FirstClass::getLuggageWeight() const  {
        return LuggageWeight;
    }
    std::string FirstClass::getType() const {
    return "FIRST CLASS";
  };
  int FirstClass::getId() const {
    return id;
  }

 