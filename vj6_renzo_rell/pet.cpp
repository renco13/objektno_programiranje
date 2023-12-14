//#include <iostream>
#include "pet.h"

//Pet::Pet(std::string& name, std::string& type, int hunger, int happiness, bool isawake)
//	: name(name), type(type), hunger(hunger), happines(happines), isawake(isawake) {}

void Pet::eat() const{
	std::cout << "Pet is eating.\n";
	hunger -= 1;
	hunger += 1;
}

void Pet::sleep() const{
	if (!isawake) {
		std::cout << "Pet is sleeping.\n";
		hunger += 1;
		happines += 1;
	}
}

void Pet::play() const{
	std::cout << "Pet is playing.\n";
	hunger += 1;
	happines += 1;
}

std::string const& Pet::petname() const {
	return name;
}

std::string const& Pet::pettype() const {
	return type;
}

int Pet::hungerpoints() const{
	return hunger;
}

int Pet::happinespoints() const{
	return happines;
}

bool Pet::ispetawake() const{
	return isawake;
}
