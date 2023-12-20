#pragma once
#ifndef owner_h
#define owner_h

#include <iostream>
#include <string>
#include <vector>
#include "pet.h"

class Owner {
public:
	Owner(const std::string& name);
	Owner(Owner& other);

	~Owner();

	void addpet(const Pet& pet);
	void action() const;
	const std::string getname() const;
	const std::vector<Pet>& getpet() const;
	Owner() = default;
	const Pet& happypet() const;
	void printdetails() const;
	int happypoints() const;

private:
	std::string name;
	std::vector<Pet> pets;
};

#endif
