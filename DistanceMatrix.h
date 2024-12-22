#ifndef DISTANCEMATRIX_H
#define DISTANCEMATRIX_H

#include <vector>
using namespace std;

class DistanceMatrix {
private:
    vector<vector<int>> matrix;
public:
    DistanceMatrix(int numCities) {
        matrix.resize(numCities, vector<int>(numCities, 0));
    }

    void setDistance(int fromCity, int toCity, int distance) {
        matrix[fromCity][toCity] = distance;
        matrix[toCity][fromCity] = distance;
    }

    int getDistance(int fromCity, int toCity) const {
        return matrix[fromCity][toCity];
    }
};

#endif // DISTANCEMATRIX_H
