#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n, 0);
    auto dfs = [&](int i, auto self)-> void {
        vis[i] = 1;
        for (auto nbr : adj[i]) {
            if (!vis[nbr]) self(nbr, self);
        }
        };
    vector<int> nodes;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans++;
            dfs(i, dfs);
            nodes.push_back(i + 1);
        }
    }
    cout << ans - 1 << endl;
    if (ans == 1) return 0;
    for (int i = 0; i < nodes.size() - 1; i++) {
        cout << nodes[i] << " " << nodes[i + 1] << endl;
    }
}