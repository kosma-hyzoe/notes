/*
 * Zadanie P3
 *
 * Napisać program, który dla grafu zadanego macierzą sąsiedztwa (wczytywaną z
 * pliku) tworzy listę sąsiedztwa opisującą graf, a następnie na podstawie tej
 * listy metodą Dijkstry wyznacza najkrótszą ścieżkę w grafie dla dwóch węzłów
 * wskazanych przez użytkownika
 */

#include <iostream>
#include <queue>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <algorithm>

#define SIZE 5

namespace hyzorek_p3 {
using std::cout;
using std::getline; using std::string;
using std::greater; using std::reverse;
using std::priority_queue;
using Path = std::filesystem::path;

static int adj[SIZE][SIZE];
static int way[SIZE];

int readAdjFromFile(const Path& path) {
    std::string line;
    std::ifstream in{path};
    if (!in)
        return 1;

    while (getline(in, line)) {
        std::istringstream iss{line};
        int n, nbr, w;
        if (!(iss >> n >> nbr >> w))
            continue;
        adj[n][nbr] = w;
        adj[nbr][n] = w;
    }
    return 0;
}

void printAdj() {
    for (int n = 0; n < SIZE; n++) {
        cout << n << ": ";
        for (int nbr = 0; nbr < SIZE; nbr++) {
            if (adj[n][nbr] != 0)
                cout << nbr << 'w' << adj[n][nbr] << ' ';
        }
        cout << '\n';
    }
}

struct State {
    int dist;
    int node;
};
static State heap[500];
static int heapSize = 0;
void heapPush(State s) {
    int i = heapSize++;
    heap[i] = s;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].dist <= heap[i].dist)
            break;
        std::swap(heap[parent], heap[i]);
        i = parent;
    }
}
void dijkstra(int from, int to) {
    int dist[SIZE];
    for (int i = 0; i < SIZE; ++i)
        dist[i] = -1;
    int pred[SIZE];
    for (int i = 0; i < SIZE; ++i)
        pred[i] = -1;
}

void run(int from, int to) {
    for (int i = 0; i < SIZE; ++i)
        way[i] = -1;
    readAdjFromFile("adj");
    printAdj();

    dijkstra(from, to);
    for (int i = 0; i < SIZE; i++) {
        if (way[i] == -1)
            cout << '\n';
        else
            cout << way[i] << "-->";
    }
}

} // namespace hyzorek_p3

int main(int argc, char* argv[])
{
    int from = 0;
    int to = 1;
    if (argc == 3) {
        from = std::stoi(argv[1]); // CPP11-ish, but simpler than from_chars
        to = std::stoi(argv[2]);
    }

    hyzorek_p3::run(from, to);
    return 0;
}
