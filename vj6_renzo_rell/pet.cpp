//#include <iostream>
#include "pet.h"

//Pet::Pet(std::string& name, std::string& type, int hunger, int happines, bool isawake) : name(name), type(type), hunger(hunger), happines(happines), isawake(isawake){}

//Pet::Pet(std::string& name, std::string& type) {}
//
//Pet::~Pet() {}

void Pet::eat() {
	hunger -= 1;
	hunger += 1;
}

void Pet::sleep() {
	if (!isawake) {
		hunger += 1;
		happines += 1;
	}
}

void Pet::play() {
	hunger += 1;
	hunger += 1;
}

std::string& Pet::petname() {
	return name;
}

std::string& Pet::pettype() {
	return type;
}

int Pet::hungerpoints() {
	return hunger;
}

int Pet::happinespoints() {
	return happines;
}

bool Pet::ispetawake() {
	return isawake;
}
