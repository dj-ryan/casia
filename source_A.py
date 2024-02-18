import random
import time

class Agent:
    def __init__(self, home, social_credit, skill):
        self.home = home
        self.social_credit = social_credit
        self.skill = skill
        self.chips = []

    def take_chips(self, dispenser):
        if self.social_credit >= dispenser.social_credit_minimum:
            self.chips.extend(dispenser.dispense_chips())
            self.social_credit -= len(self.chips) * 0.5  # Adjust the social credit based on the number of chips taken
            return True
        else:
            print("Agent does not have enough social credit to access this dispenser.")
            return False

    def bring_chips_home(self):
        time_penalty = len(self.chips) * 0.1  # Adjust the time penalty based on the number of chips
        print(f"Agent is bringing {len(self.chips)} chips home with a time penalty of {time_penalty}.")

class Dispenser:
    def __init__(self, distance, dispense_rate, social_credit_minimum):
        self.distance = distance
        self.dispense_rate = dispense_rate
        self.social_credit_minimum = social_credit_minimum
        self.accumulated_chips = []

    def dispense_chips(self):
        dispensed_chips = self.accumulated_chips[:]
        self.accumulated_chips.clear()
        return dispensed_chips

    def accumulate_chips(self):
        self.accumulated_chips.extend([Chip() for _ in range(self.dispense_rate)])

class Chip:
    value = 1  # Fixed value for all chips

def simulate_agents_and_dispensers():
    # Create agents
    agent1 = Agent(home="Home1", social_credit=10, skill=1.5)
    agent2 = Agent(home="Home2", social_credit=15, skill=1.2)

    # Create dispensers
    dispenser1 = Dispenser(distance=5, dispense_rate=2, social_credit_minimum=8)
    dispenser2 = Dispenser(distance=10, dispense_rate=3, social_credit_minimum=12)

    # Simulation steps
    # while true
    while True:
        dispenser1.accumulate_chips()
        dispenser2.accumulate_chips()

        if random.choice([True, False]):  # Randomly decide if the agent takes chips
            agent1.take_chips(dispenser1)
        if random.choice([True, False]):
            agent2.take_chips(dispenser2)

        agent1.bring_chips_home()
        agent2.bring_chips_home()

        # delay in between simulation steps
        time.sleep(1)


simulate_agents_and_dispensers()
