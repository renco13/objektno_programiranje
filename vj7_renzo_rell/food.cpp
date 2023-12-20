#include "food.h"
#include <iostream>

int Food::counter = 0;

Food::Food() {}

int Food::getcounter() {
	return counter;
}

void Food::changecounter(int n) {
	counter += n;
}

void Food::printcounter() {
	std::cout << "Food counter: " << counter << std::endl;
}
