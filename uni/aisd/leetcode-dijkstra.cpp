#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

using namespace std;
using State = std::pair<int, int>; // distance, node
using AdjacencyList = vector<
    vector<
        std::pair<int, int>  // (nbr, weight)
    >
>;

class Solution {
public:
    unordered_map<int, int> shortestPath(
        int n,
        vector<vector<int>>& edges,
        int src) {

        AdjacencyList adj = AdjacencyList(n);
        for (auto& edge: edges) {
            int srcTmp = edge[0];
            int nbr = edge[1];
            int weight = edge[2];

            adj[srcTmp].push_back({nbr, weight});
        }

        vector<int> shortest(adj.size(), -1);
        priority_queue<State, vector<State>, greater<> > pq; pq.push({0, src});
        while (!pq.empty()) {
            auto [w, cur] = pq.top(); pq.pop();
            if (shortest[cur] != -1)
                continue;
            shortest[cur] = w;

            for (auto [nbr, wn]: adj[cur])
                if (shortest[nbr] == -1)
                    pq.push({w + wn, nbr});
        }

        unordered_map<int, int> ret;
        for (int i = 0; i < shortest.size(); ++i)
            ret[i] = shortest[i];
        return ret;
    }
};
