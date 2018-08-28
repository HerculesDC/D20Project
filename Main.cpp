#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>

#include "LookupTables.hpp"
#include "Helpers.inl"

#include "Player.hpp"

//this namespace may need a separate file...
namespace printer { 
	void printStat(const Stat stat) {
		std::cout << "Stat: " << stat.getName() << ", value: " << stat.getStat() << ", inherent bonus: " << stat.getBonus() << std::endl;
	}
}

int main(void) { 
	
	srand(time(NULL));

	std::vector<Ability> abilities;

	abilities.push_back(Ability::Ability(Ability::Standard));
	abilities.push_back(Ability::Ability(Ability::Heal));

	for (int i = 0; i < abilities.size(); i++) abilities[i].print();

	Player herc("Herc", 115, 10, 10, 10, 10), hark("Hark", 98, 13, 8, 10, 10);

	herc.addAbility(abilities[0]);
	herc.print();
	hark.addAbility(abilities[1]);

	herc.print();
	hark.print();
	herc.getAbility(0).print();
	hark.getAbility(0).print();
	herc.useAbility(1, &hark); //careful! Slot uses ability number, not order in the array!!!
	herc.print();
	hark.print();

	std::cout << hark.useAbility(1, &hark) << std::endl;

	hark.print();

	std::cout << std::endl;
	std::cout << "So far, the code is being compiled all right. You may close this window (for now)" << std::endl;

	return 0; 
}