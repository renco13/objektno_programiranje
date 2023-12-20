#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "owner.h"
#include "pet.h"
#include "food.h"

int main() {
	std::srand(std::time(0));

	Owner owner1("Marko");

	owner1.addpet(Pet("Viski", "Dog", 50, 70, true));
	owner1.addpet(Pet("Alfred", "Hamster", 40, 70, false));

	Owner ownercopy = owner1;
	std::cout << "Copied owners " << "'" << ownercopy.getname() << "'" << ", details are: \n";
	ownercopy.printdetails();
	std::cout << std::endl;
	owner1.action();
	owner1.action();
	owner1.action();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Owner owner2("Roko");
	owner2.addpet(Pet("Bella", "Dog", 60, 70, false));
	owner2.addpet(Pet("Max", "Cat", 70, 70, true));
	owner2.action();
	owner2.action();
	owner2.action();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Counter with no pets -> ";
	Food::printcounter();
	Pet pet7_1("Tidus", "Dog", 60, 80, true);
	Pet pet7_2("Yuna", "Dog", 60, 80, true);
	Food::changecounter(pet7_1.hungerpoints());
	std::cout << "Counter with one pet -> ";
	Food::printcounter();
	Food::changecounter(pet7_2.hungerpoints());
	std::cout << "Counter with two pets -> ";
	Food::printcounter();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	if (pet7_1 == pet7_2) {
		std::cout << "Pets are equal." << std::endl;
	}
	else {
		std::cout << "Pets are not equal." << std::endl;
	}
	std::cout << std::endl;
	if (pet7_1 > pet7_2) {
		std::cout << pet7_1.petname() << " is happier than " << pet7_2.petname() << "." << std::endl;
	}
	else if (pet7_1 < pet7_2) {
		std::cout << pet7_2.petname() << " is happier than " << pet7_1.petname() << "." << std::endl;
	}
	else {
		std::cout << pet7_2.petname() << " and " << pet7_1.petname() << " are equally happy." << std::endl;
	}
	std::cout << std::endl;
	Pet pet7_3 = pet7_1++;
	std::cout << "After post-increment, " << pet7_1.petname() << " points are: " << pet7_1.happinespoints() << std::endl;
	std::cout << "After post-increment, " << pet7_3.petname() << " points are: " << pet7_3.happinespoints() << std::endl;
	pet7_2++;
	std::cout << "After pre-increment, " << pet7_2.petname() << " points are: " << pet7_2.happinespoints() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Owner happyowner;
	if (owner1.happypet().happinespoints() > owner2.happypet().happinespoints()){
		happyowner = owner1;
	}
	else {
		happyowner = owner2;
	}
	const Pet& happipet = happyowner.happypet();
	if (owner1.happypet().happinespoints() > owner2.happypet().happinespoints()) {
		std::cout << owner1.getname() << " has the happiest pet.\n";
	}
	else if (owner1.happypet().happinespoints() < owner2.happypet().happinespoints()) {
		std::cout << owner2.getname() << " has the happiest pet.\n";
	}
	else {
		std::cout << "Both owners have an equally happy pet.\n" << std::endl;
	}
}
