/*
 * Zadanie P3
 *
 * Napisać program, który dla grafu zadanego macierzą sąsiedztwa (wczytywaną z
 * pliku) tworzy listę sąsiedztwa opisującą graf, a następnie na podstawie tej
 * listy metodą Dijkstry wyznacza najkrótszą ścieżkę w grafie dla dwóch węzłów
 * wskazanych przez użytkownika
 */

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <limits>

namespace hyzorek_p3 {
using std::string;
using std::set;
using std::vector;
using std::cout;
using std::cin;
using std::getline;
using std::find;

using Path = std::filesystem::path;
using AdjacencyList = vector<vector<std::pair<int,int>>>;

AdjacencyList readAdjFromFile(const Path& path) {
    std::string line;
    std::ifstream in{path};

    if (!in)
        return {};

    getline(in, line);
    std::istringstream issTmp{line};
    int size;
    issTmp >> size;
    AdjacencyList adj(size);

    while (getline(in, line)) {
        std::istringstream iss{line};
        int x, y, w;
        iss >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }
    return adj;
}

void printAdj(vector<set<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << i << ": ";
        for (int v : adj[i])
            cout << v << " ";
        cout << '\n';
    }
}

int findShortest(vector<set<int>> adj, int from, int to) {
}

vector<int> shortestWayByDjikstra(vector<set<int>> adj, int from) {
    // vector<int> dist(adj.size());
    set<int> all;
    for (auto set: adj)
        for (auto elem: set)
             all.insert(elem);

    set<int> visited = {from}; // Q

    // wybranie el. o najmniejszej odległości
    for (int elem: all) {
        if (adj.at(elem)


    set<int> calculated; // S

    return {};

}

int run() {
    vector<set<int>> adj = readAdjFromFile("adj");
    printAdj(adj);

    return 0;
}

} // namespace hyzorek_p3

int main()
{
    return hyzorek_p3::run();
}
