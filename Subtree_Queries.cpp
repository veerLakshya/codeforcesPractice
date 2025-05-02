#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) cin >> val[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> subsum(n + 1, 0);

    auto dfs = [&](int cur, int par, auto self)->int {
        int sum = val[cur];
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            sum += self(nbr, cur, self);
        }
        subsum[cur] = sum;
        };
    while (q--) {

    }
}