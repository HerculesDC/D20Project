#include "AccessoryFunctions.h"
#include "Abilities.hpp"

//namespace { const std::vector<Abilities> Table = init::initializeAbilitiyTable(); }

Abilities::Abilities(AbilityTypes _type):aType(_type){}

Abilities::compl Abilities() {}

void Abilities::setName(std::string _name) { aName = _name; }
void Abilities::setDescription(std::string _desc) { aDescription = _desc; }
void Abilities::setDamage(short _damage) { aDamage = _damage; }
void Abilities::setCooldown(uShort _cooldown) { aCooldown = _cooldown; }
void Abilities::setOnCooldown(bool _onCooldown) { aOnCooldown = _onCooldown; }
void Abilities::setTimer(uShort _timer) { aCdTimer = _timer; }

void Abilities::setRoundEffects(short _atk, short _def, short _dam, short _health){
	
	aRoundEffect[0] = _atk;
	aRoundEffect[1] = _def;
	aRoundEffect[2] = _dam;
	aRoundEffect[3] = _health;
}

void Abilities::setRoundEffect(short _effect, uShort _index){

	if (_index > 0 && _index < 5) aRoundEffect[_index-1] = _effect;
}

void Abilities::setPostEffects(short _atk, short _def, short _dam, short _health) {

	aPostEffect[0] = _atk;
	aPostEffect[1] = _def;
	aPostEffect[2] = _dam;
	aPostEffect[3] = _health;
}

void Abilities::setPostEffect(short _effect, uShort _index) {

	if (_index > 0 && _index < 5) aPostEffect[_index - 1] = _effect;
}

//getters

std::string	Abilities::getName() { return this->aName; }
std::string	Abilities::getDescription() { return this->aDescription; }
short		Abilities::getDamage() { return this->aDamage; }
uShort		Abilities::getCooldown() { return this->aCooldown; }
bool		Abilities::isOnCooldown() { return this->aOnCooldown; }
uShort		Abilities::getTimer() { return this->aCdTimer; }
short*		Abilities::getRoundEffects(){ return aRoundEffect; }

short Abilities::getRoundEffect(uShort _index){

	if (_index > 0 && _index < 5) return aRoundEffect[_index - 1];
	else return 0; //should return error
}

short* Abilities::getPostEffects(){ return aRoundEffect; }

short Abilities::getPostEffect(uShort _index) {

	if (_index > 0 && _index < 5) return aPostEffect[_index - 1];
	else return 0; //should return error
}