#pragma once
class Agent
{
private:
    int id;               // unique identifier
    int currentLocation;  // current location
    int targetLocation;   // location the agent wants to go
    int credit;           // total social credit

public:
    // Constructor
    Agent(int agentId, int initialLocation, int initialCredit)
        : id(agentId), currentLocation(initialLocation), targetLocation(0), credit(initialCredit) {}

    // Getter functions
    int getId() const {
        return id;
    }

    int getCurrentLocation() const {
        return currentLocation;
    }

    int getTargetLocation() const {
        return targetLocation;
    }

    int getCredit() const {
        return credit;
    }

    // Setter functions
    void setCurrentLocation(int location) {
        currentLocation = location;
    }

    void setTargetLocation(int target) {
        targetLocation = target;
    }

    void setCredit(int newCredit) {
        credit = newCredit;
    }

    // Display information
    void displayInfo() const {
        std::cout << "Agent ID: " << id << "\nCurrent Location: " << currentLocation
            << "\nTarget Location: " << targetLocation << "\nTotal Social Credit: " << credit << "\n";
    }
};

