#include <iostream>
#include <vector>
#include <algorithm>
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
	myvector.clear();
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

void compare_vector(vector<int>& myvector, vector<int>& myvector_2, vector<int>& myvector_3) {
	for (const int& element : myvector) {
		if (find(myvector_2.begin(), myvector_2.end(), element) == myvector_2.end()) {
			myvector_3.push_back(element);
		}
	}
}

void sort_my_vector(vector<int>& myvector) {
	int suma = 0;
	//int maxmax = 0;
	sort(myvector.begin(), myvector.end());
	myvector.insert(myvector.begin(), 0);
	//int max = *max_element(myvector.begin(), myvector.end());
	for (const int& element : myvector) {
		//if (element == max) {
		//	if (maxmax < 0) {
		//		maxmax++;
		//	}
		//}
		//else {
		suma += element;
		//}
	}
	myvector.insert(myvector.end(), suma);
}

void remove_my_vector(vector<int>& myvector, vector<int>& myvector_2, vector<int>& myvector_3) {
	for (int i = 0; i < myvector.size(); i++) {
		if (myvector[i] != myvector_2[0]) {
			myvector_3.push_back(myvector[i]);
		}
	}
}


void print(vector<int> &myresult) {
	for (int broj : myresult) {
		cout << broj << " ";
	}
	cout << endl;
}
