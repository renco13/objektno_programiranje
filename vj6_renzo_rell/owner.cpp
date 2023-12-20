//#include <iostream>
//#include <string>
#include <algorithm>
//#include <vector>
#include "owner.h"
//#include "pet.h"

Owner::Owner(const std::string& name) : name(name) {}
Owner::Owner(Owner& other) : name(other.name), pets(other.pets) {}
Owner::~Owner() {}


void Owner::addpet(const Pet& pet) {
	pets.push_back(pet);
}

void Owner::action() const {
	for (auto& pet : pets) {

		//std::cout << "Choose an action: \n";
		//std::cout << "1. Eat\n2. Sleep\n3. Play\n";
		//int choice;
		//std::cin >> choice;
		//switch (choice) {

		std::cout << "Pet: " << pet.petname() << "\n";
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

const std::string Owner::getname() const {
	return name;
}

const std::vector<Pet>& Owner::getpet() const {
	return pets;
}

int Owner::happypoints() const {
	int pethappiness = 0;
	for (const auto& pet : pets) {
		pethappiness += pet.happinespoints();
	}
	return pethappiness;
}

//const Owner& Owner::happyowner() const {
//	auto happiestpet = std::max_element(pets.begin(), pets.end(), [](const Pet& pet1, const Pet& pet2) {
//		return pet1.happinespoints() < pet2.happinespoints();
//		});
//	//auto happiestpet = std::max_element(pets.begin(), pets.end(), [](const Pet& pet1, const Pet& pet2) {
//	//	return pet1.happinespoints() < pet2.happinespoints();
//	//}
//	return *this;
//}

const Pet& Owner::happypet() const {
	auto happiestpet = std::max_element(pets.begin(), pets.end(), [](const Pet& pet1, const Pet& pet2) {
		return pet1.happinespoints() < pet2.happinespoints();
		});
	return *happiestpet;
}

void Owner::printdetails() const {
	std::cout << "Owner: " << name << std::endl;
	std::cout << "Pets: " << std::endl;
	for (const auto& pet : pets) {
		std::cout << " - " << pet.petname() << " (Happiness: " << pet.happinespoints() << ")" << std::endl;
	}
	std::cout << std::endl;
}
