#include "unit.hpp"
#include "crew_members.hpp"

class Pilot : public Unit {

public:
  Pilot(int id) : id(id) { };
  
   int getHandLuggageWeight() const override{
    return 0;
   };
   int getLuggageWeight() const override{
    return 0;
   };

  std::string getType() const override{
    return "PILOT";
  };
  int getId() const override{
    return id;
  }

private:
 int id;
};

class FlightAttendant : public Unit {
public:
  FlightAttendant(int id) : id(id) { };
  
   int getHandLuggageWeight() const override{
    return 0;
   };
   int getLuggageWeight() const override{
    return 0;
   };
   std::string getType() const override{
    return "FLIGHT ATTENDANT";
  };
  int getId() const override{
    return id;
  }

private:
 int id;

};