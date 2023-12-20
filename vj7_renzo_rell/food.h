#pragma once
#ifndef food_h
#define food_h

class Food {
public:
	Food();
	static int getcounter();
	static void changecounter(int n);
	static void printcounter();

private:
	static int counter;
};

#endif