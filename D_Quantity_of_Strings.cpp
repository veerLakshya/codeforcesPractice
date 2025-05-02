#include <bits/stdc++.h>
using namespace std;
#define ll long long 

class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

ll power(ll a, ll b, ll MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

int main() {
    ll n, m, k, MOD = 1e9 + 7;
    cin >> n >> m >> k;

    UnionFind dsu(n);
    for (ll i = 0; i <= n - k; i++) {
        ll l = i, r = i + k - 1;
        while (l < r) {
            dsu.unionSet(l, r);
            l++, r--;
        }
    }
    ll components = 0;

    for (ll i = 0; i < n; i++) components += (dsu.findSet(i) == i);


    cout << power(m, components, MOD);
}