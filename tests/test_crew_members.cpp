#include <cassert>
#include "../units/crew_members.hpp"
#include <iostream>
#include <memory>


void testPilot(){
    int id=0;
    std::unique_ptr<Pilot> pilot = std::make_unique<Pilot>(id);
    assert (pilot->getId() == 0);
    assert ( pilot->getHandLuggageWeight()==0);
    assert (pilot->getLuggageWeight()==0);
    assert (pilot->getType() =="PILOT");

};
void testFlightAttendant(){
int id=0;
    std::unique_ptr<FlightAttendant> pilot = std::make_unique<FlightAttendant>(id);
    assert (pilot->getId() == 0);
    assert ( pilot->getHandLuggageWeight()==0);
    assert (pilot->getLuggageWeight()==0);
    assert (pilot->getType() =="FLIGHT ATTENDANT");



};


int main(){


     testPilot();

     testFlightAttendant();

    std::cout<<"Tests passed"<<std::endl;
     
    return 0;
}