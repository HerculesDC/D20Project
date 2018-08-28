#include "LookupTables.hpp"

//Minion struct definitions placed in "Helpers.inl" for now. May move them to the specific files later

std::vector<AbilityData> initializeAbilityData() {

	std::vector<AbilityData> data(Ability::AbCount);

		data[Ability::Standard].name = "Cut";
		data[Ability::Standard].description = "Cuts opponents";
		data[Ability::Standard].action = "cut";
		data[Ability::Standard].baseDamage = 10;
		data[Ability::Standard].cooldown = 0;
		data[Ability::Standard].turnBonuses[0] = 3;
		data[Ability::Standard].turnBonuses[1] = 1;
		data[Ability::Standard].turnBonuses[2] = 2;
		data[Ability::Standard].turnBonuses[3] = 0;
		data[Ability::Standard].nextBonuses[0] = 4;
		data[Ability::Standard].nextBonuses[1] = 8;
		data[Ability::Standard].nextBonuses[2] = 5;
		data[Ability::Standard].nextBonuses[3] = 7;
	
		data[Ability::Heal].name = "Heal";
		data[Ability::Heal].description = "Heals Target";
		data[Ability::Heal].action = "healing";
		data[Ability::Heal].baseDamage = -10;
		data[Ability::Heal].cooldown = 0;
		data[Ability::Heal].turnBonuses[0] = 0;
		data[Ability::Heal].turnBonuses[1] = 0;
		data[Ability::Heal].turnBonuses[2] = 0;
		data[Ability::Heal].turnBonuses[3] = 0;
		data[Ability::Heal].nextBonuses[0] = 0;
		data[Ability::Heal].nextBonuses[1] = 0;
		data[Ability::Heal].nextBonuses[2] = 0;
		data[Ability::Heal].nextBonuses[3] = 0;

	return data;
}

std::vector<CookData> initializeCookData() {
	
	std::vector<CookData> cookData(SimpleMinion::MinionCount);

		cookData[SimpleMinion::Cook_1].name = "Simple Cook 1";
		cookData[SimpleMinion::Cook_1].atk  =  10;
		cookData[SimpleMinion::Cook_1].def  =  10;
		cookData[SimpleMinion::Cook_1].pow  =  10;
		cookData[SimpleMinion::Cook_1].hp   = 100;

		cookData[SimpleMinion::Cook_2].name = "Simple Cook 2";
		cookData[SimpleMinion::Cook_2].atk = 10;
		cookData[SimpleMinion::Cook_2].def = 10;
		cookData[SimpleMinion::Cook_2].pow = 10;
		cookData[SimpleMinion::Cook_2].hp = 100;

	return cookData;
}

ChefData initializeChefData() { //felt cumbersome having a single-element vector...

	ChefData chefData;
		chefData.name = "Chef";
		chefData.atk  =  10;
		chefData.def  =  10;
		chefData.pow  =  10;
		chefData.wis  =  10;
		chefData.hp   = 100;

	return chefData;
}

MasterChefData initializeMasterChefData() { //see ChefData for details

	MasterChefData masterChefData;
		masterChefData.name = "MasterChef";
		masterChefData.atk  =  12;
		masterChefData.def  =  12;
		masterChefData.pow  =  12;
		masterChefData.wis  =  12;
		masterChefData.hp   = 120;

	return masterChefData;
}