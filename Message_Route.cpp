#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> v(n, 0), p(n, -1), d(n, INF);
    queue<int> q;
    q.push(0);
    d[0] = 1;
    v[0] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (auto nbr : adj[cur]) {
            if (!v[nbr]) {
                v[nbr] = 1;
                q.push(nbr);
                p[nbr] = cur;
                d[nbr] = d[cur] + 1;
            }
        }
    }
    if (d[n - 1] == INF) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << d[n - 1] << endl;

    vector<int> path;
    int cur = n - 1;
    while (cur != -1) {
        path.push_back(cur + 1);
        cur = p[cur];
    }
    reverse(path.begin(), path.end());
    for (auto i : path) cout << i << " ";
}