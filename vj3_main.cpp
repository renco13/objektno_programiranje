#include <iostream>
#include <vector>
#include "vj3_myvector.hpp"
using namespace std;

int main() {
	vector<int> myvector;
	int elementi;
	cout << "Upišite elemente vektora: \n";
	cin >> elementi;
	input_vector(myvector, elementi);

	int min, max;
	cout << "Unesite min i max vrijednost: \n";
	cin >> min >> max;
	input_in_range(myvector, min, max);

	output_vector(myvector);

}