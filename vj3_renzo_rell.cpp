#include <iostream>
#include <vector>
#include "vj3_myvector.hpp"
using namespace std;

void input_vector(vector<int> &myvector, int elementi) {
	cout << "Unesite elemente vektora: \n";
	int broj;
	for (int i = 0; i < elementi; i++) {		
		cin >> broj;
		myvector.push_back(broj);
	}
}

void input_in_range(vector<int>& myvector, int min, int max) {
	cout << "Unesite brojeve unutar min max: \n";
	while (true) {
		int broj;
		cin >> broj;
		if (min < broj && broj < max) {
			myvector.push_back(broj);
		}
		else
			break;
	}
	cout << endl;
}

void print(vector<int> &myvector) {
	for (int broj : myvector) {
		cout << broj << " ";
	}
	cout << endl;
}

