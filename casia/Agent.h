#pragma once
#ifndef AGENT_H
#define AGENT_H

class Agent {
private:
    int id;               // unique identifier
    int currentLocation;  // current location
    int targetLocation;   // location the agent wants to go
    int credit;           // total social credit

public:
    // Constructor
    Agent();
    Agent(int agentId, int initialLocation, int initialCredit);

    // Getter functions
    int getId() const;
    int getCurrentLocation() const;
    int getTargetLocation() const;
    int getCredit() const;

    // Setter functions
    void setCurrentLocation(int location);
    void setTargetLocation(int target);
    void setCredit(int newCredit);

    // Display information
    void displayInfo() const;
};

#endif // AGENT_H


