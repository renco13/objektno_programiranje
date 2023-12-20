#pragma once
#ifndef pet_h
#define pet_h

#include <iostream>
#include <vector>
#include <string>

class Pet {
public:
	Pet(const std::string& name, const std::string& type, int hunger, int happiness, bool isawake); /*: name(name), type(type), hunger(50), happines(50), isawake(true) {}*/
	Pet(const Pet& other);
	~Pet();

	void eat() const;
	void sleep() const;
	void play() const;
	std::string const& petname() const;
	std::string const& pettype() const;
	int hungerpoints() const;
	//int getinithappy() const;
	int happinespoints() const;
	bool ispetawake() const;
	const std::vector<int>& gethappihistory() const;

private:
	std::string name;
	std::string type;
	mutable int hunger;
	mutable int happiness;
	mutable std::vector<int> happihistory;
	bool isawake;
};

#endif
