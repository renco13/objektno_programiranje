#pragma once
#ifndef pet_h
#define pet_h

#include <iostream>
#include <string>

class Pet {
public:
	//, std::string& type, int hunger, int happines, bool isawake);
	Pet(std::string& name, std::string& type) {
		std::string& petname = name;
		std::string& pettype = type;
		hunger = 50;
		happines = 50;
		isawake;
	}
	~Pet();

	void eat();
	void sleep();
	void play();
	std::string& petname();
	std::string& pettype();
	int hungerpoints();
	int happinespoints();
	bool ispetawake();

private:
	std::string name;
	std::string type;
	int hunger;
	int happines;
	bool isawake;
};

#endif
