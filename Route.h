#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <iostream>
#include "City.h"
using namespace std;

class Route {
private:
    vector<int> path;
    int totalCost;
public:
    Route(int numCities) : path(numCities, -1), totalCost(0) {}

    void setPath(const vector<int>& newPath, int cost) {
        path = newPath;
        totalCost = cost;
    }

    vector<int> getPath() const {
        return path;
    }

    int getTotalCost() const {
        return totalCost;
    }

    void printRoute(const vector<City>& cities) const {
        for (int city : path) {
            cout << cities[city].name << " -> ";
        }
        cout << cities[path[0]].name << endl;
        cout << "Общая длина маршрута: " << totalCost << endl;
    }
};

#endif // ROUTE_H
