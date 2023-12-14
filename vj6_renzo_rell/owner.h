#pragma once
#ifndef owner_h
#define owner_h

#include <iostream>
#include <string>
#include <vector>
#include "pet.h"

class Owner {
public:
	Owner(const std::string& name); /*{
		std::string& ownername = name;
	}*/
	Owner(Owner& other);

	~Owner();

	void addpet(const Pet& pet);
	void action() const;
	std::string getname() const;
	const std::vector<Pet>& getpet() const;

private:
	std::string name;
	std::vector<Pet> pets;
};

#endif
