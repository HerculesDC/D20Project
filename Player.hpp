#pragma once

#include "Abilities.hpp"
#include "Character.hpp"

class Player final : public Character { // ensures no class inherits from Player

	public:
	//constructor & destructor 
		//(if applicable, non-default constructors need to have their values defined in this file)
					Player(std::string name, uShort attack = 8, uShort defense = 8, uShort power = 8, uShort HP = 100, uShort wisdom = 8);
					compl Player();

	//additional getters & setters
		//setters
		void		setWisdom(uShort wisdom);

		//setter overrides
		void		setAttack(uShort attack) final override;
		void		setDefense(uShort defense) final override;
		void		setPower(uShort power) final override;
		void		setHealth(uShort hp) final override;
		void		setMaxHealth(uShort maxHP) final override;

		//getters
		uShort		getWisdom();
		uShort*		getInherentBonuses();
		uShort		getInherentBonus(uShort index);

	//player-exclusive functions
		void		heal(uShort amount); //negative heals don't really make sense

	//implementation of virtual functions
		void		takeDamage(uShort damage) final override;
		void		rollAttack(Character* target) final override;

	private:
		//player-exclusive functions
		void		calculateInherentBonus(uShort attribute, uShort index);//idea is to calculate it and put it in the index
		void		calculateInherentBonuses(); //for all at once

		uShort		wisdom;
		uShort		inherentBonus[5]; //will use for internal bonuses based on character stats
};