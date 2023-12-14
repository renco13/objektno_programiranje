#include <iostream>
#include <string>
#include <algorithm>
#include "owner.h"
#include "pet.h"

int main() {
	std::string ownername;
	std::cout << "Uneiste ime vlasnika: \n";
	std::getline(std::cin, ownername);
	Owner owner(ownername);

	std::string petname, pettype;
	int hunger, happines;
	bool isawake;

	std::cout << "Unesite podatke svojeg novog kucnog ljubimca: \n";
	//std::cin >> petname >> pettype >> hunger >> happines >> isawake;
	std::cout << "Name: \n";
	std::getline(std::cin, petname);
	std::cout << "Type: \n";
	std::getline(std::cin, pettype);
	std::cout << "Hunger and happines: \n";
	std::cin >> hunger >> happines;

	//std::cin >> petname >> pettype >> hunger >> happines >> isawake;
	//owner.addpet(Pet(petname, pettype, hunger, happines, isawake));
	Pet pet(petname, pettype, hunger, happines, isawake);

	owner.addpet(pet);
	owner.action();

	const Owner ownercopy = owner;
	ownercopy.action();

	const Owner& happyowner = (owner.getname() == ownercopy.getname() && owner.getpet()[0].happinespoints() > ownercopy.getpet()[0].happinespoints()) ? owner : ownercopy;
	const Pet happypet = *std::max_element(happyowner.getpet().begin(), happyowner.getpet().end(), [](const Pet& pet1, const Pet& pet2) {
		return pet1.happinespoints() < pet2.happinespoints();
		});
	std::cout << "Vlasnik sa najsretnijim ljubimcem je: " << happyowner.getname() << std::endl;
	std::cout << "Najsretniji ljubimac je: " << happypet.petname() << std::endl;
}
