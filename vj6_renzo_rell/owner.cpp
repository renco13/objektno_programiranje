//#include <iostream>
//#include <string>
//#include <algorithm>
#include <vector>
#include "owner.h"
#include "pet.h"

Owner::Owner(const std::string& name) : name(name) {}
Owner::Owner(Owner& other) : name(other.name), pets(other.pets) {}
Owner::~Owner() {}

void Owner::addpet(const Pet& pet) { 
	pets.push_back(pet);
}

void Owner::action() const {
	for (auto& pet : pets) {
		std::cout << "What action do you want to do?\n";
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

std::string Owner::getname() const{
	return name;
}

const std::vector<Pet>& Owner::getpet() const{
	return pets;
}
