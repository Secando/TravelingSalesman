#ifndef TRAVELSALESMAN_H
#define TRAVELSALESMAN_H

#include <vector>
#include <map>
#include <limits>
#include <algorithm>
#include "City.h"
#include "DistanceMatrix.h"
#include "Route.h"

using namespace std;

class TravelSalesman {
private:
    vector<City> cities;
    DistanceMatrix distanceMatrix;
    Route bestRoute;
    map<vector<int>, int> routeCache;

public:
    TravelSalesman(int numCities) : distanceMatrix(numCities), bestRoute(numCities) {}

    void addCity(const string& cityName) {
        cities.push_back(City(cityName));
    }

    void setDistance(int fromCity, int toCity, int distance) {
        distanceMatrix.setDistance(fromCity, toCity, distance);
    }

    Route findOptimalRoute(bool useDP = false) {
        vector<int> path(cities.size());
        for (int i = 0; i < cities.size(); ++i) {
            path[i] = i;
        }

        int minCost = numeric_limits<int>::max();
        vector<int> bestPath;

        do {
            int currentCost = calculateRouteCost(path);
            if (currentCost < minCost) {
                minCost = currentCost;
                bestPath = path;
            }
        } while (next_permutation(path.begin() + 1, path.end()));

        bestRoute.setPath(bestPath, minCost);
        return bestRoute;
    }

    string getCityName(int index) const {  
        return cities[index].name;
    }

    vector<City>& getCities() {  
        return cities;
    }

private:
    int calculateRouteCost(const vector<int>& path) const {
        int cost = 0;
        for (size_t i = 0; i < path.size(); ++i) {
            int fromCity = path[i];
            int toCity = path[(i + 1) % path.size()];
            cost += distanceMatrix.getDistance(fromCity, toCity);
        }
        return cost;
    }

    int findOptimalRouteDP(vector<int>& path, int visitedMask, int pos) {
        if (visitedMask == (1 << cities.size()) - 1) {
            return distanceMatrix.getDistance(path[pos], path[0]);
        }

        if (routeCache.find(path) != routeCache.end()) {
            return routeCache[path];
        }

        int minCost = numeric_limits<int>::max();

        for (int city = 0; city < cities.size(); ++city) {
            if (!(visitedMask & (1 << city))) {
                path.push_back(city);
                int newCost = distanceMatrix.getDistance(pos, city) +
                              findOptimalRouteDP(path, visitedMask | (1 << city), city);
                minCost = min(minCost, newCost);
                path.pop_back();
            }
        }

        routeCache[path] = minCost;
        return minCost;
    }
};

#endif // TRAVELSALESMAN_H
