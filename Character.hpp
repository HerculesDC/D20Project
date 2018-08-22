#pragma once
#include <string>
#include <vector>

#include "Definitions.h"
#include "Abilities.hpp"

class Character {

	public:
		//constructor and destructor:
								Character(std::string name, uShort attack, uShort defense, uShort power, uShort HP);
								compl Character();

		//getters and setters:
			//setters:
		void					setName(std::string name);
		virtual void			setAttack(uShort attack);
		virtual void			setDefense(uShort defense);
		virtual void			setPower(uShort power);
		virtual void			setHealth(uShort HP);
		virtual void			setMaxHealth(uShort maxHP);
		void					setBonus(short bonus, uShort slot); //for individual bonus setup
		void					setBonuses(short attack, short defense, short power, short hp); // Thinking of overloading this
		void					resetBonus(uShort slot);
		void					resetBonuses();
			//getters:
		std::string				getName();
		uShort					getAttack();
		uShort					getDefense();
		uShort					getPower();
		uShort					getHealth();
		uShort					getMaxHealth();
		short*					getBonuses();
		short					getBonus(uShort slot); // for specific bonuses
		
		//interaction functions (pure virtual, for an abstract class)
		virtual void			rollAttack(Character* target) = 0;
		virtual void			takeDamage(uShort damage) = 0;
		virtual void			heal(uShort amount) = 0;

	protected: //Should be private! 
					//The relationship to child classes should be via getters and setters
		std::string				name;
		uShort					attack;
		uShort					defense;
		uShort					power;
		uShort					health;
		uShort					maxHealth;
		short					bonuses[4];
		std::vector<Abilities>	abilities;
};