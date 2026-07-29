#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Condition 1: A tree must have exactly n - 1 edges
        if (edges.size() != n - 1) return false;

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); // initialize parent[i] = i

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa == pb) return false; // cycle detected
            parent[pa] = pb;
            return true;
        };

        for (auto& e : edges) {
            if (!unite(e[0], e[1])) return false;
        }

        return true; // connected and no cycles
    }
};
