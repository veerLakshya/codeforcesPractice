// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

const int N = 200069;

int c[N], adj[N], vis[N];
vector<int> starts;

void dfs(int cur) {
    vis[cur] = 1;
    int nbr = adj[cur];
    if (nbr == cur) {
        starts.push_back(cur);
    }
    else if (!vis[nbr]) dfs(nbr);
    else if (vis[nbr] == 1) starts.push_back(nbr);
    vis[cur] = 2;
}

void solve(int t) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> adj[i];

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    int ans = 0;

    for (auto x : starts) {
        int y = adj[x], add = c[x];
        while (y != x) {
            add = min(add, c[y]);
            y = adj[y];
        }
        ans += add;
    }

    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}