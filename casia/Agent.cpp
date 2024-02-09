#include "Agent.h"
#include <iostream>

//default constructor
Agent::Agent() : id(0), currentLocation(0), locationMap(""), targetLocation(0), credit(0) {}

// Constructor
Agent::Agent(int agentId, int initialLocation, int initialCredit)
    : id(agentId), currentLocation(initialLocation), targetLocation(0), locationMap("----------------------------------------------------------------------------------------------------\n"), credit(initialCredit) {}

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

char* Agent::getLocationMap() const {
	return locationMap;
}

int Agent::getCredit() const {
    return credit;
}

// Setter functions
void Agent::setCurrentLocation(int location) {
    currentLocation = location;
}

void Agent::setTargetLocation(int target) {
    targetLocation = target;
}

void Agent::setLocationMap(char* newMap) {
    locatichonMap = newMap;
}

void Agent::setCredit(int newCredit) {
    credit = newCredit;
}

// Display information
void Agent::displayInfo() const {
    std::cout << "Agent ID: " << id << "\nCurrent Location: " << currentLocation
        << "\nTarget Location: " << targetLocation << "\nTotal Social Credit: " << credit << "\n";
}
