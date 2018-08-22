#include <iostream>
#include "Character.hpp"

Character::Character(std::string _name = "Default", uShort _atk = 8, uShort _def = 8, uShort _pwr = 8, uShort _hp = 50) :
					name(_name),
					attack(_atk),
					defense(_def),
					power(_pwr),
					health(_hp),
					maxHealth(_hp)
{
	//vector initialization
	abilities.reserve(2);

	//bonus initialization: original
	//for (uShort i = 0; i < 4; i++) bonuses[i] = 0;

	//bonus initialization: current
	resetBonuses();
}

Character::compl Character() {}

//getters and setters:
	//setters:
void Character::setName(std::string _name) { name = _name; }
void Character::setAttack(uShort _atk) { attack = _atk; }
void Character::setDefense(uShort _def) { defense = _def; }
void Character::setPower(uShort _pwr) { power = _pwr; }
void Character::setHealth(uShort _hp) { health = _hp; }
void Character::setMaxHealth(uShort _maxHP) { maxHealth = _maxHP; }

void Character::setBonus(short _bonus, uShort _slot) {
	
	if (_slot > 0 && _slot < 5)	bonuses[_slot-1] = _bonus;
	else std::cout << "Invalid slot! Bonus not added..." << std::endl;
}

void Character::setBonuses(short _atkBonus, short _defBonus, short _pwrBonus, short _hpBonus){
	
	bonuses[0] = _atkBonus;
	bonuses[1] = _defBonus;
	bonuses[2] = _pwrBonus;
	bonuses[3] = _hpBonus;
}

void Character::resetBonus(uShort _slot) { setBonus(0, _slot); }
void Character::resetBonuses() { setBonuses(0, 0, 0, 0); }

	//getters:
std::string	Character::getName() { return this->name; }
uShort		Character::getAttack() { return this->attack; }
uShort		Character::getDefense() { return this->defense; }
uShort		Character::getPower(){ return this->power; }
uShort		Character::getHealth(){ return this->health; }
uShort		Character::getMaxHealth(){ return this->maxHealth; }
short*		Character::getBonuses(){ return this->bonuses; }

short		Character::getBonus(uShort _slot){
	if (_slot > 0 && _slot < 5) return this->bonuses[_slot-1];
	else return 0; //I wanted to include a message, but since it returns an uShort...
}

//intteraction functions ( pure virtual)
/*
void Character::rollAttack(Character* target)
void Character::takeDamage(uShort damage)
void Character::heal(uShort amount)
*/