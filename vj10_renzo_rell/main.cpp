#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

void funk(const std::string& datoteka, const std::string& rijec, const std::string& podstring) {
    std::ifstream file(datoteka);
    if (!file.is_open()) {
        std::cout << "Datoteka se ne moze otvoriti." << std::endl;
        return;
    }

    std::istream_iterator<std::string> iterator(file);
    std::istream_iterator<std::string> kraj;
    std::vector<std::string> rijeci(iterator, kraj);
    file.close();

    std::vector<int> pozicije;
    for (auto i = rijeci.begin(); (i = find(i, rijeci.end(), rijec)) != rijeci.end(); i++) {
        pozicije.push_back(distance(rijeci.begin(), i));
    }

    rijeci.erase(remove_if(rijeci.begin(), rijeci.end(), [&podstring](const std::string& str) {
        return str.find(podstring) != std::string::npos;
        }
    ), rijeci.end());

    transform(rijeci.begin(), rijeci.end(), rijeci.begin(), [](std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
        });

    copy(rijeci.begin(), rijeci.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << "Pozicije pojavljivanja trazene rijeci: ";
    copy(pozicije.begin(), pozicije.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

struct Point {
    double x, y;


    double distance() const {
        return  std::sqrt(x * x + y * y);
    }
};


std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}


void processPoints() {
    std::ifstream file("points.txt");
    std::vector<Point> points;

    std::copy(std::istream_iterator<Point>(file),
        std::istream_iterator<Point>(),
        std::back_inserter(points));


    std::sort(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            return a.distance() < b.distance();
        });


    double radius = 5.0;
    int count = std::count_if(points.begin(), points.end(),
        [radius](const Point& p) {
            return p.distance() <= radius;
        });
    std::cout << "Broj tocaka unutar kruga: " << count << std::endl;


    double specificDistance = 3.0;
    Point newPoint = { 0, 0 };
    std::replace_if(points.begin(), points.end(),
        [specificDistance](const Point& p) {
            return std::abs(p.distance() - specificDistance) < 1e-6;
        }, newPoint);

    std::reverse(points.begin(), points.end());
    std::for_each(points.begin(), points.end(), [](const Point& p) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
        });
}


int main() {
    //funk("words.txt", "je", "programiranje");
    processPoints();
}