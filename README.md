# C.A.S.I.A.
**C**oordination **A**mong **S**elf-**I**nterested **A**gents

## Abstract
In the realm of multi-agent systems comprised of self-interested agents, the fundamental question revolves around understanding the intricacies of movement coordination. Each agent, functioning as an autonomous entity, is inherently driven by individual goals and preferences. This individualistic motivation introduces a layer of complexity, giving rise to a dynamic environment where collaboration and conflict coexist.

To unravel the mechanisms governing movement coordination, this simulation employs a decentralized approach. The emphasis is placed on investigating how information exchange, consensus algorithms, and adaptive strategies contribute to the overall coordination of agents in their pursuit of individual objectives. The decentralized coordination mechanism serves as a foundational framework for exploring the challenges that arise in such environments.


# Simulation
## v1.0 - [Hallow Knight](https://github.com/dj-ryan/casia/tree/hollow-knight-v1.0)
- 1D environment
    - agents move left or right
- Social credit system
    - The more social credit the more say that you have in justifications 



## v2.0 - Plastic Chip
- **Dispenser** - A device that, at a regular intervals, dispenses plastic chips. Dispensers can have different intervals.
- **Chip** - A token with fixed value.
- **Home** - The location that the agent has to bring the chip to receive it's value
- **Social Credit** - The credit that the agent has that allows it to access faster or more valuable dispensers
- **Skill** - A multiplier to the chips that the agent gathers

All agent have a home, a social credit and a skill multiplier.
All dispensers have a distance from the agents home, a dispense rate and a social credit minimum.
All chips are the same value
Dispensers dispense chips of a fixed value and at a fixed rate. They also have a social credit minimum that agents must have so that they can access them. The chips that are dispensed accumulate. The more valuable dispensers are a further distance from the agents homes. 
The agents can go to a dispenser and collect all of the the chips that have accumulated there if they meet the social credit minimum. It can also choose to wait at the dispenser and not take the chips. Every chip that the dispenser makes where the agent does not take them will increase it's social credit. However when the agent decides to take the chips it loses social credit in proportion to how many chips it has taken. The skill multiplier means that some agents can extract more value from the chip. The agent must bring the chips home which costs a time penalty. The farther the dispensary the more the time cost.

## v3.0 - [Run Around](https://github.com/dj-ryan/casia/tree/run-around-v3.0)

Robots can move around a 3d environment and are trying to get closer to a target. They know where the target is and where they are. They also can sense the presence of another robot. Which ever robot has the greater social credit is still allowed to move and the robot with the lower social credit must stop moving. Once the transaction has been completed then the robots exchange the proper amount of social credit. 

# Definitions
- **Agent**: An autonomous entity that is capable of making decisions and taking actions.
- **Environment**: The space in which agents operate.
- **Objective**: The goal that an agent is trying to achieve
- **Consensus**: The process of reaching an agreement or common ground among a group of agents.
- **Coordination**: The process of organizing and integrating the actions of agents to achieve a common goal.
- **Decentralized**: A system in which decision-making is distributed among agents, rather than being controlled by a single entity.
- **Self-Interested**: Acting in one's own interest, often without regard for the interests of others.
