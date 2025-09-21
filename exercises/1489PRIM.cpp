// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/submissions/1775403885/?envType=problem-list-v2&envId=minimum-spanning-tree
// Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
private:
    int getMstWeight(int n, const vector<vector<int>>& edges, int ignore_edge_idx, int force_edge_idx) {
        vector<vector<pair<int, int>>> adj(n);
        int forced_edge_original_weight = 0;

        for (int i = 0; i < edges.size(); ++i) {
            if (i == ignore_edge_idx) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            if (i == force_edge_idx) {
                forced_edge_original_weight = weight;
                weight = 0;
            }
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        int mst_weight = 0;
        int nodes_count = 0;
        

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);


        pq.push({0, 0});

        while (!pq.empty() && nodes_count < n) {
            auto [weight, u] = pq.top();
            pq.pop();

            if (visited[u]) {
                continue;
            }

            visited[u] = true;
            mst_weight += weight;
            nodes_count++;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int edge_weight = edge.second;
                if (!visited[v]) {
                    pq.push({edge_weight, v});
                }
            }
        }

        if (nodes_count != n) {
            return numeric_limits<int>::max();
        }

        return mst_weight + forced_edge_original_weight;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edges_with_idx = edges;
        for(int i = 0; i < edges.size(); ++i) {
            edges_with_idx[i].push_back(i);
        }


        int original_mst_weight = getMstWeight(n, edges_with_idx, -1, -1);
        
        vector<int> critical_edges;
        vector<int> pseudo_critical_edges;

        for (int i = 0; i < edges_with_idx.size(); ++i) {

            int weight_without = getMstWeight(n, edges_with_idx, i, -1);
            if (weight_without > original_mst_weight) {
                critical_edges.push_back(edges_with_idx[i][3]);
                continue; 
            }

            int weight_with = getMstWeight(n, edges_with_idx, -1, i);
            if (weight_with == original_mst_weight) {
                pseudo_critical_edges.push_back(edges_with_idx[i][3]);
            }
        }

        return {critical_edges, pseudo_critical_edges};
    }
};