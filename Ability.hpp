#pragma once

#include <string>
#include <iostream>

#include "Stat.hpp" //included here to keep track of stat bonuses length

#include "LookupTables.hpp"

#include "Helpers.inl"

class Ability {

	public:
		enum		Type {Standard, Heal, AbCount};

					Ability(Type type);
					compl Ability();

		std::string getName() const;
		std::string getDescription() const;
		std::string getAction() const;

		short		getBaseDamage() const;

		uShort		getCooldown() const;
		uShort		getTimer() const;
		bool		isOnCooldown() const;


		short*		getTurnBonuses() const;
		short*		getNextBonuses() const;

		//the functions below follow an OpenGL approach, but I realized they're not good when you apply OOP principles
			//also, not sure "const" applies here
		void		setTurnBonuses(short* targetArray, const uShort bonusArraySize) const;
		void		setNextBonuses(short* targetArray, const uShort bonusArraySize) const;

		//void		use();

		void		print();

	private:
		bool		advanceCooldown();

	private:

		Type		type;

		std::string name;
		std::string description;
		std::string action;
		
		short		baseDamage; //Healing abilities have negative damage, hence short instead of uShort
		
		uShort		cooldown; //fixed
		uShort		cooldownTimer; //decreases
		bool		onCooldown;

		//decided to not use a constant for the array size, rather, link it to the (max) amount of stats a character would have.
		short		turnBonuses[Stat::StatCount];
		short		nextBonuses[Stat::StatCount];
};