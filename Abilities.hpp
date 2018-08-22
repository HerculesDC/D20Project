#pragma once

#include <string>

#include "Definitions.h"

class Abilities {
	public:
		enum			AbilityTypes {
						//"Basic" attacks:
						Cut, 
						Chop, 
						Slice, 

						//"Special" attacks:
						Grill,
						Boil,
						StirFry,
						Fry,

						//Healing abilities
						Sprinkle,
						Add,
						
						//indexer
						TypeCount};
						
						Abilities(AbilityTypes type);
						compl Abilities();

		//getters and setters
		void			setName(std::string name);
		void			setDescription(std::string description);
		void			setDamage(short damage);
		void			setCooldown(uShort cooldown);
		void			setOnCooldown(bool onCooldown);
		void			setTimer(uShort timer);
		void			setRoundEffects(short attack, short defense, short damage, short health); //sets all effects
		void			setRoundEffect(short bonus, uShort slot); //sets effect at index
		void			setPostEffects(short attack, short defense, short damage, short health);
		void			setPostEffect(short bonus, uShort slot);

		std::string		getName();
		std::string		getDescription();
		short			getDamage();
		uShort			getCooldown();
		bool			isOnCooldown();
		uShort			getTimer();
		short*			getRoundEffects(); //get all effects
		short			getRoundEffect(uShort slot); //get effect from index
		short*			getPostEffects();
		short			getPostEffect(uShort slot);

	private:
		AbilityTypes	aType;
		std::string		aName;
		std::string		aDescription;
		short			aDamage;
		uShort			aCooldown; //because negative cooldowns don't make sense
		bool			aOnCooldown;
		uShort			aCdTimer; //same cooldown logic
		short			aRoundEffect[4];
		short			aPostEffect[4];
};