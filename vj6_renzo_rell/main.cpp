#include <iostream>
#include <string>
#include "owner.h"
#include "pet.h"

int main() {
	std::string ownername;
	std::cout << "Uneiste ime vlasnika: \n";
	std::getline(cin, ownername);
	Owner owner(ownername);

	std::string petname, pettype;
	int hunger, happines;
	bool isawake;

	std::cout << "Unesite podatke svojeg novog kucnog ljubimca: \n";
	std::cin >> petname >> pettype >> hunger >> happines >> isawake;
	owner.addpet(Pet(petname, pettype, hunger, happines, isawake));

	Owner ownercopy = owner;

	owner.action();
	ownercopy.action();

	Owner& happyowner = (owner.getname() == ownercopy.getname() && owner.getpet()[0].happinespoints() > ownercopy.getpet()[0].happinespoints()) ? owner : ownercopy;
	Pet& happypet = std::max_element(happyowner.getpet().begin(), happyowner.getpet().end(), [](Pet& pet1, Pet& pet2) {
		return pet1.happinespoints() < pet2.happinespoints();
		});
	std::cout << "Vlasnik sa najsretnijim ljubimcem je: " << happyowner.getname() << endl;
	std::cout << "Najsretniji ljubimac je: " << happypet.petname() << endl;
}