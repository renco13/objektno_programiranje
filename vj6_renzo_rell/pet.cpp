#include <iostream>
#include <string>
#include "pet.h"

Pet(std::string& name, std::string& type, int hunger, int happines, bool isawake) 
	: name(name), type(type), hunger(hunger), happines(happines), isawake(isawake){}

~Pet() {}

void eat() {
	hunger -= 1;
	hunger += 1;
}

void sleep() {
	if (!awake) {
		hunger += 1;
		happines += 1:
	}
}

void play() {
	hunter += 1;
	hunger += 1;
}

std::string& petname() {
	return name;
}

std::string& pettype() {
	return type;
}

int hungerpoints() {
	return hunger;
}

int happinespoints() {
	return happines;
}

bool ispetawake() {
	return isawake;
}