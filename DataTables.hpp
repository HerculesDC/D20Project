#pragma once
#include <string>
#include <vector>

#include "AccessoryFunctions.h"
#include "Abilities.hpp"
#include "Player.hpp"
#include "MasterChef.hpp"

struct AbilityData {
	std::string abName;
	std::string abDescription;
	short		abDamage;
	uShort		abCooldown;
	uShort		abTimer;
	short		abRoundEffect[4];
	short		abPostEffect[4];
};

std::vector<AbilityData> initializeAbilityTables();