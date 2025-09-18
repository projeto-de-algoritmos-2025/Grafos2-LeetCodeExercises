// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/submissions/1775378965/?envType=problem-list-v2&envId=9id5lube

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;


        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            auto [steps, r, c, elims] = pq.top();
            pq.pop();
            if (steps > dist[r][c][elims]) {
                continue;
            }

            if (r == m - 1 && c == n - 1) {
                return steps;
            }
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_elims = elims + grid[nr][nc];

                    if (next_elims <= k && dist[nr][nc][next_elims] > steps + 1) {
                        dist[nr][nc][next_elims] = steps + 1;
                        pq.push({steps + 1, nr, nc, next_elims});
                    }
                }
            }
        }
        return -1;
    }
};
