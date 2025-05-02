#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DP on Trees

int main() {
    ll n;
    cin >> n;
    vector<ll> col(n, 0); // 0-black 1-white
    for (int i = 0; i < n; i++) cin >> col[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<ll> ans(n, 0), dp(n, 0), subtree_size(n, 0);

    auto dfs = [&](int cur, int par, auto self)->void { // max pos in cur subtree
        dp[cur] = (col[cur] == 1 ? 1 : -1);
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            self(nbr, cur, self);
            dp[cur] += max(0ll, dp[nbr]);
        }
        };

    auto changeRoot = [&](int oldRoot, int newRoot)-> void {
        //undo
        dp[oldRoot] -= max(0ll, dp[newRoot]);
        //redo
        dp[newRoot] += max(0ll, dp[oldRoot]);

        };

    // Rerooting each node as a root once
    auto reroot = [&](int cur, int par, auto self)->void {
        ans[cur] = dp[cur];
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            changeRoot(cur, nbr);
            self(nbr, cur, self);
            changeRoot(nbr, cur);
        }
        };

    dfs(0, -1, dfs);
    reroot(0, -1, reroot);
    for (auto i : ans) cout << i << " ";

}