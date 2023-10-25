#include <iostream>
using namespace std;

//3:
// struct vektor{
// 	int *podatak;
// 	int velicina;
// 	int kapaciteta;
// };
// struct matrica{
// 	int stupci;
// 	int redci;
// 	float **podaci;
// };
// vektor vector_new(){
// 	vektor vek;
// 	vek.podatak = new int[1];
// 	vek.velicina = 0;
// 	vek.kapaciteta = 0;
// 	return vek;
// };
// void unos_matrice(matrica &m){
// 	cout << "Unesite matricu: " << m.redci << m.stupci;
// 	for (int i = 0; i < m.redci; i++)
// 	{
// 		for (int j = 0; j < m.stupci; j++){
// 			cin >> m.podaci[i][j];
// 		}
// 	}
// }
// void vector_push_back(vektor& vek, int a){
// 	if (vek.velicina >= vek.kapaciteta){		
// 		vek.kapaciteta = vek.kapaciteta * 2;
// 		int *novi_podatak = new int[vek.kapaciteta];
// 		for (int i = 0; i < vek.velicina; i++)
// 			novi_podatak[i] = vek.podatak[i];
// 		delete[] vek.podatak;
// 		vek.podatak = novi_podatak;
// 	}
// 	vek.podatak[vek.velicina] = a;
// 	vek.velicina++;
// }
// void vector_pop_back(vektor& vek){
// 	if (vek.velicina > 0)
// 		vek.velicina--;
// }
// int vector_front(vektor& vek){
// 	if (vek.velicina > 0)
// 		return vek.podatak[0];
// 	return -1;
// }
// int vector_back(vektor& vek){
// 	if (vek.velicina > 0)
// 		return vek.podatak[vek.velicina - 1];
// 	return -1;
// }
// int vector_size(vektor& vek){
// 	return vek.velicina;
// }
// void vector_delete(vektor& vek) {
//     delete[] vek.podatak;
// }

//4:
// struct matrica{
// 	int redci, stupci;
// 	float **podaci;
// };
// void unos_matrice(matrica& mat){
// 	cout << "Unesite matricu [ " << mat.redci << " " << mat.stupci << " ]" << endl;
// 	for (int i = 0; i < mat.redci; i++){
// 		for (int j = 0; j < mat.stupci; j++)
// 			cin >> mat.podaci[i][j];
// 	}
// }
// void generiranje_matrice(matrica& mat, float a, float b){
// 	for (int i = 0; i < mat.redci; i++){
// 		for (int j = 0; j < mat.stupci; j++)
// 			mat.podaci[i][j] = a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (b - a)));
// 	}
// }
// matrica matrice_zbroj(const matrica& mat_1, const matrica& mat_2){
// 	matrica rez;
// 	if (mat_1.redci != mat_2.redci || mat_1.stupci != mat_2.stupci){
// 		cout << "Nisu iste dimenzije.\n";
// 		return rez;
// 	}
// 	rez.redci = mat_1.redci;
// 	rez.stupci = mat_1.stupci;
// 	rez.podaci = new float*[rez.redci];
// 	for (int i = 0; i < rez.redci; i++){
// 		rez.podaci[i] = new float[rez.stupci];
// 		for (int j = 0; j < rez.stupci; j++)
// 			rez.podaci[i][j] = mat_1.podaci[i][j] + mat_2.podaci[i][j];
// 	}
// 	return rez;
// }
// matrica matrice_razlika(const matrica& mat_1, const matrica& mat_2){
// 	matrica rez;
// 	if (mat_1.redci != mat_2.redci || mat_1.stupci != mat_2.stupci){
// 		cout << "Nisu iste dimenzije.\n";
// 		return rez;
// 	}
// 	rez.redci = mat_1.redci;
// 	rez.stupci = mat_1.stupci;
// 	rez.podaci = new float*[rez.redci];
// 	for (int i = 0; i < rez.redci; i++){
// 		rez.podaci[i] = new float[rez.stupci];
// 		for (int j = 0; j < rez.stupci; j++)
// 			rez.podaci[i][j] = mat_1.podaci[i][j] - mat_2.podaci[i][j];
// 	}
// 	return rez;
// }
// matrica matrice_mnozenje(const matrica& mat_1, const matrica& mat_2){
// 	matrica rez;
// 	if (mat_1.redci != mat_2.stupci){
// 		cout << "Nisu iste dimenzije.\n";
// 		return rez;
// 	}
// 	rez.redci = mat_1.redci;
// 	rez.stupci = mat_2.stupci;
// 	rez.podaci = new float*[rez.redci];
// 	for (int i = 0; i < rez.redci; i++){
// 		rez.podaci[i] = new float[rez.stupci];
// 		for (int j = 0; j < rez.stupci; j++){
// 			rez.podaci[i][j] = 0.0;
// 			for (int k = 0; k < rez.stupci; k++)
// 				rez.podaci[i][j] += mat_1.podaci[i][k] * mat_2.podaci[k][j];
// 		}
// 	}
// 	return rez;
// }
// matrica matrice_trans(const matrica& mat){
// 	matrica trans;
// 	trans.redci = mat.stupci;
// 	trans.stupci = mat.redci;
// 	trans.podaci = new float *[trans.redci];
// 	for (int i = 0; i < trans.redci; i++){
// 		trans.podaci[i] = new float[trans.stupci];
// 		for (int j = 0; j < trans.stupci; j++)
// 			trans.podaci[i][j] = mat.podaci[j][i];
// 	}
// 	return trans;
// }
// void ispis_matrice(matrica& mat){
// 	for (int i = 0; i < mat.redci; i++){
// 		for (int j = 0; j < mat.stupci; j++)
// 			cout << mat.podaci[i][j] << " ";
// 	}
// 	cout << endl;
// }

