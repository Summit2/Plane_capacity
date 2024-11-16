#pragma once

#include "unit.hpp"
#include <vector>
#include <memory>
#include <string>
#include "passengers.hpp"


class Plane {
public:
    Plane(int max_weight_economy, int max_weight_business, int max_weight_firstclass);

    bool addPassenger(std::shared_ptr<Unit> passenger);

    int getTotalLuggageWeight();
    void addLuggageToEconomy(std::shared_ptr<Unit> vip_passenger);

    int getCurrentLuggageWeightEconomy();
    int getCurrentLuggageWeightBusiness();
    int getCurrentLuggageWeightFirstClass();

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

    //id пассажиров, чей багаж был ссажен
    std::vector<int> idPassengersEconomyNoLuggage;
    
};

