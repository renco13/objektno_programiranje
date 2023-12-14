#pragma once
#ifndef pet_h
#define pet_h

#include <iostream>
#include <string>

class Pet {
public:
	//, std::string& type, int hunger, int happines, bool isawake);
	Pet(std::string& name, std::string& type, int hunger, int happines, bool isawake) : name(name), type(type), hunger(50), happines(50), isawake(true) {}
	//~Pet();

	void eat() const;
	void sleep() const;
	void play() const;
	std::string const& petname() const;
	std::string const& pettype() const;
	int hungerpoints() const;
	int happinespoints() const;
	bool ispetawake() const;

private:
	std::string name;
	std::string type;
	mutable int hunger;
	mutable int happines;
	bool isawake;
};

#endif
