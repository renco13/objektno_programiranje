#include <iostream>
#include "pet.h"
#include "food.h"

int main() {
	std::cout << "Counter with no pets -> ";
	Food::printcounter();
	Pet pet1("Tidus", "Dog", 60, 80, true);
	Pet pet2("Yuna", "Dog", 70, 90, true);
	Food::changecounter(pet1.hungerpoints());
	std::cout << "Counter with one pet -> ";
	Food::printcounter();
	Food::changecounter(pet2.hungerpoints());
	std::cout << "Counter with two pets -> ";
	Food::printcounter();
	std::cout << std::endl;

	if (pet1 == pet2) {
		std::cout << "Pets are equal." << std::endl;
	}
	else if (pet1 != pet2) {
		std::cout << "Pets are not equal." << std::endl;
	}
	std::cout << std::endl;

	if (pet1 > pet2) {
		std::cout << pet1.petname() << " is happier than " << pet2.petname() << "." << std::endl;
	}
	else if (pet1 < pet2) {
		std::cout << pet2.petname() << " is happier than " << pet1.petname() << "." << std::endl;
	}
	else {
		std::cout << pet2.petname() << " and " << pet1.petname() << " are equally happy." << std::endl;
	}
	std::cout << std::endl;

	Pet pet3 = pet1;
	std::cout << pet1.petname() << " was copied into a copy of " << pet3.petname() << "." << std::endl;
	std::cout << std::endl;

	Pet pet4 = ++pet2;
	std::cout << "After post-increment, " << pet2.petname() << " hunger points are: " << pet2.hungerpoints() << std::endl;
	std::cout << "After post-increment, copy " << pet4.petname() << " hunger points are: " << pet4.hungerpoints() << std::endl;
	std::cout << std::endl;

	std::cout << "This is " << pet1.petname() << " and their hunger points are " << pet1.hungerpoints() << ", they ate " << pet1.getportions() << " portions." << std::endl;
	std::cout << "This is " << pet2.petname() << " and their hunger points are " << pet2.hungerpoints() << ", they ate " << pet2.getportions() << " portions."  << std::endl;
	std::cout << std::endl;

	std::cout << pet2.petname() << "'s details are:\n" << pet2 << std::endl;
}
