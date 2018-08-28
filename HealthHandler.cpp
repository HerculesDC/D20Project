#include "HealthHandler.hpp"

Health::Health(int _value) : maxHealth(_value), currentHealth(_value) {}

Health::Health(const Health& other) {
	this->currentHealth = other.currentHealth;
	this->maxHealth = other.maxHealth;
}

Health::Health(int _maxVal, int _curVal) : maxHealth(_maxVal), currentHealth(_curVal) {
	if(!this->checkHealth()) this->currentHealth = this->maxHealth;
}

Health::compl Health() { this->maxHealth = 0; this->currentHealth = 0; }

void Health::setMaxHealth(int _maxHP) {

	this->maxHealth = _maxHP; 
	if(!this->checkHealth()) this->currentHealth = this->maxHealth;
}

int Health::getMaxHealth() const { return this->maxHealth; }

int Health::getHealth() const { return this->currentHealth; }

bool Health::assessLife() const { return this->currentHealth > 0; }

bool Health::checkHealth() const { return this->currentHealth <= this->maxHealth; }

bool Health::checkHealth(int amount) const { return ((this->currentHealth + amount) <= this->maxHealth); }

//Overloaded operators:

int Health::operator+(int amount) { return this->currentHealth + amount; }
int Health::operator-(int amount) { return this->currentHealth - amount; }

int Health::operator+=(int amount) {

	//the idea is to check if the sum does not exceed (if the sum is "possible"
		//also, don't forget to assign your variables
	if (this->checkHealth(amount)) this->currentHealth += amount;
	else this->currentHealth = this->maxHealth;

	return this->currentHealth;
}

int Health::operator-=(int amount) {

	if (this->currentHealth - amount <= 0) this->currentHealth = 0;
	else this->currentHealth -= amount;

	return this->currentHealth;
}

// as stated in header, you can only compare "this" against something else
	//separate "something else vs this" comparison requires non-member, possibly friend function
bool Health::operator==(int rValue) const { return (this->currentHealth == rValue); }
bool Health::operator!=(int rValue) const { return !((*this) == rValue); }//seems cumbersome...