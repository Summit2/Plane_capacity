#include "unit.hpp"
#include "plane.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>



Plane::Plane(int max_weight_economy, int max_weight_business, int max_weight_firstclass)
    : maxWeightEconomySegment(max_weight_economy),
      maxWeightBusinessSegment(max_weight_business),
      maxWeightFirstClassSegment(max_weight_firstclass),
      currentWeightEconomySegment(0),
      currentWeightBusinessSegment(0),
      currentWeightFirstClassSegment(0) {}

bool Plane::addPassenger(std::shared_ptr<Unit> passenger) {

        std::string typeOfPassenger = passenger->getType();

        
       

        
        // с пилотами и бортпроводниками все просто
        if (typeOfPassenger == "FLIGHT ATTENDANT" || typeOfPassenger == "PILOT") {
            flightAttendants.push_back(passenger);
            return true;}
        

        


        //проверяем, в норме ли у пассажира ручная кладь и багаж
        if (passenger->canAddHandLuggage()==false || passenger->canAddLuggage()==false){
            return false;
        }

       
        if (typeOfPassenger == "ECONOMY"){

            //проверка, влезет ли ручная кладь
            if (passenger->getHandLuggageWeight()+currentWeightEconomySegment<=maxWeightEconomySegment){
                
                currentWeightEconomySegment += passenger->getHandLuggageWeight();
                //проверка, влезет ли багаж
                if (currentWeightEconomySegment + passenger->getLuggageWeight() <= maxWeightEconomySegment){
                currentWeightEconomySegment += passenger->getLuggageWeight();
                }
                else {
                // если багаж не влез, то ссаживаем багаж
                std::cout << "!!PASSENGER’S LUGGAGE REMOVED FROM FLIGHT, ID = {" << passenger->getId() << "}!!"<<std::endl;
                //добавляем пассажира в список тех, у кого мы убрали багаж
                idPassengersEconomyNoLuggage.push_back(passenger->getId());
            }
            //добавляем пассажира
            passengersEconomy.push_back(passenger); 
            }
            else{
                //может быть случай, когда пассажир с ручной кладью не поместится
                return false;
            }
        }
        else if (typeOfPassenger == "BUSINESS"){

            //проверка, влезет ли ручная кладь
            if (passenger->getHandLuggageWeight()+currentWeightBusinessSegment<=maxWeightBusinessSegment){
                currentWeightBusinessSegment += passenger->getHandLuggageWeight();

                //проверка, влезет ли багаж
                if (currentWeightBusinessSegment + passenger->getLuggageWeight() <= maxWeightBusinessSegment){
                currentWeightBusinessSegment += passenger->getLuggageWeight();
                }
                else {
                // если багаж не влез, то мы гарантируем, что он влезет в отсек эконом класса
                addLuggageToEconomy(passenger);
            }
            //добавляем пассажира
            passengersBusiness.push_back(passenger); 
            }
            else{
                //может быть случай, когда пассажир с ручной кладью не поместится
                return false;
            }
             
        }

        else if (typeOfPassenger == "FIRST CLASS"){
           //проверка, влезет ли ручная кладь
            if (passenger->getHandLuggageWeight()+currentWeightFirstClassSegment<=maxWeightFirstClassSegment){
                currentWeightFirstClassSegment += passenger->getHandLuggageWeight();

                //проверка, влезет ли багаж
                if (currentWeightFirstClassSegment + passenger->getLuggageWeight() <= maxWeightFirstClassSegment){
                currentWeightFirstClassSegment += passenger->getLuggageWeight();
                }
                else {
                // если багаж не влез, то мы гарантируем, что он влезет в отсек эконом класса
                addLuggageToEconomy(passenger);
            }
            //добавляем пассажира
            passengersFirstClass.push_back(passenger); 
            }
            else{
                //может быть случай, когда пассажир с ручной кладью не поместится
                return false;
            }
        }
        
        return true;
    };


    int Plane::getTotalLuggageWeight(){
        return currentWeightEconomySegment + currentWeightBusinessSegment + currentWeightFirstClassSegment;
    }

    int Plane::getCurrentLuggageWeightEconomy(){
        return currentWeightEconomySegment;
    }
    int Plane::getCurrentLuggageWeightBusiness(){
        return currentWeightBusinessSegment;
    }
    int Plane::getCurrentLuggageWeightFirstClass(){
        return currentWeightFirstClassSegment;
    }




    void Plane::addLuggageToEconomy(std::shared_ptr<Unit> passenger){
        //если багаж не влезает, переносим его в эконом класс
                if (passenger->getLuggageWeight() + currentWeightEconomySegment <= maxWeightEconomySegment){
                    currentWeightEconomySegment += passenger->getLuggageWeight();
                    return;
                }

        // если эконом класс забит, начинаем его чистить 

        //отсортируем сначала багаж по убыванию  
                    std::sort(passengersEconomy.begin(), passengersEconomy.end(), [](const std::shared_ptr<Unit>& a, const std::shared_ptr<Unit>& b) {
                        return a->getLuggageWeight() > b->getLuggageWeight();
                    });

                    //далее понимаем, багаж каких id эконом класса нам нужно снять
                    std::vector<int> idLuggageOut;
                    int sumLuggage=0; //суммарный вес багажа экономщиков, который мы снимем
                    for (int i = passengersEconomy.size()-1; i >= 0; i--)
                    {
                        //сначала проверим, может, мы смотрим пассажира, у которого мы уже ссадили багаж
                        auto result{std::find(std::begin(idPassengersEconomyNoLuggage), std::end(idPassengersEconomyNoLuggage), passengersEconomy[i]->getId())};
                        if (result != std::end(idPassengersEconomyNoLuggage)){
                            //если нашли такого человека, то нам не надо заново ссаживать его багаж
                            continue;
                        }
                        
                        
                        sumLuggage+=passengersEconomy[i]->getLuggageWeight();
                        idLuggageOut.push_back(passengersEconomy[i]->getId());
                        if (sumLuggage>=passenger->getLuggageWeight()){
                            break;
                        }
                        
                       
                    }
                    
                    //запишем их в массив тех, у кого сняли багаж, чтобы случайно не ссадить их заново
                    //и оповестим о том, что мы сняли багаж у таких пассажиров
                    for (size_t i = 0; i < idLuggageOut.size(); i++)
                    {
                        // std::cout<<"Убираем багаж у "<<idLuggageOut[i]<<std::endl;
                        idPassengersEconomyNoLuggage.push_back(idLuggageOut[i]);
                        std::cout << "!!PASSENGER’S LUGGAGE REMOVED FROM FLIGHT, ID = {" << idLuggageOut[i] << "}!!"<<std::endl;
                    }
                    //уберем этот вес из эконом класса
                    currentWeightEconomySegment-= sumLuggage;

                    //добавим багаж пассажира в общий вес эконом класса
                    currentWeightEconomySegment += passenger->getLuggageWeight();
    }