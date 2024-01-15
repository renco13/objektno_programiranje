#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

template <typename T>
T min(T& a, T& b) {
	return (a < b) ? a : b;
}

template <typename T>
class skup {
private:
	std::vector<T> elementi;
public:
	void dodaj(const T& element) {
		elementi.push_back(element);
	}

	void isbrisi(const T& element) {
		auto i = find(elementi.begin(), elementi.end(), element);
		if (i != elementi.end()) {
			elementi.erase(i);
		}
	}

	bool sadrzi(const T& element) {
		for (auto& i : elementi) {
			if (i == element) {
				return true;
			}
		}
		return false;
	}

	void prikazi() const {
		std::cout << "Skup: " << std::endl;
		for (auto& element : elementi) {
			std::cout << element << " " << std::endl;
		}
	}
};

bool poredaj(char a, char b) {
	if (tolower(a) < tolower(b)) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
void sortiraj(T* niz, int duzina) {
	std::sort(niz, niz + duzina);
}

template<>
void sortiraj(char* niz, int duzina) {
	std::sort(niz, niz + duzina, poredaj);
}

template <typename T>
class point {
private:
	T x, y;

public:
	point(T x, T y) : 
		x(x), y(y) {}

	double operator-(const point& other) const {
		T dx = x - other.x;
		T dy = y - other.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	friend std::ostream& operator<<(std::ostream& os, const point& p) {
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}
};

int main()
{
	//Prvi

	//int a = 4;
	//int b = 7;
	//std::cout << "Manji od brojeva: " << min(a, b) << std::endl;

	//std::string str1 = "ovo je";
	//std::string str2 = "programiranje";
	//std::cout << "Manji od stringova: " << min(str1, str2) << std::endl;

	// Drugi
	
	//skup<int> a;
	//a.dodaj(1);
	//a.dodaj(2);
	//a.dodaj(3);
	//a.prikazi();
	//a.isbrisi(2);
	//a.prikazi();
	//std::cout << std::endl;
	//std::cout << "Da li sadrzi skup broj 3: " << (a.sadrzi(3)) << std::endl;

	// Treci
	
	//char niz[] = "neven";
	//int duzina = sizeof(niz) - 1;
	//sortiraj(niz, duzina);
	//std::cout << "Sortiran niz: " << niz << std::endl;

	//int niz1[] = { 21, 13, 999, 1, -4 };
	//int duzina1 = sizeof(niz1) / sizeof(int);
	//sortiraj(niz1, duzina1);
	//std::cout << "Sortiran niz: " << std::endl;
	//for (int i = 0; i < duzina1; i++)
	//{
	//	std::cout << niz1[i] << " ";
	//}

	// Cetvrti

	//point<int> p1(2, 3), p2(3, 4);
	//std::cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << (p1 - p2) << std::endl;
}