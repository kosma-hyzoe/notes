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
#include <queue>
#include <algorithm>

namespace hyzorek_p3 {
using std::cout;
using std::getline; using std::string;
using std::set; using std::vector; using std::priority_queue; using std::pair;
using std::greater; using std::reverse;
using Path = std::filesystem::path;


// adj[i] = nbrsOfNodeI; nbrsOfNodeI = [(nbr1, w1), (nbr2, w2), ...]
using AdjacencyList = vector<vector<pair<int, int>>>;
int adjSize;

/* i.e.
* 5
* node nbrOfNode weight
* 0 1 7
* 0 2 3
*
* 1 3 2
*
* 2 1 4
* 2 3 8
* 2 4 2
*
* 3 4 5
*/
AdjacencyList readAdjFromFile(const Path& path) {
    std::string line;
    std::ifstream in{path};
    if (!in)
        return {};

    getline(in, line);
    std::istringstream issTmp{line};
    issTmp >> adjSize;
    AdjacencyList adj(adjSize);

    while (getline(in, line)) {
        std::istringstream iss{line};
        int x, y, w;
        if (!(iss >> x >> y >> w))
            continue;
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

using State = std::pair<int, int>; // distance, node
vector<int> dijkstra(const AdjacencyList& adj, int from, int to) {
    vector<int> dist(adj.size(), -1);
    vector<int> pred(adj.size(), -1);

    priority_queue<State, vector<State>, greater<> > pq; pq.push({0, from});
    while (!pq.empty()) {
        auto [w, cur] = pq.top(); pq.pop();
        if (dist[cur] != -1)
            continue;

        dist[cur] = w;
        if (cur == to)
            break;
        for (auto [nbr, wn]: adj[cur]) {
            if (dist[nbr] == -1) {
                pq.push({w + wn, nbr});
                if (pred[nbr] == -1)
                    pred[nbr] = cur;
            }
        }
    }

    vector<int> way;
    if (dist[to] != -1) {
        for (int nbr = to; nbr != -1; nbr = pred[nbr])
            way.push_back(nbr);
        reverse(way.begin(), way.end());
    }

    return way;
}

void run(int from, int to) {
    AdjacencyList adj = readAdjFromFile("adj");
    vector<int> way = dijkstra(adj, from, to);

    for (int i = 0; i < way.size(); i++) {
        if (i == way.size() - 1)
            cout << way[i] << '\n';
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
