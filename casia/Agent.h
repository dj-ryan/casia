#pragma once
#ifndef AGENT_H
#define AGENT_H


#define MAP_SIZE 101


class Agent {
private:
    int id;               // unique identifier
    int currentLocation;  // current location
    int targetLocation;   // location the agent wants to go
    char locationMap[MAP_SIZE];			  // map of the world
    int credit;           // total social credit

public:
    // Constructor
    Agent();
    Agent(int agentId, int initialLocation, int initialCredit);

    // Getter functions
    int getId() const;
    int getCurrentLocation() const;
    int getTargetLocation() const;
    const char* getLocationMap() const;
    int getCredit() const;

    // Setter functions
    void setCurrentLocation(int location);
    void setTargetLocation(int target);
    //void setLocationMap(char* map);
    void setCredit(int newCredit);

    // Display information
    void displayInfo() const;
};

#endif // AGENT_H


