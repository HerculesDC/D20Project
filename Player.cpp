#include "Player.hpp"

Player::Player(std::string _name, int _maxHealth, int _atk, int _def, int _pow, int _wis) : Character(_name, _maxHealth, _atk, _def, _pow, _wis) {
	//this is where the abilities will probably go
}

Player::~Player() { }

bool	Player::takeDamage(short damage) {

	this->hp -= (damage - (this->getStat(Stat::Defense).getBonus() + this->getBonus(Stat::Defense)));

	return this->hp.assessLife();
}

short	Player::useAbility(const Ability selectedAbility, Character* target) {

	//Still has logic flaws. Check!!!
	if (!selectedAbility.isOnCooldown()) {

		short* tempBonus = selectedAbility.getTurnBonuses();
			for (int i = 0; i < Stat::StatCount; i++) this->bonus[i] += tempBonus[i];

		short damage = this->getStat(Stat::Attack).getBonus() + this->getBonus(Stat::Attack) + selectedAbility.getBaseDamage();

		tempBonus = selectedAbility.getNextBonuses(); //even if the bonuses are 0, it sets them correctly
			for (int i = 0; i < Stat::StatCount; i++) this->bonus[i] = tempBonus[i];
				
		return damage;
	} 
	else return 0;
}

short	Player::useAbility(const uShort slot, Character* target) { 

	uShort tempSlot = slot - 1; //to avoid off-by-one assignments

	if (tempSlot >=0 && tempSlot < this->ab.size() && !this->ab[tempSlot].isOnCooldown()) {

		short* tempBonus = this->ab[tempSlot].getTurnBonuses();
			for (int i = 0; i < Stat::StatCount; i++) this->bonus[i] += tempBonus[i];

		short damage = this->getStat(Stat::Attack).getBonus() + this->getBonus(Stat::Attack) + this->ab[tempSlot].getBaseDamage();

		std::cout << damage << std::endl;

		tempBonus = this->ab[tempSlot].getNextBonuses();
			for (int i = 0; i < Stat::StatCount; i++) this->bonus[i] = tempBonus[i];

		target->takeDamage(damage);
		
		return damage;
	}
	else return 0;
}


bool	Player::addAbility(const Ability selectedAbility) { 

	if (this->ab.size() < this->ab.capacity()) {

		this->ab.push_back(selectedAbility);
		return true;
	}
	else return false; // returns a boolean that can be used as a criterion for displaying messages in Print (wherever that'll be)
}

uShort	Player::getAbilityCooldown(const Ability selectedAbility) { return selectedAbility.getTimer(); } //actually returns the state of the cooldown.

uShort	Player::getAbilityCooldown(const uShort slot) {

	uShort tempSlot = slot - 1; //to avoid off-by-one assignments

	if (tempSlot >= 0 && tempSlot < this->ab.size()) {
		return this->ab[tempSlot].getTimer();
	}
	else throw std::logic_error("Not a valid ability slot");
}

void	Player::print() {
	std::cout << "Player's name: " << this->getName() << std::endl;
	
	//think of a for loop for the part below later
	std::cout << this->getName() << "'s max HP: " << this->getHealth().getMaxHealth() << std::endl;
	std::cout << this->getName() << "'s current HP: " << this->getHealth().getHealth() << std::endl;

	for (int i = 0; i < Stat::StatCount; i++) {
		std::cout << this->getName() << "'s " << this->getStat(i).getName() << ": " 
				  << this->getStat(i).getStat() << ", stat bonus: " << this->getStat(i).getBonus() << std::endl;
	}
	
	for (auto ability : this->ab) ability.print();
}