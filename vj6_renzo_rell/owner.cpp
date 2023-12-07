#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "owner.h"

Owner(std::string& name) : name(name) {}
Owner(Owner& newown) : name(newown.name), pets(newown.pets) {}
~Owner() {}

void addpet(Pet& pet) {
	pets.pushback(pet);
}

void action() {
	for (auto& pet : pets) {
		int random = rand() % 3;
		switch (random) {
		case 0:
			pet.eat();
			break;
		case 1:
			pet.sleep();
			break;
		case 2:
			pet.play();
			break;
		}
	}
}

std::string& getname() {
	return name;
}

std::vector<Pet> getpet() {
	return pets;
}