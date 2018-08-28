#pragma once
#include <string>

#include "Helpers.inl"

class Stat{

	public:

		enum						Type { Attack, Defense, Power, Wisdom, StatCount };
								
									Stat(Type type, uShort value = 8);
									Stat(const Stat& other);
									compl Stat();
									
		void						setStat(uShort value);
		
		Stat::Type					getType()	const;
		std::string					getName()	const;
		uShort						getStat()	const;
		uShort						getBonus()	const;
		

	private: //method
		void						calculateBonus();

	private: //static const members. 
			 //Since they're shared by all instances, but shouldn't be accessible from the outside 
			 //as per design choices
		static const std::string	name[Stat::StatCount];

	private: //members
		Type						type;
		uShort						value;
		uShort						bonus;
};