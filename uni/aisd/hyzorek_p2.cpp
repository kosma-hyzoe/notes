/*
 * Zadanie P2

 * 1. Tworzy liste z danych o samochodach (marka, cena, przebieg,
 *    rok produkcji), wczytywanych z pliku o nazwie podanej przez
 *    uzytkownika – korzystajac z funkcji dolaczania jednego
 *    samochodu o podanych danych na koncu listy zaczynajacej sie
 *    pod jakims adresem (parametrem funkcji dolaczania jest tylko
 *    adres poczatku listy oraz marka, cena, przebieg i rok
 *    produkcji dolaczanego samochodu).
 *
 * 2. Napisac funkcje, ktora:
 *    a) Do listy wstawia nowy samochod przed co drugi element o
 *       przebiegu mniejszym od przebiegu przedostatniego
 *       samochodu na liscie oraz przed co trzeci element o roku
 *       produkcji starszym niz sredni rok produkcji wszystkich
 *       samochodow na liscie. Nowy samochod posiada dane
 *       wczytane przez uzytkownika.
 *    b) Skasowac wszystkie samochody z listy znajdujace sie za
 *       pierwszym samochodem o cenie wyzszej niz podana przez
 *       uzytkownika wartosc oraz w ich miejsce wstawic jeden
 *       samochod zawierajacy marke wczytana przez uzytkownika,
 *       natomiast przebieg, rok produkcji oraz cene policzyc
 *       jako srednia arytmetyczna z odpowiednich wartosci
 *       elementow skasowanych.
 *
 * 3. Na koncu usuwa liste z pamieci.
 *
 * 4. Drukuje liste po kazdej operacji korzystajac z odpowiedniej
 *    funkcji drukowania listy.
 *
 * Uwaga: Slowo "jakis" oznacza parametr funkcji.
 */

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace hyzorek_p2 {
using std::string;
using std::cout;
using std::cin;
using std::getline;
using Path = std::filesystem::path;

struct Car {
    string brand;
    double price{-1.0};
    int mileage{0};
    int year{0};
};

struct CarNode {
    Car car;
    CarNode* next{nullptr};
};

void appendCar(CarNode*& head, const string& brand,
            double price, int mileage, int year) {
    Car car{brand, price, mileage, year};

    if (!head) {
        head = new CarNode{car, nullptr};
        return;
    }

    CarNode* cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = new CarNode{car, nullptr};
}

Car inputCar() {
    cout << "Input a new car: \n";
    Car car;
    cout << "\tBrand: ";
        cin >> car.brand;
    cout << "\tPrice: ";
        cin >> car.price;
    cout << "\tMileage: ";
        cin >> car.mileage;
    cout << "\tYear: ";
        cin >> car.year;
    return car;
}

void insertCarBeforeNext(CarNode*& cur, const string& brand,
            double price, int mileage, int year) {
    Car car{brand, price, mileage, year};

    if (!cur || !cur->next)
        return;

    cur->next = new CarNode{car, cur->next};
}

void cleanup(CarNode*& head) {
    while (head) {
        CarNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void readCarsFromFile(CarNode*& head, const Path& path) {
    Car car;
    std::string line;
    std::ifstream in{path};
    if (!in)
        return;
    while (getline(in, line)) {
        std::istringstream iss{line};
        iss >> car.brand >> car.price >> car.mileage >> car.year;
        appendCar(head, car.brand, car.price, car.mileage, car.year);
    }
}

void printCarList(const CarNode* head, const string desc = "") {
    cout << "==" << desc << "==\n";
    for (const CarNode* cur = head; cur != nullptr; cur = cur->next)
        cout
            << "Brand: " << cur->car.brand << '\t'
            << "Price: " << cur->car.price << '\t'
            << "Mileage: " << cur->car.mileage << '\t'
            << "Year: " << cur->car.year << '\n';
}



int countElements(CarNode*& head) {
    if (!head)
        return 0;

    CarNode* cur = head;
    int count = 1;
    while (cur->next) {
        cur = cur->next;
        count++;
    }
    return count;
}

// ... to funkcja z punktu 2, ale robi też inne rzeczy ;)
int run() {
    CarNode* head = nullptr;
    string filename;
    cout << "TSV Filename: ";
        cin >> filename;
    Path path{filename};
    readCarsFromFile(head, path);
    if (!head)
        return -1;

    printCarList(head, "AFTER READING FROM FILE");

    /* 2a */

    CarNode* cur = head;

    int mileageOfPreLastCar = -1;
    while (cur->next) {
        if (!cur->next->next)
            mileageOfPreLastCar = cur->next->car.mileage;
        cur = cur->next;
    }

    cur = head;
    int carCount = 0;
    int meanYear = 0;
    while (cur) {
        meanYear += cur->car.year;
        carCount++;
        cur = cur->next;
    }
    meanYear /= carCount;

    cur = head;
    int countMileageLessThanPreLast = 0;
    int countYearLessThanMeanYear = 0;


    while (cur && cur->next) {
        bool inserted = false;
        if (!inserted && cur->next->car.mileage < mileageOfPreLastCar) {
            countMileageLessThanPreLast++;

            if (countMileageLessThanPreLast % 2 == 0) {
                Car car = inputCar();
                insertCarBeforeNext(cur, car.brand, car.price, car.mileage, car.year);
                printCarList(head, "AFTER INSERTING AFTER CAR WITH LESSER MILEAGE");
                cur = cur->next;
                inserted = true;
            }
        }
        if (!inserted && cur->next->car.year < meanYear) {
            countYearLessThanMeanYear++;

            if (countYearLessThanMeanYear % 3 == 0) {
                Car car = inputCar();
                insertCarBeforeNext(cur, car.brand, car.price, car.mileage, car.year);
                printCarList(head, "AFTER INSERTING AFTER CAR WITH MORE RECENT YEAR");
                cur = cur->next;
                inserted = true;
            }
        }
        if (!inserted)
            cur = cur->next;
    }

    /* 2b */

    double maxPrice;
    cout << "Max price: ";
    cin >> maxPrice;

    string brand;
    cout << "New brand: ";
    cin >> brand;

    cur = head;
    while (cur && cur->car.price <= maxPrice)
        cur = cur->next;

    if (!cur || !cur->next) {
        cleanup(head);
        return 0;
    }

    int count = 0;
    meanYear = 0;
    int meanMileage = 0;
    double meanPrice = 0;
    CarNode* toDelete = cur->next;
    cur->next = nullptr;
    while (toDelete) {
        meanYear += toDelete->car.year;
        meanMileage += toDelete->car.mileage;
        meanPrice += toDelete->car.price;
        count++;

        CarNode* tmp = toDelete;
        toDelete = toDelete->next;
        delete tmp;
    }

    CarNode* carNodeTmp =  new CarNode{
            Car{
                brand,
                meanPrice / count,
                meanMileage / count,
                meanYear / count
            },
            nullptr
        };
    cur->next = carNodeTmp;

    printCarList(head, "AFTER REMOVING CARS AFTER MAX PRICE AND ADDING MEAN ONE");

    cleanup(head);
    return 0;
}
} // namespace hyzorek_p2

int main()
{
    return hyzorek_p2::run();
}
