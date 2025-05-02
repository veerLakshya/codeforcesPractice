#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a[k];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x - 1].push_back(i);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // if (s == 1) {
    //     for (int i = 0; i < n; i++) cout << 0 << " ";
    //     return 0;
    // }
    vector <vector<ll>> val(n, vector<ll>(k, 0));
    for (int i = 0; i < k; i++) {
        queue<ll> q;
        vector<ll> dist(n, INT_MAX);
        for (auto j : a[i]) {
            q.push(j);
            dist[j] = 0;
        }
        while (q.size()) {
            ll x = q.front();
            q.pop();
            for (auto nbr : adj[x]) {
                if (dist[nbr] > dist[x] + 1) {
                    dist[nbr] = dist[x] + 1;
                    q.push(nbr);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            val[j][i] = dist[j];
            // cout << dist[j] << " ";
        }
        // cout << endl;
    }
    for (auto i : val) {
        sort(i.begin(), i.end());
        int ans = 0;
        for (int j = 0; j < s; j++) ans += i[j];
        cout << ans << " ";
    }

}