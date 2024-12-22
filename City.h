#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City {
public:
    string name;

    City(const string& cityName) : name(cityName) {}
};

#endif // CITY_H
