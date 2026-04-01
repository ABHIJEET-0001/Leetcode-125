#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dest, unordered_set<string>& visited) {
        // Agar node exist nahi karta
        if (graph.find(src) == graph.end()) return -1.0;

        // Same node
        if (src == dest) return 1.0;

        visited.insert(src);

        for (auto& neighbor : graph[src]) {
            string next = neighbor.first;
            double weight = neighbor.second;

            if (visited.count(next)) continue;

            double result = dfs(next, dest, visited);
            if (result != -1.0) {
                return result * weight;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        
        // Step 1: Graph build
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // Step 2: Solve queries
        vector<double> ans;

        for (auto& q : queries) {
            string src = q[0];
            string dest = q[1];

            unordered_set<string> visited;
            double res = dfs(src, dest, visited);
            ans.push_back(res);
        }

        return ans;
    }
};