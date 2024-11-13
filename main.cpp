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

    // Вводятся пилоты

    



    //Вводятся бортпроводники




    //Теперь ввод пассажиров

    int idCounter = 0;

    int handLuggage;
    int luggage;

    std::shared_ptr<Economy> passenger = std::make_shared<Economy>(idCounter,100,100);
    std::cout<<passenger->getId();


    return 0;
}