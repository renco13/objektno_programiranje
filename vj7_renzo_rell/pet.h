#pragma once
#ifndef pet_h
#define pet_h

#include <iostream>
#include <vector>
#include <string>

class Pet {
public:
	Pet(const std::string& name, const std::string& type, int hunger, int happiness, bool isawake);
	Pet(const Pet& other);
	~Pet();

	void eat() const;
	void sleep() const;
	void play() const;
	std::string const& petname() const;
	std::string const& pettype() const;
	int hungerpoints() const;
	int happinespoints() const;
	bool ispetawake() const;
	const std::vector<int>& gethappihistory() const;

	bool operator==(const Pet& other) const;
	bool operator!=(const Pet& other) const;
	Pet& operator=(const Pet& other);
	bool operator<(const Pet& other) const;
	bool operator>(const Pet& other) const;
	bool operator<=(const Pet& other) const;
	bool operator>=(const Pet& other) const;
	Pet& operator++();
	Pet operator++(int);
	friend std::ostream& operator<<(std::ostream& os, const Pet& pet);

private:
	std::string name;
	std::string type;
	mutable int hunger;
	mutable int happiness;
	mutable std::vector<int> happihistory;
	bool isawake;
};

#endif
