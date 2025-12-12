#include <iostream>
#include <climits>

using namespace std;

static const int n = 5;

struct Car {
    string brand;
    int mileage;
    int year;
};

struct CarNode {
    struct Car* car;
    struct CarNode* next;
};


int main()
{
    struct CarNode *carNode = new CarNode;
    int mostRecentYear = INT_MAX;
    CarNode *mostRecentCar;

    CarNode *head = carNode;
    for (int i = 0; i < n; i++) {
        Car* cur = new Car;
        head->car = cur;
        cout << "Brand: ";
            cin >> cur->brand;
        cout << "Mileage: ";
            cin >> cur->mileage;
        cout << "Year: ";
            cin >> cur->year;
        if (cur->year < mostRecentYear) {
            mostRecentYear = cur->year;
            mostRecentCar = head;
        }
        head = head->next;
    }
}
