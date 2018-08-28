#include <stdexcept>

#include "Character.hpp"

Character::Character(CharType _type) : type(_type) //this is where the specs will be loaded from the LookupTables file...
{
	stats.reserve(Stat::StatCount);
		stats.push_back(Stat(Stat::Attack, 10));
		stats.push_back(Stat(Stat::Defense, 10));
		stats.push_back(Stat(Stat::Power, 10));

	ab.reserve(2);
	
	this->bonus = new short[Stat::StatCount]; //yep. I've added a new, unused bonus to this
		for (int i = 0; i < Stat::StatCount; i++) bonus[i] = 0;
}

Character::Character(std::string _name, int _maxHealth, int _atk, int _def, int _pow, int _wis, CharType _character) :
					 type(_character), 
					 name(_name), 
					 hp(_maxHealth, _maxHealth) //think Abilities later, rework Stat assignment
{
	if (this->type == Character::Player) { 
		
		stats.reserve(Stat::StatCount); //std::vector.reserve only allocates memory. It doesn't create the slots
			stats.push_back(Stat(Stat::Attack, _atk));
			stats.push_back(Stat(Stat::Defense, _def));
			stats.push_back(Stat(Stat::Power, _pow));
			stats.push_back(Stat(Stat::Wisdom, _wis));

		this->bonus = new short[Stat::StatCount];
			for (int i = 0; i < Stat::StatCount; i++) bonus[i] = 0;

		ab.reserve(4);
	
	} else throw std::logic_error("Attempt to construct invalid character!!!");
}

Character::compl Character() {

	this->name = "";
	this->hp.setMaxHealth(0);
	this->stats.clear();
	delete this->bonus;
	this->ab.clear();
}

std::string Character::getName() { return this->name; }

std::string Character::getType() {
	
	switch (this->type) {
		case(CharType::Cook):		return "Cook";
		case(CharType::Chef):		return "Chef";
		case(CharType::MasterChef): return "MasterChef";
		case(CharType::Player):		return "Player";

		default: return "Unknown Type Character";
	}
}

Health  Character::getHealth() const { return this->hp; }

Ability	Character::getAbility(const int slot) const {  //didn't think of overriding cause technically, it's the same for everyone

	//Vectors overload operator[] so that indices may be used.
		//The alternative is vectorObject.at(slot), but it returns a reference, not the value
	if (slot >= (unsigned long)0 && slot < this->ab.size()) return ab[slot];
	else throw std::out_of_range("Not an ablity!");
}

uShort	Character::getStatSize() const { return (uShort)this->stats.size(); }

Stat	Character::getStat(const uShort slot) const {  //didn't think of overriding cause technically, it's the same for everyone

													   //Vectors overload operator[] so that indices may be used.
													   //The alternative is vectorObject.at(slot), but it returns a reference, not the value
	if (slot >= Stat::Attack && slot < this->stats.size()) return this->stats[slot];
	else throw std::out_of_range("Not a stat!");
}

Stat	Character::getStat(const Stat::Type _type) const {  //didn't think of overriding cause technically, it's the same for everyone

													//Vectors overload operator[] so that indices may be used.
													//The alternative is vectorObject.at(slot), but it returns a reference, not the value
	if (_type >= Stat::Attack && _type < this->stats.size()) return this->stats[_type];
	else throw std::out_of_range("Not a stat!");
}

//protected functions

short	Character::getBonus(const Stat::Type _type) const {

	if (_type >= Stat::Attack && _type < this->stats.size()) return this->bonus[_type];
	else throw std::out_of_range("Not a valid bonus slot");
}

short* Character::getBonuses() const { //feels a bit unsafe, as far as array boundaries go...

	short* temp = new short[Stat::StatCount];

	for (int i = 0; i < Stat::StatCount; i++)temp[i] = this->bonus[i];

	return temp;
}

void	Character::setBonuses(const Ability selectedAbility) { this->bonus = selectedAbility.getTurnBonuses(); }

uShort	Character::getAbilities() const { return (short)this->ab.size(); }

bool	Character::setStat(const Stat::Type type, const uShort value) {
	
	if (type >= Stat::Attack && type < this->stats.size()) {
		stats[type].setStat(value);
		return true;
	
	} else throw std::logic_error("Not a valid bonus slot!!!");
}

bool	Character::setBonus(const Stat::Type type, const short value) {
	
	if (type >= Stat::Attack && type < this->stats.size()) {
		this->bonus[type] = value;
		return true;

	} else throw std::logic_error("Not a valid bonus slot!!!");
}