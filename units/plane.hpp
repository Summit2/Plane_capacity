#pragma once

#include "unit.hpp"
#include <vector>
#include <memory>
#include <string>

class Plane {
public:
    Plane(int max_weight_economy, int max_weight_business, int max_weight_firstclass);

    bool addPassenger(std::shared_ptr<Unit> passenger);

    int getTotalLuggageWeight();

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

