#pragma once
#ifndef AGENT_H
#define AGENT_H

class Agent {
private:
    uint8_t id;               // unique identifier
    uint8_t currentLocation;  // current location
    uint8_t targetLocation;   // location the agent wants to go
    char locationMap[101];			  // map of the world
    uint8_t credit;           // total social credit

public:
    // Constructor
    Agent();
    Agent(int agentId, int initialLocation, int initialCredit);

    // Getter functions
    int getId() const;
    int getCurrentLocation() const;
    int getTargetLocation() const;
    char* getLocationMap() const;
    int getCredit() const;

    // Setter functions
    void setCurrentLocation(int location);
    void setTargetLocation(int target);
    void setLocationMap(char* map);
    void setCredit(int newCredit);

    // Display information
    void displayInfo() const;
};

#endif // AGENT_H


