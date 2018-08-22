#include "DataTables.hpp"
#include "Player.hpp"
#include "MasterChef.hpp"
#include "Abilities.hpp"
#include "AccessoryFunctions.h"

std::vector<AbilityData> initializeAbilityTables() {
	std::vector<AbilityData> data(Abilities::TypeCount);

	data[Abilities::Cut].abName = "Cut";
	data[Abilities::Cut].abDescription = "Cuts the opponent";
	data[Abilities::Cut].abDamage = 0;
	data[Abilities::Cut].abCooldown = 0;
	data[Abilities::Cut].abTimer = 0;
	data[Abilities::Cut].abRoundEffect[0] = 0;
	data[Abilities::Cut].abRoundEffect[1] = 0;
	data[Abilities::Cut].abRoundEffect[2] = 0;
	data[Abilities::Cut].abRoundEffect[3] = 0;
	data[Abilities::Cut].abPostEffect[0] = 0;
	data[Abilities::Cut].abPostEffect[1] = 0;
	data[Abilities::Cut].abPostEffect[2] = 0;
	data[Abilities::Cut].abPostEffect[3] = 0;
	
	return data;
}
