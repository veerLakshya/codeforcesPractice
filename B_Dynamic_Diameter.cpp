#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (n == 1) {
        cout << 1;
        return 0;
    }

    set<int> st;

    int maxi = 0;
    int node = -1;

    auto farthestNode = [&](int cur, int par, int dis, auto self)->void {
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            self(nbr, cur, dis + 1, self);
        }
        if (maxi < dis) {
            maxi = dis;
            node = cur;
        }
        };

    vector<int> ans(n + 1);
    farthestNode(1, 0, 0, farthestNode);
    st.insert(node);
    ans[node]++;
    // cout << node << endl;

    maxi = 0;
    farthestNode(node, 0, 0, farthestNode);
    st.insert(node);
    ans[node]++;

    int diameter = maxi;

    auto dfs = [&](int cur, int par, int dis, auto self)->void {
        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            self(nbr, cur, dis + 1, self);
        }
        if (dis == diameter) ans[cur]++;
        };

    for (auto i : st) dfs(i, 0, 0, dfs);
    for (int i = 1; i <= n; i++) {
        cout << diameter + (ans[i] > 0) << endl;
    }
}