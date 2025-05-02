#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dp(n + 1, 0), nodes;
    int ans = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({ v, 0 });
        adj[v].push_back({ u, 1 });
    }

    function<void(int, int)> dfs = [&](int node, int par) {
        for (auto nbr : adj[node]) {
            if (nbr.first == par) continue;
            dp[node] += nbr.second;
            dfs(nbr.first, node);
            dp[node] += dp[nbr.first];
        }
        };

    function<void(int, int)> reroot = [&](int node, int par) {
        if (dp[node] < ans) {
            ans = dp[node];
            nodes.clear();
            nodes.push_back(node);
        }
        else if (dp[node] == ans) {
            nodes.push_back(node);
        }

        for (auto& nbr : adj[node]) {
            if (nbr.first == par) continue;
            dp[nbr.first] = dp[node] + (nbr.second ? -1 : 1);
            reroot(nbr.first, node);
        }
        };

    dfs(1, -1);
    reroot(1, -1);

    sort(nodes.begin(), nodes.end());

    cout << ans << '\n';
    for (auto i : nodes) cout << i << ' ';

    return 0;
}
