#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dis(n + 1, 0);

    int maxi = 0, node = -1;

    // function to find the farthest node
    auto farthestNode = [&](int cur, int par, int d, auto& self) -> void {
        if (d > maxi) {
            maxi = d;
            node = cur;
        }
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            self(nbr, cur, d + 1, self);
        }
        };

    // function to update distances from a node
    auto dfs = [&](int cur, int par, int d, auto& self) -> void {
        dis[cur] = max(dis[cur], d);
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            self(nbr, cur, d + 1, self);
        }
        };

    // Find one endpoint of the tree diameter
    farthestNode(1, 0, 0, farthestNode);
    int firstEnd = node;

    // Find the other endpoint of the diameter
    maxi = 0;
    farthestNode(firstEnd, 0, 0, farthestNode);
    int secondEnd = node;

    // Run DFS from both endpoints to get max distance from either
    dfs(firstEnd, 0, 0, dfs);
    dfs(secondEnd, 0, 0, dfs);

    // Print the maximum distances
    for (int i = 1; i <= n; i++) cout << dis[i] << " ";
}
