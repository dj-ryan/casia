#include <iostream>
#include "Agent.h"

#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

// include std::vector
#include <vector>

// include std::sort
#include <algorithm>


int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to initialize 10 agents with random starting and target locations
void initAgents(Agent agents[], int numAgents) {
    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < numAgents; ++i) {
        int randomStart = generateRandom(1, 100);    // Random starting location between 1 and 100
        int randomTarget = generateRandom(1, 100);   // Random target location between 1 and 100
        //int randomCredit = generateRandom(50, 200);  // Random initial credit between 50 and 200

        agents[i] = Agent(i + 1, randomStart, 0); // social credit is set to 0
        agents[i].setTargetLocation(randomTarget);
    }
}

void simulateIteration(Agent agents[], int numAgents) {
    // Sort agents based on current location (ascending order)
    std::sort(agents, agents + numAgents, [](const Agent& a, const Agent& b) {
        return a.getCurrentLocation() < b.getCurrentLocation();
        });


    // loop through agents and add all agents in the same location to a vector
    for (int i = 0; i < numAgents; ++i) {
        std::vector<Agent> agentsInSameLocation;
        agentsInSameLocation.push_back(agents[i]);
        for (int j = i + 1; j < numAgents; ++j) {
            if (agents[j].getCurrentLocation() == agents[i].getCurrentLocation()) {
                agentsInSameLocation.push_back(agents[j]);
            }
            else {
                break;
            }
        }

        // 
        if (agentsInSameLocation.size() > 1) {
            // If there are multiple agents in the same location determin which has the highest social credit score
            int maxCredit = agentsInSameLocation[0].getCredit();
            int maxCreditIndex = 0;
            for (int k = 1; k < agentsInSameLocation.size(); ++k) {
                if (agentsInSameLocation[k].getCredit() > maxCredit) {
                    maxCredit = agentsInSameLocation[k].getCredit();
                    maxCreditIndex = k;
                }
            }

            // Move the agent with the highest social credit score towards its target location
            if (agentsInSameLocation[maxCreditIndex].getCurrentLocation() != agentsInSameLocation[maxCreditIndex].getTargetLocation()) {
                if (agentsInSameLocation[maxCreditIndex].getTargetLocation() > agentsInSameLocation[maxCreditIndex].getCurrentLocation()) {
                    agentsInSameLocation[maxCreditIndex].setCurrentLocation(agentsInSameLocation[maxCreditIndex].getCurrentLocation() + 1);
                }
                else {
                    agentsInSameLocation[maxCreditIndex].setCurrentLocation(agentsInSameLocation[maxCreditIndex].getCurrentLocation() - 1);
                }
            }

            // Update the social credit score of the agent that moved
            //agentsInSameLocation[maxCreditIndex].setCredit(agentsInSameLocation[maxCreditIndex].getCredit() - 1);

            // Update the social credit score of the other agents in the same location
            for (int k = 0; k < agentsInSameLocation.size(); ++k) {
                if (k != maxCreditIndex) {
                    agentsInSameLocation[k].setCredit(agentsInSameLocation[k].getCredit() + 1); // Update the social credit score of the agent that did not move
                }
                else {
                    agentsInSameLocation[k].setCredit(agentsInSameLocation[k].getCredit() - 1); // Update the social credit score of the agent that moved
                }
            }


        }
        else {
            // If there is only one agent in the location, move the agent towards its target location
            if (agents[i].getCurrentLocation() != agents[i].getTargetLocation()) {
                if (agents[i].getTargetLocation() > agents[i].getCurrentLocation()) {
                    agents[i].setCurrentLocation(agents[i].getCurrentLocation() + 1);
                }
                else {
                    agents[i].setCurrentLocation(agents[i].getCurrentLocation() - 1);
                }
            }
        }

    }


}




int main() {
    // Your code goes here

    std::cout << "Hello, World!" << std::endl;

    const int numAgents = 10;
    int itterationCounter = 0;
    //bool allAgentsAtTarget = false;
    Agent agents[numAgents];

    // Initialize agents
    initAgents(agents, numAgents);

    // Display information for each agent
    for (int i = 0; i < numAgents; ++i) {
        agents[i].displayInfo();
        std::cout << "----------------------\n";
    }


    // Main loop
    while (true) {
        // Check if all agents reached their target locations
        bool allReachedTarget = true;
        for (int i = 0; i < numAgents; ++i) {
            if (agents[i].getCurrentLocation() != agents[i].getTargetLocation()) {
                allReachedTarget = false;
                break;
            }
        }

        // End simulation if all agents reached their target locations
        if (allReachedTarget) {
            std::cout << "All agents reached their target locations. Simulation ends.\n";
            break;
        }
        else {
            itterationCounter++;
            std::cout << "Not all agents reached their target locations. Simulation continues. Itteration:\n" << itterationCounter;
        }

        // Simulate one iteration of the main loop
        if (!allReachedTarget) {
            simulateIteration(agents, numAgents);
        }

        // Display information for each agent after the iteration
        for (int i = 0; i < numAgents; ++i) {
            agents[i].displayInfo();
            std::cout << "----------------------\n";
        }
    }


    return 0;
}
