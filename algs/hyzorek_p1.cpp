/*
Zadanie P1

1. Wczytać z klawiatury n (n – stała) kolejnych danych o samochodach:
   marka, rocznik, przebieg. Na ich podstawie utworzyć listę
   jednokierunkową w kolejności zgodnej z kolejnością wczytywania.

2. Wydrukować utworzoną listę, korzystając z funkcji drukującej
   listę zaczynającą się pod jakimś adresem (parametr funkcji).

3. Usunąć z listy najmłodszy samochód (o największym roczniku).
   Należy uwzględnić możliwość wystąpienia kilku elementów
   o tym samym, największym roczniku. Następnie dopisać na
   końcu listy nowy element wczytany z klawiatury.

4. Ponownie wydrukować listę.

5. Skasować całą listę, korzystając z funkcji kasującej listę
   zaczynającą się pod jakimś adresem (parametr funkcji).

6. Ponownie wydrukować listę.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr int n = 2; // AT LEAST 2

struct Car {
    string brand;
    int mileage = 0;
    int year = 0;
};

struct CarNode {
    Car car;
    CarNode* next{nullptr};
};

Car inputCar() // no-copy thanks to RVO/NRVO?
{
    Car car;
    cout << "Brand: ";
        cin >> car.brand;
    cout << "Mileage: ";
        cin >> car.mileage;
    cout << "Year: ";
        cin >> car.year;
    return car;
}

void printCarList(const CarNode* head)
{
    for (const CarNode* cur = head; cur != nullptr; cur = cur->next)
        cout
            << "Brand: " << cur->car.brand << '\t'
            << "Mileage: " << cur->car.mileage << '\t'
            << "Year: " << cur->car.year << '\n';
}

void deleteCarNodesByYear(CarNode*& head, int year)
{
    while (head && head->car.year == year) {
        CarNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    for (CarNode* cur = head; cur && cur->next; ) {
        if (cur->next->car.year == year) {
            CarNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
}

void addCar(CarNode*& head, const Car& car)
{
    if (!head) {
        head = new CarNode{car, nullptr};
        return;
    }

    CarNode* cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = new CarNode{car, nullptr};
}

void cleanup(CarNode*& head)
{
    while (head) {
        CarNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main()
{
    CarNode* head = new CarNode;
    CarNode* cur = head;
    int mostRecentYear = 0;

    cout << "==INPUT==\n";
    for (int i = 1; i <= n; ++i) {
        cur->car = inputCar();
        mostRecentYear = max(mostRecentYear, cur->car.year);

        if (i < n) {
            cur->next = new CarNode;
            cur = cur->next;
        }
    }

    cout << "==OUTPUT==\n";
    printCarList(head);

    deleteCarNodesByYear(head, mostRecentYear);
    cout << "*DELETING CARS WITH YEAR " << mostRecentYear << "*\n";

    cout << "==INPUT==\n";
    addCar(head, inputCar());

    cout << "==OUTPUT==\n";
    printCarList(head);

    cleanup(head);

    cout << "==AFTER CLEANUP==\n";
    printCarList(head);
}
