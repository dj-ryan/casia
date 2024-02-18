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
		int randomStart = generateRandom(0, 99);    // Random starting location between 0 and 99
		int randomTarget = generateRandom(0, 99);   // Random target location between 0 and 99
		//int randomCredit = generateRandom(50, 200);  // Random initial credit between 50 and 200

		agents[i] = Agent(i + 1, randomStart, 0); // social credit is set to 0
		agents[i].setTargetLocation(randomTarget);
		//agents[i].setCurrentLocation(randomStart);
	}
}

void simulateIteration(Agent agents[], int numAgents) {

	//Make a vector of vecotrs to store the agents that are at each location
	std::vector<std::vector<Agent>> agentsAtLocation;

	// fill the vector with the agents but put the agents in the same location in the same vector
	for (int i = 0; i < MAP_SIZE; i++) {
		std::vector<Agent> temp;
		for (int j = 0; j < numAgents; j++) {
			if (agents[j].getCurrentLocation() == i) {
				temp.push_back(agents[j]);
			}
		}
		agentsAtLocation.push_back(temp);
	}

	//print agentsAtLocation
	for (int i = 0; i < agentsAtLocation.size(); i++) {
		std::cout << "[" << i << "] : ";
		for (int j = 0; j < agentsAtLocation[i].size(); j++) {
			std::cout << "(" << agentsAtLocation[i][j].getId() << "|" << agentsAtLocation[i][j].getCredit() << "->" << agentsAtLocation[i][j].getTargetLocation() << ") ";
		}
		std::cout << std::endl;
	}

	// loop through the agentsAtlocation and if there is more than one agent at a location then they interact
	for (int i = 0; i < agentsAtLocation.size(); i++) {
		if (agentsAtLocation[i].size() > 1) {
			// compare all of the agents in the location and which ever has the highest social credit moves closer to its target
			int maxCredit = 0;
			int maxCreditIndex = 0;
			for (int j = 0; j < agentsAtLocation[i].size(); j++) {
				if (agentsAtLocation[i][j].getCredit() > maxCredit) {
					maxCredit = agentsAtLocation[i][j].getCredit();
					maxCreditIndex = j;
				}
			}
			// move the agent with the highest social credit closer to its target
			if (agentsAtLocation[i][maxCreditIndex].getCurrentLocation() < agentsAtLocation[i][maxCreditIndex].getTargetLocation()) {
				agentsAtLocation[i][maxCreditIndex].setCurrentLocation(agentsAtLocation[i][maxCreditIndex].getCurrentLocation() + 1);
			}
			else if (agentsAtLocation[i][maxCreditIndex].getCurrentLocation() > agentsAtLocation[i][maxCreditIndex].getTargetLocation()) {
				agentsAtLocation[i][maxCreditIndex].setCurrentLocation(agentsAtLocation[i][maxCreditIndex].getCurrentLocation() - 1);
			}
		}
		else if (agentsAtLocation[i].size() == 1) {
			// move the agent one step closer to the target
			if (agentsAtLocation[i][0].getCurrentLocation() < agentsAtLocation[i][0].getTargetLocation()) {
				
				agentsAtLocation[i][0].setCurrentLocation(agentsAtLocation[i][0].getCurrentLocation() + 1);
				std::cout << "Moved " << agentsAtLocation[i][0].getId() << " to " << agentsAtLocation[i][0].getCurrentLocation() + 1 << std::endl;
			}
			else if (agentsAtLocation[i][0].getCurrentLocation() > agentsAtLocation[i][0].getTargetLocation()) {
				agentsAtLocation[i][0].setCurrentLocation(agentsAtLocation[i][0].getCurrentLocation() - 1);
				std::cout << "Moved " << agentsAtLocation[i][0].getId() << " to " << agentsAtLocation[i][0].getCurrentLocation() - 1 << std::endl;
			}

		}
		else {
			// do nothing
		}
	}



}




int main() {
	// Your code goes here

	std::cout << "CASIA simulation begining..." << std::endl;

	const int numAgents = 10;
	int itterationCounter = 0;
	//bool allAgentsAtTarget = false;
	Agent agents[numAgents];

	// Initialize agents
	initAgents(agents, numAgents);

	// Display information for each agent
	for (int i = 0; i < numAgents; ++i) {
		agents[i].displayInfo();
		std::cout << "==============================\n";
	}

	bool allReachedTarget = false;

	// Main loop
	while (!allReachedTarget) {
		// Check if all agents reached their target locations
		allReachedTarget = true;
		for (int i = 0; i < numAgents; i++) {
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
			std::cout << "Not all agents reached their target locations. Simulation continues. Itteration: " << itterationCounter << "\n";
			simulateIteration(agents, numAgents);
		}

		// Display information for each agent after the iteration
		//for (int i = 0; i < numAgents; ++i) {
		//    agents[i].displayInfo();
		//    std::cout << "==============================\n";
		//}

		// wait for a enter key press to continue
		std::cin.get();
		std::cout << "==============================\n";
	}


	return 0;
}
