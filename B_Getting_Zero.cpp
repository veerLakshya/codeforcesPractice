#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll x = 32768;
    vector<int> v[x];
    for (ll i = 0; i < x; i++) {
        v[(i * 2) % x].push_back(i);
        v[(i + 1) % x].push_back(i);
    }
    queue<ll> q;
    q.push(0);
    vector<int> vis(x, 0), dis(x, 0), a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vis[0] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (auto nbr : v[cur]) {
            if (!vis[nbr]) {
                vis[nbr] = 1;
                dis[nbr] = dis[cur] + 1;
                q.push(nbr);
            }
        }
    }
    for (int i = 0; i < n; i++) cout << dis[a[i]] << " ";
}