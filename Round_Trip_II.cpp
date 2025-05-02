// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> vis(n + 1, 0), instack(n + 1, 0), path;

    function<bool(int)> dfs = [&](int cur)->bool {
        vis[cur] = instack[cur] = 1;
        path.push_back(cur);
        for (auto nbr : adj[cur]) {
            if (!vis[nbr]) {
                bool f = dfs(nbr);
                if (f) return f;
            }
            else if (instack[nbr]) {
                path.push_back(nbr);
                return 1;
            }
        }
        instack[cur] = 0;
        path.pop_back();
        return false;
        };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bool f = dfs(i);
            if (f) {
                int nodes = path.size();
                for (int i = 0; i < nodes - 1; i++) {
                    if (path[i] == path[nodes - 1]) {
                        cout << nodes - i << endl;
                        for (int j = i; j < nodes; j++) cout << path[j] << " ";
                        return;
                    }

                }
            }
        }
    }

    cout << "IMPOSSIBLE";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}