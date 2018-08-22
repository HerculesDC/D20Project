#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "DataTables.hpp"
#include "Abilities.hpp"
#include "Player.hpp"
#include "MasterChef.hpp"

namespace init {
	std::vector<Abilities> initializeAbilityTables();
	Player createPlayer();
}

std::vector<Abilities> init::initializeAbilityTables(){
	std::vector<Abilities> data(Abilities::TypeCount);

	return data;
}

Player init::createPlayer() {

	std::string name;

	std::cout << "Welcome to the player character creation!\n" <<
				 "Please, input your character's name: ";
	std::cin >> name;
	Player player(name);

	return player;
}