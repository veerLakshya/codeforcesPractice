#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0, vertex = -1;
    // vector<int> nbrs(n + 1, 0);
    // function <void(int, int)> dfs = [&](int cur, int par)->void {
    //     int nbr = 0;
    //     for (auto x : adj[cur]) {
    //         nbr++;
    //         if (x == par) continue;
    //         dfs(x, cur);
    //     }
    //     nbrs[cur] = nbr;
    //     };

    for (int i = 1; i <= n; i++) if (adj[i].size() > 2) {
        cnt++;
        vertex = i;
        if (cnt > 1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    if (vertex == -1) {
        cout << "1\n";
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() == 1) cout << i << " ";
        }
        return 0;
    }
    cout << adj[vertex].size() << "\n";
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) cout << vertex << " " << i << "\n";
    }
}