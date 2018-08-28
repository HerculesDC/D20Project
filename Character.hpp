#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Stat.hpp"
#include "HealthHandler.hpp"
#include "Ability.hpp"

#include "helpers.inl"

class Ability;

class Character {
	
	public:

		enum					CharType { Cook, Chef, MasterChef, Player, CharCount }; //may require redesign, but the idea is to have the Player Character be a unique one
								
								Character(CharType character); //the idea is that if the character is not the player, the attributes are self-built
								Character(std::string name, int maxHP, int attack, int defense, int power, int wisdom = 0, CharType character = CharType::Player);
								compl Character();

		std::string				getName();
		std::string				getType();

		Health					getHealth() const; // may need some plumbing as well
		Ability					getAbility(const int slot) const; // may need to be redesigned to account for "finding" an ability within the vector. 
														//Research the vector class for better understanding
		uShort					getStatSize() const;
		Stat					getStat(const uShort slot) const;
		Stat					getStat(const Stat::Type stat) const;

		//Virtual Functions:
		virtual bool			takeDamage(short damage) = 0; // will return whatever "hp.assessLife()" returns
		
		//REVISE!!! These next two functions may not require such argument list
		virtual short			useAbility(const Ability selectedAbility, Character* target) = 0;
		virtual short			useAbility(const uShort slot, Character* target) = 0;

	protected: //methods

		virtual bool			addAbility(const Ability selectedAbility) = 0; //not sure how yet

		virtual uShort			getAbilityCooldown(const Ability selectedAbility) = 0;
		virtual uShort			getAbilityCooldown(const uShort slot) = 0;

		short					getBonus(const Stat::Type type) const;
		short*					getBonuses() const;

		//thinking of expanding upon this...
		uShort					getAbilities() const; //not sure why I included this, though...

		bool					setStat(const Stat::Type type, const uShort value); // think of overloading later
		
		bool					setBonus(const Stat::Type type, const short value); // seems this is the right place to put this for now
		void					setBonuses(const Ability selectedAbility);

		virtual void			print() = 0;

		
	protected: //HP, abilities and bonuses. Placed them here to avoid plumbing

		Health					hp;
		std::vector<Ability>	ab;
		short*					bonus; //these will be set to zero, but the array's Size will always match the stat size!

	private:
		
		CharType				type;
		std::string				name;
		std::vector<Stat>		stats;
};