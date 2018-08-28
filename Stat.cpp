#include "Stat.hpp"

const std::string Stat::name[Stat::StatCount] = { "Attack", "Defense", "Power", "Wisdom" };

Stat::Stat(Type _type, uShort _value) : type(_type), value(_value) { calculateBonus(); }

Stat::Stat(const Stat& other) {

	this->type = other.type;
	this->value = other.value;
	calculateBonus();
}

Stat::compl Stat() {

	this->type = Attack;
	this->value = 0;
	this->bonus = 0;
}

Stat::Type	Stat::getType() const { return this->type; }

std::string	Stat::getName() const { return this->name[this->type]; }

uShort		Stat::getStat() const { return this->value; }

uShort		Stat::getBonus() const { return this->bonus; }

//uncomfortable with a setter for this...
void		Stat::setStat(uShort _value) {

	this->value = _value;
	calculateBonus();
}

void		Stat::calculateBonus() { bonus = (this->value-8) / 2; }