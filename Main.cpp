#include <iostream>
#include <string>
#include <cstdlib> //for rand functions
#include <ctime> //for time seed

#include "Abilities.hpp"
#include "Player.hpp"
#include "MasterChef.hpp"
#include "AccessoryFunctions.h"
#include "Game.hpp"

int main(void) { 

	Player player = init::createPlayer();

	std::cout << player.getName() << ", " << player.getAttack() << std::endl;

	srand(time(NULL));

	return 0;
}