//1:
// void zad_1(int arr[], int n, int & min, int & max)
// {	
// 	min = arr[0];
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (arr[i] < min)
// 			min = arr[i];
// 		if (arr[i] > max)
// 			max = arr[i];
// 	}
// }

//2:
// int &zad_2(int n, int arr[])
// {
// 	return arr[n];
// }

int main()
{
	//1:
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

	//2:
	// int n;
	// cout << "Unesite broj: \n";
	// cin >> n;
	// int arr[] = { 13,21,213,121,421 };
	// cout << "Elemnt prije funkcije: " << arr[n] << endl;
	// int lvalue=arr[n];
	// zad_2(n, arr) = lvalue;
	// lvalue += 1;
	// cout << "Element posli funkcije: " << lvalue << endl;

	//3:
	// vektor vek = vector_new();
	// vector_push_back(vek, 1);
	// vector_push_back(vek, 2);
	// vector_push_back(vek, 4);
	// cout << "Front: " << vector_front(vek) << endl;
	// cout << "Back: " << vector_back(vek) << endl;
	// cout << "Size: " << vector_size(vek)<< endl;
	// vector_pop_back(vek);
	// cout << "Last element: " << vector_back(vek) << endl;
	// vector_delete(vek);

	//4:
	// int redci, stupci;
	// cout << "Unesite redtke i stupce za matricu: \n";
	// cin >> redci >> stupci;
	// matrica mat_1;
	// mat_1.redci = redci;
	// mat_1.stupci = stupci;
	// mat_1.podaci = new float *[redci];
	// for (int i = 0; i < redci; i++){
	// 	mat_1.podaci[i] = new float[stupci];
	// }
	// unos_matrice(mat_1);
	// cout << "Generiraj redtke i stupce za matricu [a, b]: \n";
	// float a, b;
	// cin >> a >> b;
	// matrica mat_2;
	// mat_2.redci = redci;
	// mat_2.stupci = stupci;
	// mat_2.podaci = new float *[redci];
	// for (int i = 0; i < redci; i++){
	// 	mat_2.podaci[i] = new float[stupci];
	// }
	// generiranje_matrice(mat_2, a, b);
	// cout << "Prva matrica: \n";
	// ispis_matrice(mat_1);
	// cout << endl;
	// cout << "Druga matrica: \n ";
	// ispis_matrice(mat_2);
	// cout << endl;
	// matrica zbroj = matrice_zbroj(mat_1, mat_2);
	// cout << "Zbroj matrica je: \n";
	// ispis_matrice(zbroj);
	// matrica razlika = matrice_razlika(mat_1, mat_2);
	// cout << "Razlika matrica je: \n";
	// ispis_matrice(razlika);
	// matrica umnozak = matrice_mnozenje(mat_1, mat_2);
	// cout << "Zbroj matrica je: \n";
	// ispis_matrice(zbroj);
	// matrica transponiranje = matrice_trans(mat_1);
	// cout << "Transponirana matrice je: \n";
	// ispis_matrice(transponiranje);
	// for (int i = 0; i < redci; i++){
	// 	delete[] mat_1.podaci[i];
	// 	delete[] mat_2.podaci[i];
	// }
	// delete[] mat_1.podaci;
	// delete[] mat_2.podaci;
	// for (int i = 0; i < zbroj.redci; i++){
	// 	delete[] zbroj.podaci[i];
	// 	delete[] razlika.podaci[i];
	// 	delete[] umnozak.podaci[i];
	// 	delete[] transponiranje.podaci[i];
	// }
	// delete[] zbroj.podaci;
	// delete[] razlika.podaci;
	// delete[] umnozak.podaci;
	// delete[] transponiranje.podaci;
}
	