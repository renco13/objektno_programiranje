#include <iostream>
#include <vector>
#include "vj3_myvector.hpp"
using namespace std;

int main() {
	//1:
	/*vector<int> myvector;
	input_vector(myvector, 4);
	input_in_range(myvector, 2, 13);
	print(myvector);*/
	
	//2:
	vector<int> myvector;
	input_vector(myvector, 4);
	vector<int> myvector_2;
	vector<int> myvector_3;
	input_vector(myvector_2, 4);
	compare_vector(myvector, myvector_2, myvector_3);
}