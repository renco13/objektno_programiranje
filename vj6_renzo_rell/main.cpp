#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "owner.h"
#include "pet.h"

int main() {
	std::srand(std::time(0));
	//std::string ownername;
	//std::cout << "Uneiste ime vlasnika: \n";
	//std::getline(std::cin, ownername);
	//Owner owner1(ownername);

	//std::string petname, pettype;
	//int hunger, happines;
	//bool isawake = false;

	//std::cout << "Unesite podatke svojeg novog kucnog ljubimca\n";
	////std::cin >> petname >> pettype >> hunger >> happines >> isawake;

	//std::cout << "Name: \n";
	//std::getline(std::cin, petname);
	//std::cout << "Type: \n";
	//std::getline(std::cin, pettype);
	//std::cout << "Hunger and happines: \n";
	//std::cin >> hunger >> happines;

	////std::cin >> petname >> pettype >> hunger >> happines >> isawake;
	////owner.addpet(Pet(petname, pettype, hunger, happines, isawake));
	//Pet pet(petname, pettype, hunger, happines, isawake);

	//owner1.addpet(pet);
	//owner1.action();

	//std::cout << std::endl;
	//const Owner owner2 = owner1;
	//std::cout << "Uneiste ime vlasnika: \n";
	//std::getline(std::cin, ownername);
	////Owner owner2(ownername);
	//std::cout << "Unesite podatke svojeg novog kucnog ljubimca\n";
	//std::cout << "Name: \n";
	//std::getline(std::cin, petname);
	//std::cout << "Type: \n";
	//std::getline(std::cin, pettype);
	//std::cout << "Hunger and happines: \n";
	//std::cin >> hunger >> happines;
	////std::cin >> petname >> pettype >> hunger >> happines >> isawake;
	//Pet pet1(petname, pettype, hunger, happines, isawake);

	//owner1.addpet(pet1);
	//owner2.action();

	//std::cout << "Unesite podatke svojeg novog kucnog ljubimca\n";
	////std::cin >> petname >> pettype >> hunger >> happines >> isawake;
	//std::cout << "Name: \n";
	//std::getline(std::cin, petname);
	//std::cout << "Type: \n";
	//std::getline(std::cin, pettype);
	//std::cout << "Hunger and happines: \n";
	//std::cin >> hunger >> happines;
	//Pet pet1(petname, pettype, hunger, happines, isawake);
	//ownercopy.addpet(pet);

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

	//Pet pet1("Lulu", "Dog", 50, 50, true);
	//Pet pet2("Meowy", "Cat", 40, 60, true);
	//owner1.addpet(pet1);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Owner owner2("Roko");
	owner2.addpet(Pet("Bella", "Dog", 60, 70, false));
	owner2.addpet(Pet("Max", "Cat", 70, 70, true));
	owner2.action();
	owner2.action();
	owner2.action();


	//Owner happyowner = std::max_element(Owner.begin(), Owner.end(), [](const Owner& owner1, const Owner& owner2) {
	//	return owner1.happypet().happinespoints() < owner2.happypet().happinespoints()
	//	});

	//const Owner& happyowner = (owner1.happypet().happinespoints() > owner2.happypet().happinespoints());
	//const Pet& happypet = happyowner.getpet();

	//const Owner& happyowner = (owner.getname() == ownercopy.getname() && owner.getpet()[0].happinespoints() > ownercopy.getpet()[0].happinespoints()) ? owner : ownercopy;
	//const Pet happypet = *std::max_element(happyowner.getpet().begin(), happyowner.getpet().end(), [](const Pet& pet1, const Pet& pet2) {
	//	return pet1.happinespoints() < pet2.happinespoints();
	//});

	//std::cout << std::endl;
	Owner happyowner;
	//const Owner& happyowner = (owner1.happypoints() > owner2.happypoints()) ? owner1 : owner2;
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
	//std::cout << "The happiest pet is: " << happipet.petname() << ", with: " << happipet.happinespoints() << " points.\n";

	//if (owner1.happypet().happinespoints() > owner2.happypet().happinespoints()) {
	//	std::cout << "The happiest pet is: " << happipet.petname() << ", with: " << happipet.happinespoints() << " points.\n";
	//}
	//else if (owner1.happypet().happinespoints() < owner2.happypet().happinespoints()) {
	//	std::cout << owner2.getname() << " has the happiest pet.\n";
	//}
	//else {
	//	std::cout << "Both owners have equally happy pets.\n" << std::endl;
	//}
	//std::cout << "The owner with the happiest pet is: " << happyowner.getname() << std::endl;
	//std::cout << "The happiest pet is: " << happipet.petname() << ", with: " << happipet.happinespoints() << " points.\n";

	//std::cout << std::endl;
	//if (owner1.happypet().happinespoints() > owner2.happypet().happinespoints()) {
	//	std::cout << owner1.getname() << " has the happiest pet.\n";
	//}
	//else if (owner1.happypet().happinespoints() < owner2.happypet().happinespoints()) {
	//	std::cout << owner2.getname() << " has the happiest pet.\n";
	//}
	//else {
	//	std::cout << "Both owners have equally happy pets.\n" << std::endl;
	//}

	//std::cout << "Vlasnik sa najsretnijim ljubimcem je: " << happyowner.getname() << std::endl;
	//std::cout << "Najsretniji ljubimac je: " << happypet.petname() << std::endl;

}
