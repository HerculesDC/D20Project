#include "Player.hpp"

Player::Player(std::string _name, uShort _atk, uShort _def, 
	uShort _pwr, uShort _HP, uShort _wis) : Character(_name, _atk, _def, _pwr, _HP),
	wisdom(_wis)
{
	calculateInherentBonuses();
}

Player::compl Player(){}

void Player::setWisdom(uShort _wis) {
	this->wisdom = _wis;
	calculateInherentBonus(wisdom, 4); // 4 is the wisdom index bonus modifier
}

//functions overriden from Parent:
void Player::setAttack(uShort _atk) {
	this->attack = _atk;
	calculateInherentBonus(attack, 0); // 0 is the attack index bonus modifier
}

void Player::setDefense(uShort _def) {
	this->defense = _def;
	calculateInherentBonus(defense, 1); // 1 is the defense index bonus modifier
}

void Player::setPower(uShort _pwr) {
	this->power = _pwr;
	calculateInherentBonus(power, 2); // 2 is the power index bonus modifier
}

void Player::setHealth(uShort _hp) { this->health = _hp; } // no bonus to calculate in this case

void Player::setMaxHealth(uShort _maxHP) { this->maxHealth = _maxHP; }

//Player-exclusive attribute
uShort Player::getWisdom() { return this->wisdom; }

uShort* Player::getInherentBonuses() { return inherentBonus; }

uShort Player::getInherentBonus(uShort _index) {

	if (_index > 0 && _index < 6) return inherentBonus[_index - 1];
}

void Player::heal(uShort _healAmt) {
	
	this->health += _healAmt;
	if (this->health > this->maxHealth) this->health = this->maxHealth;
}

void Player::takeDamage(uShort _damage) {

	this->health -= (_damage - this->defense);
	if (this->health <= 0) /*kill player, game over...*/;
}

void Player::rollAttack(Character* _target) {

	_target->takeDamage(this->attack + this->bonuses[0]);
}

//IMPLEMENT!!!
void Player::calculateInherentBonuses() {}

void Player::calculateInherentBonus(uShort _attrib, uShort _index) {}