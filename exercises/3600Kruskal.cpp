#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


class DSU {
private:
    vector<int> parent;
    int components;

public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
        components = n;
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true; 
        }
        return false; 
    }

    int getComponents() {
        return components;
    }
};

class Solution {
public:
    bool check(long long S, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int upgrades_needed = 0;

        for (const auto& edge : edges) {
            if (edge[3] == 1) { 
                if (edge[2] < S) return false; 
                if (!dsu.unite(edge[0], edge[1])) return false; 
            }
        }

        vector<pair<int, int>> optional_cost_0; 
        vector<pair<int, int>> optional_cost_1; 

        for (const auto& edge : edges) {
            if (edge[3] == 0) { 
                if (edge[2] >= S) {
                    optional_cost_0.push_back({edge[0], edge[1]});
                } else if ((long long)edge[2] * 2 >= S) {
                    optional_cost_1.push_back({edge[0], edge[1]});
                }
            }
        }

        for (const auto& p : optional_cost_0) {
            dsu.unite(p.first, p.second);
        }

        for (const auto& p : optional_cost_1) {
            if (dsu.find(p.first) != dsu.find(p.second)) {
                if (k > 0) {
                    dsu.unite(p.first, p.second);
                    k--;
                }
            }
        }

        return dsu.getComponents() == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        long long low = 0, high = 200001; 
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid == 0) {
                low = mid + 1;
                continue;
            }
            if (check(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        

        if (ans == 0) {
            bool is_possible_at_all = check(1, n, edges, k);
            if (!is_possible_at_all && n > 1) {
                 DSU dsu(n);
                 for (const auto& edge : edges) {
                     dsu.unite(edge[0], edge[1]);
                 }
                 if(dsu.getComponents() > 1) return -1;
            }
        }


        if (!check(1, n, edges, k)) {
            if (n > 1) return -1;
        }

        return ans;
    }
};