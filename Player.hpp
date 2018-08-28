#pragma once

#include "Character.hpp"

class Player : public Character {
	public:
				Player(std::string _name, int _maxHealth, int _atk, int _def, int _pow, int _wis); //feels a bit weird thinking of using :Character to autogenerate :Player...
				compl Player();

		bool	takeDamage(short damage) final override;
		
		short	useAbility(const Ability selectedAbility, Character* target) final override; // problem: how to know which ability it is?
		short	useAbility(const uShort slot, Character* target) final override; //problem. It's returning the damage, what for?
		
		bool	addAbility(const Ability selectedAbility) final override;

		uShort	getAbilityCooldown(const Ability selectedAbility) final override;
		uShort	getAbilityCooldown(const uShort slot) final override;

		void	print() final override;

	private:
		bool	alive;
};