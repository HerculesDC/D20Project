#pragma once

class Health { //not providing for a "health bonus". May require a bit of rework to be reused for Mana/Special points, etc...
	public:
				Health(int maxHP = 100);
				Health(const Health& other);
				Health(int maxHP, int currentHP);
				compl Health();
		
		void	setMaxHealth(int maxHP);

		int		getHealth() const;
		int		getMaxHealth() const;

		bool	assessLife() const;
		
		//review rules
			//the plan is to always have health + or - an integer.
			//may need to overload the = operator as well in this case.
		int		operator+(int amount);
		int		operator-(int amount);
		int		operator+=(int amount);
		int		operator-=(int amount);

		//a note on overloading comparison operators: they already know what the LHV is
			//think later for "health level" comparisons
		bool	operator==(int rValue) const; 
		bool	operator!=(int rValue) const;
		

	private:
		bool	checkHealth() const;
		bool	checkHealth(int amount) const;

	private:
		int		maxHealth;
		int		currentHealth;
};