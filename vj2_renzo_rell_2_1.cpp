#include <iostream>
using namespace std;

//1:
//Napisati funkciju koja racuna najveci i najmanji broj u nizu od n prirodnih
//brojeva.Funkcija vraca tra�ene brojeve pomocu referenci.

void zad_1(int arr[], int n, int & min, int & max)
{	
	min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
}

//2:
//Napisati funkciju koja vraca referencu na neki element niza. Koristeci povratnu
//vrijednost funkcije kao lvalue uvecajte i - ti element niza za jedan.

int &zad_2(int n, int arr[])
{
	return arr[n];
}

struct vector{
	int *podataka;
	int velicina;
	int kapaciteta;
};

struct matrica{
	int stupci;
	int redci;
	float **podaci;
};

void unos_matrice(matrica &m){
	cout << "Unesite matricu: " << m.redci << m.stupci;
	for (int i = 0; i < m.redci; i++)
	{
		for (int j = 0; j < m.stupci; j++){
			cin >> m.podaci[i][j];
		}
	}
}

vector vector_new(){
	vector vek;
	vek.podataka = new int[1];
	vek.velicina = 0;
	vek.kapaciteta = 0;
	return vek;
};

void

int main()
{
	//PRVI ZADATAK
	// int n;
	// int arr[100];
	// cout << "Unesite velicinu niza: \n";
	// cin >> n; 
	// cout << "Unesite brojeve u nizu: \n";
	// for (int i = 0; i < n; i++)
	// {
	// 	cin >> arr[i];
	// }
	// int min,max;
	// zad_1(arr,n,min,max);
	// cout << "Velicina niza je: " << n << endl;
	// cout << "Najmanji je: " << min << endl;
	// cout << "Najveci je: " << max << endl;

	//DRUGI ZADATAK
	// int n;
	// cout << "Unesite broj: \n";
	// cin >> n;
	// int arr[] = { 13,21,213,121,421 };
	// cout << "Elemnt prije funkcije: " << arr[n] << endl;
	// int lvalue=arr[n];
	// zad_2(n, arr) = lvalue;
	// lvalue += 1;
	// cout << "Element posli funkcije: " << lvalue << endl;

	//TRECI ZADATAK
	vector vek = vector_new();
	vector_push_back(vek, 1);
	vector_push_back(vek, 2);
	vector_push_back(vek, 4);
	cout << "Front: \n" << vector_front(vek);
	cout << "Back: \n" << vector_back(vek);
	cout << "Size: \n" << vector_size(vek);
	vector_pop_back(vek);
	cout << "Last element: \n" << vecotr_back(vek);
	vector_delete(vek);
}	
