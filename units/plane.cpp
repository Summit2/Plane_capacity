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
        for(long unsigned int i=0; i < passengersEconomy.size(); ++i){
             std::cout<<passengersEconomy[i]->getId()<<" "<< passengersEconomy[i]->getHandLuggageWeight()<<" " << passengersEconomy[i]->getLuggageWeight() <<std::endl;
                    }
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
   
             }

           //если не помещается в эконом классе, то надо убрать чей-то багаж в эконом классе
            else{
                addLuggageToEconomy(passenger); 
            }
            passengersBusiness.push_back(passenger);
            
             
        }

        else if (typeOfPassenger == "FIRST CLASS"){
            //добавляем его ручную кладь
            currentWeightBusinessSegment += passenger->getHandLuggageWeight();

            if (currentWeightFirstClassSegment + passenger->getLuggageWeight() <= maxWeightFirstClassSegment){
                currentWeightFirstClassSegment += passenger->getLuggageWeight();                
            }
            else {
                    addLuggageToEconomy(passenger); 
            }
            passengersFirstClass.push_back(passenger);
        }
        
        return true;
    };


    int Plane::getTotalLuggageWeight(){
        return currentWeightEconomySegment + currentWeightBusinessSegment + currentWeightFirstClassSegment;
    }




    void Plane::addLuggageToEconomy(std::shared_ptr<Unit> vip_passenger){
        //если багаж не влезает, переносим его в эконом класс
                if (vip_passenger->getLuggageWeight() + currentWeightEconomySegment <= maxWeightEconomySegment){
                    currentWeightEconomySegment += vip_passenger->getLuggageWeight();
                    return;
                }
        //иначе начинаем чистить эконом класс

        //отсортируем сначала багаж по убыванию  
                    std::sort(passengersEconomy.begin(), passengersEconomy.end(), [](const std::shared_ptr<Unit>& a, const std::shared_ptr<Unit>& b) {
                        return a->getLuggageWeight() > b->getLuggageWeight();
                    });

                    //далее понимаем, багаж каких id эконом класса нам нужно снять
                    std::vector<int> idLuggageOut;
                    int sumLuggage=0; //суммарный вес багажа экономщиков, который мы снимем
                    for (int i = passengersEconomy.size()-1; i >= 0; i--)
                    {
                        sumLuggage+=passengersEconomy[i]->getLuggageWeight();
                        idLuggageOut.push_back(passengersEconomy[i]->getId());
                        if (sumLuggage>=vip_passenger->getLuggageWeight()){
                            break;
                        }
                        
                       
                    }
                    
                    //оповестим о том, что мы сняли багаж у таких пассажиров
                    for (size_t i = 0; i < idLuggageOut.size(); i++)
                    {
                        std::cout << "!!PASSENGER’S LUGGAGE REMOVED FROM FLIGHT, ID = {" << idLuggageOut[i] << "}!!"<<std::endl;
                    }
                    //уберем этот вес из эконом класса
                    currentWeightEconomySegment-= sumLuggage;

                    //добавим багаж пассажира в общий вес эконом класса
                    currentWeightEconomySegment += vip_passenger->getLuggageWeight();
    }