#include "unit.hpp"
#include "crew_members.hpp"


  Pilot::Pilot(int id) : id(id) { };
  
   int Pilot::getHandLuggageWeight() const {
    return 0;
   };
   int Pilot::getLuggageWeight() const {
    return 0;
   };

  std::string Pilot::getType() const {
    return "PILOT";
  };
  int Pilot::getId() const {
    return id;
  }
  bool Pilot::canAddHandLuggage()  {
        
        return true;  
    }
  bool Pilot::canAddLuggage()  {
       
        return true;  
  }




  FlightAttendant::FlightAttendant(int id) : id(id) { };
  
   int FlightAttendant::getHandLuggageWeight() const {
    return 0;
   };
   int FlightAttendant::getLuggageWeight() const {
    return 0;
   };
   std::string FlightAttendant::getType() const {
    return "FLIGHT ATTENDANT";
  };
  int FlightAttendant::getId() const {
    return id;
  }
  bool FlightAttendant::canAddHandLuggage()  {
        
        return true;  
    }
  bool FlightAttendant::canAddLuggage()  {
       
        return true;  
  }

