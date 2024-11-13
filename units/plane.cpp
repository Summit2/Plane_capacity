#include "unit.hpp"
#include "plane.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
class Plane{

    public:

    Plane(int max_weigth_economy, int max_weight_business, int max_weight_firstclass ) :
    maxWeightEconomySegment(max_weigth_economy), maxWeightBusinessSegment(max_weight_business),maxWeightFirstClassSegment(max_weight_firstclass),
    currentWeightEconomySegment(0),currentWeightBusinessSegment(0),currentWeightFirstClassSegment(0)
    {};


    bool addPassenger(std::shared_ptr<Unit> passenger ){

        std::string typeOfPassenger = passenger->getType();
        
        // с пилотами и бортпроводниками все просто
        if (typeOfPassenger == "FLIGHT ATTENDANT") flightAttendants.push_back(passenger);
        else if (typeOfPassenger == "PILOT") pilots.push_back(passenger);


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
             if (currentWeightBusinessSegment + passenger->getLuggageWeight()+passenger->getHandLuggageWeight() <= maxWeightBusinessSegment){
                currentWeightBusinessSegment += (passenger->getLuggageWeight()+passenger->getHandLuggageWeight());
                passengersBusiness.push_back(passenger);
                return true;
             }
             else {
                //ручную кладь оставляем в бизнес классе
                currentWeightBusinessSegment += passenger->getHandLuggageWeight();

                //если багаж не влезает, переносим его в эконом класс
                if (passenger->getLuggageWeight() + currentWeightEconomySegment <= maxWeightEconomySegment){
                    currentWeightEconomySegment += passenger->getLuggageWeight();
                    

                }
                //если не помещается в эконом классе, то надо убрать чей-то багаж в эконом классе
                else{
                // int idWithMinWeight;
                // for (int i = 0; i < passengersEconomy.size(); i++)
                // {
                //    auto tempPassenger = passengersEconomy[i];
                //    if (tempPassenger->getLuggageWeight() 
                // }
                }
             }
        }

        else if (typeOfPassenger == "FIRST CLASS"){
            if (currentWeightFirstClassSegment + passenger->getLuggageWeight()+passenger->getHandLuggageWeight() <= maxWeightFirstClassSegment){
                currentWeightFirstClassSegment += (passenger->getLuggageWeight()+passenger->getHandLuggageWeight());
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


    int getTotalLuggageWeight(){
        return currentWeightEconomySegment + currentWeightBusinessSegment + currentWeightFirstClassSegment;
    }


    private:

    const int maxWeightEconomySegment;
    const int maxWeightBusinessSegment;
    const int maxWeightFirstClassSegment;

    int currentWeightEconomySegment;
    int currentWeightBusinessSegment;
    int currentWeightFirstClassSegment;

    std::vector<std::shared_ptr<Unit>> passengersEconomy;
    std::vector<std::shared_ptr<Unit>> passengersBusiness;
    std::vector<std::shared_ptr<Unit>> passengersFirstClass;

    std::vector<std::shared_ptr<Unit>> flightAttendants;
    std::vector<std::shared_ptr<Unit>> pilots;
};

