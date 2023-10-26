#include <iostream>
#include <vector>
//#include "vj3_myvector.hpp"
using namespace std;

void print(vector<int> myvector){
	for (auto broj : myvector){
		cout << broj << " ";
	}
	cout << endl;
}

int main() {
	vector<int> myvector;
	int elementi;
	cout << "Upisite broj vektora: \n";
	cin >> elementi;
	cout << "Unesite elemente vektora: \n";
	for (int i = 0; i < elementi; i++){
		int broj;
		cin >> broj;
		myvector.push_back(broj);
	}
	print(myvector);
	// input_vector(myvector, elementi);

	// int min, max;
	// cout << "Unesite min i max vrijednost: \n";
	// cin >> min >> max;
	// input_in_range(myvector, min, max);

	// output_vector(myvector);

}