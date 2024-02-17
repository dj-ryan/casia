#include "Agent.h"
#include <iostream>

//default constructor
Agent::Agent() : id(0), currentLocation(0), locationMap("---------------------------------------------------------------------------------------------------"), targetLocation(0), credit(0) {}

// Constructor
Agent::Agent(int agentId, int initialLocation, int initialCredit)
    : id(agentId), currentLocation(initialLocation), targetLocation(0), locationMap("---------------------------------------------------------------------------------------------------"), credit(initialCredit) {}

// Getter functions
int Agent::getId() const {
    return id;
}

int Agent::getCurrentLocation() const {
    return currentLocation;
}

int Agent::getTargetLocation() const {
    return targetLocation;
}

const char* Agent::getLocationMap() const {
    return locationMap;
}

int Agent::getCredit() const {
    return credit;
}

// Setter functions
void Agent::setCurrentLocation(int location) {
    if(location = targetLocation) {
		locationMap[location] = '@';
    }
    else {
        locationMap[currentLocation] = '-';
        locationMap[location] = 'X';
        currentLocation = location;
    }
}

void Agent::setTargetLocation(int target) {
    locationMap[targetLocation] = '-';
    locationMap[target] = 'O';
    targetLocation = target;
}

//void Agent::setLocationMap(char newMap[101]) {
//    //locatichonMap = newMap;
//    strcpy_s(locationMap, newMap);
//}

void Agent::setCredit(int newCredit) {
    credit = newCredit;
}

// Display information
void Agent::displayInfo() const {
    std::cout << "Agent ID: " << id << "\n" << currentLocation
        << " -> " << targetLocation << "\nTotal Social Credit: " << credit << "\n" << locationMap << "\n";
}
