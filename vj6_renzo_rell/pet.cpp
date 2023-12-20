//#include <iostream>
#include "pet.h"

Pet::Pet(const std::string& name, const std::string& type, int hunger, int happiness, bool isawake) : name(name), type(type), hunger(hunger), happiness(happiness), isawake(isawake), happihistory{ happiness } {}
Pet::Pet(const Pet& other) : name(other.name), type(other.type), hunger(other.hunger), happiness(other.happiness), isawake(other.isawake), happihistory{ happiness } {} 
Pet::~Pet(){}

void Pet::eat() const {
	if (!isawake) {
		std::cout << "Pet is sleeping, cannot eat right now.\n";
		std::cout << std::endl;
	}
	else if (isawake) {
		std::cout << "Pet is eating.\n";
		std::cout << "-1 Hunger +1 Happiness\n";
		hunger -= 1;
		//happihistory.push_back(happihistory.back() + 1);
		happiness += 1;
		std::cout << "Happiness points: " << happiness << std::endl;
		happihistory.push_back(happiness);
		std::cout << std::endl;
	}

}

void Pet::sleep() const {
	if (isawake) {
		std::cout << "Pet doesn't want to sleep.\n";
		std::cout << std::endl;
	}
	else if (!isawake) {
		std::cout << "Pet is sleeping.\n";
		std::cout << "+1 Hunger +1 Happiness\n";
		hunger += 1;
		//happihistory.push_back(happihistory.back() + 1);
		happiness += 1;
		std::cout << "Happiness points: " << happiness << std::endl;
		happihistory.push_back(happiness);
		std::cout << std::endl;
	}
}

void Pet::play() const {
	if (!isawake) {
		std::cout << "Pet is sleeping, cannot play right now.\n";
		std::cout << std::endl;
	}
	else if (isawake) {
		std::cout << "Pet is playing.\n";
		std::cout << "+1 Hunger +1 Happines\n";
		hunger += 1;
		//happihistory.push_back(happihistory.back() + 1);
		happiness += 1;
		std::cout << "Happiness points: " << happiness << std::endl;
		happihistory.push_back(happiness);
		std::cout << std::endl;
	}

}

std::string const& Pet::petname() const {
	return name;
}

std::string const& Pet::pettype() const {
	return type;
}

int Pet::hungerpoints() const {
	return hunger;
}

int Pet::happinespoints() const {
	return happiness;
}

bool Pet::ispetawake() const {
	return isawake;
}

const std::vector<int>& Pet::gethappihistory() const {
	return happihistory;
}
