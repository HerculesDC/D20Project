#include "Ability.hpp"

namespace { std::vector<AbilityData> Table = initializeAbilityData(); }

Ability::Ability(Type _t): type(_t), 
						   name(Table[type].name), 
						   description(Table[type].description),
						   action(Table[type].action),
						   baseDamage(Table[type].baseDamage),
						   cooldown(Table[type].cooldown),
						   cooldownTimer(0),
						   onCooldown(false),
						   turnBonuses(), nextBonuses()
{
	for (int i = 0; i < Stat::StatCount; i++) {
		this->turnBonuses[i] = Table[type].turnBonuses[i];
		this->nextBonuses[i] = Table[type].nextBonuses[i];
	}
}

Ability::compl Ability() {

	this->type = Ability::Standard;
	this->name = "";
	this->description = "";
	this->action = "";
	this->baseDamage = 0;
	this->cooldown = 0;
	this->cooldownTimer = 0;
	this->onCooldown = false;

	for (int i = 0; i < Stat::StatCount; i++) {
		this->turnBonuses[i] = 0;
		this->nextBonuses[i] = 0;
	}
}

std::string		Ability::getName()			const { return this->name; }
std::string		Ability::getDescription()	const { return this->description; }
std::string		Ability::getAction()		const { return this->action; }
Ability::Type	Ability::getType()			const { return this->type; }

short			Ability::getBaseDamage()	const { return this->baseDamage; }

short*			Ability::getTurnBonuses()	const {
	
	short* temp = new short[Stat::StatCount];

	for (int i = 0; i < Stat::StatCount; i++) temp[i] = this->turnBonuses[i];

	return temp;
}

short*			Ability::getNextBonuses() const {

	short* temp = new short[Stat::StatCount];

	for (int i = 0; i < Stat::StatCount; i++) temp[i] = this->nextBonuses[i];

	return temp;
}

//A bit clumsy right now. The idea is to have abilities that increase/decrease the cooldown of others
void			Ability::setCooldown(uShort _cooldown) { 
									
	if (_cooldown <= this->cooldown) this->cooldownTimer = _cooldown;
}

void			Ability::resetCooldown() { this->cooldownTimer = this->cooldown; }

//These next two functions may need to be removed later...
void			Ability::setTurnBonuses(short* bonusArray, const uShort bonusArraySize) const {
	
	uShort temp;
	if (bonusArraySize >= Stat::StatCount) temp = Stat::StatCount;
	else temp = bonusArraySize;

	for (int i = 0; i < temp; i++) bonusArray[i] = this->turnBonuses[i];
}

void			Ability::setNextBonuses(short* bonusArray, const uShort bonusArraySize) const {
	
	uShort temp;
	if (bonusArraySize >= Stat::StatCount) temp = Stat::StatCount;
	else temp = bonusArraySize;
	
	for (int i = 0; i < temp; i++) bonusArray[i] = this->nextBonuses[i];
}

uShort			Ability::getCooldown()	const { return this->cooldown; }
uShort			Ability::getTimer()		const { return this->cooldownTimer; }
bool			Ability::isOnCooldown() const { return this->onCooldown; }

//Private function that controls cooldown. 
	//While the original idea was to return void, returning a bool seems to make more sense (to assign onCooldown)
	//The idea is to recognise that there are other design choices available
bool			Ability::advanceCooldown() {

	if (this->cooldown > 0) this->cooldown -= 1;
	return this->cooldown > 0;
}

//this function will probably be discarded later...
void			Ability::print() {

	std::cout << this->name << ", " << this->description << ", " << this->action << std::endl;
	std::cout << "data: " << this->baseDamage << ", " << this->cooldown << ", " << this->cooldownTimer << ", " << std::boolalpha << this->onCooldown << std::endl;
	std::cout << "bonuses: ";
	for (int i = 0; i < Stat::StatCount; i++) std::cout << this->turnBonuses[i] << ", ";
	std::cout << std::endl;
	for (int i = 0; i < Stat::StatCount; i++) std::cout << this->nextBonuses[i] << ", ";
	std::cout << std::endl;
}