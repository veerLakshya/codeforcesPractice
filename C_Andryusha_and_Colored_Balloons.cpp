#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll k = 3;
    for (int i = 1; i <= n; i++) k = max(k, (ll)(adj[i].size() + 1));

    vector<ll> color(n + 1, -1);
    color[1] = 1;

    auto dfs = [&](int cur, int par, auto self)-> void {
        int x = 1;
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            if (x == color[par] || x == color[cur]) x++;
            if (x == color[par] || x == color[cur]) x++;
            // if (color[nbr] == -1) {
            color[nbr] = x;
            x++;
            self(nbr, cur, self);
            // }
        }
        };
    dfs(1, 0, dfs);

    cout << k << endl;
    for (int i = 1; i <= n; i++) cout << color[i] << " ";
}