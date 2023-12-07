//#include <iostream>
//#include <string>
//#include <algorithm>
#include <vector>
#include "owner.h"
#include "pet.h"

//Owner::Owner(std::string& name) : name(name) {}
//Owner::Owner(Owner& newown) : name(newown.name), pets(newown.pets) {}
//Owner::~Owner() {}

void Owner::addpet(Pet& pet) {
	pets.push_back(pet);
}

void Owner::action() {
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

std::string& Owner::getname() {
	return name;
}

std::vector<Pet>& Owner::getpet() {
	return pets;
}
