#include "unit.hpp"
#include "plane.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

#define tes

Plane::Plane(int max_weight_economy, int max_weight_business, int max_weight_firstclass)
    : maxWeightEconomySegment(max_weight_economy),
      maxWeightBusinessSegment(max_weight_business),
      maxWeightFirstClassSegment(max_weight_firstclass),
      currentWeightEconomySegment(0),
      currentWeightBusinessSegment(0),
      currentWeightFirstClassSegment(0) {}

bool Plane::addPassenger(std::shared_ptr<Unit> passenger) {

        std::string typeOfPassenger = passenger->getType();

        #ifdef test
        std::cout <<std::endl<< "Тип пассажира "<<typeOfPassenger<<std::endl;
        #endif
        
        // с пилотами и бортпроводниками все просто
        if (typeOfPassenger == "FLIGHT ATTENDANT" || typeOfPassenger == "PILOT") {
            flightAttendants.push_back(passenger);
            return true;}
        

        

        //проверяем, в норме ли у пассажира ручная кладь и багаж
        if (passenger->canAddHandLuggage()==false || passenger->canAddLuggage()==false){
            return false;
        }

       
        if (typeOfPassenger == "ECONOMY"){

            currentWeightEconomySegment += passenger->getHandLuggageWeight();

            if (currentWeightEconomySegment + passenger->getLuggageWeight() <= maxWeightEconomySegment){
                currentWeightEconomySegment += passenger->getLuggageWeight();
                passengersEconomy.push_back(passenger); 
            }
            else {
                // ссаживаем его багаж
                std::cout << "!!PASSENGER’S LUGGAGE REMOVED FROM FLIGHT, ID = {" << passenger->getId() << "}!!"<<std::endl;
            }
        }
        else if (typeOfPassenger == "BUSINESS"){
            //ручную кладь оставляем в бизнес классе
             currentWeightBusinessSegment += passenger->getHandLuggageWeight();

             if (currentWeightBusinessSegment + passenger->getLuggageWeight() <= maxWeightBusinessSegment){
                currentWeightBusinessSegment += passenger->getLuggageWeight();
                passengersBusiness.push_back(passenger);
                return true;
             }
             else {
                

                //если багаж не влезает, переносим его в эконом класс
                if (passenger->getLuggageWeight() + currentWeightEconomySegment <= maxWeightEconomySegment){
                    currentWeightEconomySegment += passenger->getLuggageWeight();
                    passengersBusiness.push_back(passenger);
                    return true;

                }
                //если не помещается в эконом классе, то надо убрать чей-то багаж в эконом классе
                else{
                    //отсортируем сначала багаж по возрастанию  
                    std::sort(passengersEconomy.begin(), passengersEconomy.end(), [](const std::shared_ptr<Unit>& a, const std::shared_ptr<Unit>& b) {
                        return a->getLuggageWeight() > b->getLuggageWeight();
                    });
                
                    


             }
        }}

        else if (typeOfPassenger == "FIRST CLASS"){
            //добавляем его ручную кладь
            currentWeightBusinessSegment += passenger->getHandLuggageWeight();

            if (currentWeightFirstClassSegment + passenger->getLuggageWeight() <= maxWeightFirstClassSegment){
                currentWeightFirstClassSegment += passenger->getLuggageWeight();
                passengersFirstClass.push_back(passenger);
                return true;
             }
             else {

             }
        }
        else {
            return false;
        };
        return true;
    };


    int Plane::getTotalLuggageWeight(){
        return currentWeightEconomySegment + currentWeightBusinessSegment + currentWeightFirstClassSegment;
    }



