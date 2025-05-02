#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

struct DSU {
    vector<int> par, rnk, sz;
    int c, maxi = 1;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
        for (int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int i) {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    int get_size(int i) {
        return sz[find(i)];
    }
    int count() {
        return c;    //connected components
    }
    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        maxi = max(maxi, sz[j]);
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
    int maxsize() {
        return maxi;
    }
};

int32_t main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
        cout << dsu.count() << " " << dsu.maxsize() << endl;
    }
    return 0;
}