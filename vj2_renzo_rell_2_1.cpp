#include <iostream>
using namespace std;

//1:
//Napisati funkciju koja racuna najveci i najmanji broj u nizu od n prirodnih
//brojeva.Funkcija vraca tražene brojeve pomocu referenci.

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

int main()
{
	//PRVI ZADATAK
	/*int n;
	int arr[100];
	cout << "Unesite velicinu niza: \n";
	cin >> n; 
	cout << "Unesite brojeve u nizu: \n";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int min,max;
	zad_1(arr,n,min,max);

	cout << "Velicina niza je: " << n << endl;
	cout << "Najmanji je: " << min << endl;
	cout << "Najveci je: " << max << endl;*/

	//DRUGI ZADATAK
	int n;
	cout << "Unesite broj: \n";
	cin >> n;
	int arr[] = { 13,21,213,121,421 };
	cout << "Elemnt prije funkcije: " << arr[n] << endl;
	int lvalue=arr[n];
	zad_2(n, arr) = lvalue;
	lvalue += 1;
	cout << "Element posli funkcije: " << lvalue << endl;
	
}