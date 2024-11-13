#include <iostream>
#include <vector>
#include "plane.hpp"
#include "crew_members.hpp"
#include "passengers.hpp"
#include <memory>

int main(){
    


    //Сначала вводятся сегменты самолета
    int economySegmentCapacity, businessSegmentCapacity, firstClassSegmentCapacity;
    for (int i=0; i<2; i++ ){
        std::string tempSegmentName;
        int tempSegmentCapacity;
        std::cin>>tempSegmentName>>tempSegmentCapacity;
        
        if (tempSegmentName == "ECONOMY_CLASS_SEGMENT"){
            economySegmentCapacity = tempSegmentCapacity;
        }
        else if (tempSegmentName == "BUSINESS_CLASS_SEGMENT"){
            businessSegmentCapacity = tempSegmentCapacity;
        }
        else if (tempSegmentName == "FIRST_CLASS_SEGMENT"){
            firstClassSegmentCapacity = tempSegmentCapacity;
        }
    }

    Plane plane(economySegmentCapacity, businessSegmentCapacity, firstClassSegmentCapacity);


    //общий счетчик
    int idCounter = 0;
    // Вводятся пилоты - 2 шт.

    for (int i = 0; i < 2; i++)
    {
        std::string tempLabel;
        int tempHandLuggage , tempLuggage;
        std::cin>>tempLabel>>tempHandLuggage>>tempLuggage;
        
        std::shared_ptr<Pilot> passenger = std::make_shared<Pilot>(idCounter,tempHandLuggage,tempLuggage);
        plane.addPassenger(passenger);
        idCounter++;
    }
    

    //Вводятся бортпроводники - 6 шт.
    for (int i = 0; i < 6; i++)
    {
        std::string tempLabel;
        int tempHandLuggage , tempLuggage;
        std::cin>>tempLabel>>tempHandLuggage>>tempLuggage;
        
        std::shared_ptr<FlightAttendant> passenger = std::make_shared<FlightAttendant>(idCounter,tempHandLuggage,tempLuggage);
        plane.addPassenger(passenger);
        idCounter++;
    }


    //Теперь ввод пассажиров

    
	// while (std::cin >> operation >> word) {

    int handLuggage;
    int luggage;

    std::shared_ptr<Economy> passenger = std::make_shared<Economy>(idCounter,100,100);
    std::cout<<passenger->getId();


    return 0;
}