#pragma once

#include <string>

#include <vector>
#include <functional>

#include "Helpers.inl"
#include "Ability.hpp"
#include "Character.hpp"
#include "Stat.hpp"
#include "HealthHandler.hpp"

/*REMINDER: These are just values to be plugged into the proper classes' constructors.
		  * They are *NOT* class objects in themselves. 
		  * This data will be passed to the classes' constructors 
				* via the nameless namespaces which contain the initialization instructions for each class
*/

class Stat;
class Health;
class Ability;
class Character;
class Player;
class Cook;
class Chef;
class MasterChef;

struct AbilityData {

	std::string name;
	std::string description;
	std::string action;

	short baseDamage;
	uShort cooldown;

	short turnBonuses[4];
	short nextBonuses[4];
};

struct CookData {

	std::string name;

	uShort atk;
	uShort def;
	uShort pow;

	uShort hp;

	enum Abilities {Primary, Secondary, CookAbCount};
};

struct ChefData {

	std::string name;

	uShort atk;
	uShort def;
	uShort pow;
	uShort wis;

	uShort hp;

	enum Abilities { Primary, Secondary, MinorHeal, ChefAbCount };
};

struct MasterChefData {
	
	std::string name;
	
	uShort atk;
	uShort def;
	uShort pow;
	uShort wis;

	uShort hp;

	//Check specs file
	enum Abilities { Primary, Secondary, Tertiary, MinorHeal, MasterAbCount };
};

std::vector<AbilityData> initializeAbilityData();

std::vector<CookData> initializeCookData();

ChefData initializeChefData();

MasterChefData initializeMasterChefData();