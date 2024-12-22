#include <iostream>
#include "TravelSalesman.h"

using namespace std;

void runTravelSalesmanProblem() {
    int numCities;
    cout << "Введите количество городов: ";
    while (!(cin >> numCities) || numCities <= 1 || numCities >= 50) {
        cout << "Ошибка! Введите корректное количество городов (больше 1 и меньше 50): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    TravelSalesman ts(numCities);

    for (int i = 0; i < numCities; ++i) {
        string cityName;
        cout << "Введите название города " << i + 1 << ": ";
        cin >> cityName;
        ts.addCity(cityName);
    }

    for (int i = 0; i < numCities; ++i) {
        for (int j = i + 1; j < numCities; ++j) {
            int distance;
            cout << "Введите расстояние между " << ts.getCityName(i) << " и " << ts.getCityName(j) << ": ";
            while (!(cin >> distance) || distance <= 0) {
                cout << "Ошибка! Расстояние должно быть положительным числом. Введите расстояние между "
                     << ts.getCityName(i) << " и " << ts.getCityName(j) << ": ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            ts.setDistance(i, j, distance);
        }
    }

    bool useDP = false;
    Route optimalRoute = ts.findOptimalRoute(useDP);
    cout << "\nОптимальный маршрут: \n";
    optimalRoute.printRoute(ts.getCities());
}

int main() {
    runTravelSalesmanProblem();
    return 0;
}
