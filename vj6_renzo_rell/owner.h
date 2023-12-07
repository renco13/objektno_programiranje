#pragma once
#ifndef owner_h
#define owner_h

#include <iostream>
#include <string>
#include <vector>

class Owner {
public:
	Owner(std::string& name);
	Owner(Owner& newown);
	~Owner();

	void addpet(Pet& pet);
	void action();
	std::string& getname();
	std::vector<Pet>& getpet();

private:
	std::string name;
	std::vector<Pet> pets;
};

#endif
