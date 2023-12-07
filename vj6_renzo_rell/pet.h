#pragma once
#ifndef pet_h
#define pet_h

#include <iostream>
#include <string>

class Pet {
public:
	Pet(std::string& name, std::string& type, int hunger, int happines, bool isawake);
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