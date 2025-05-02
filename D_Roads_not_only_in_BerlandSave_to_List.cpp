#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class DSU {
private:
    vector<int> par, rnk, sz;
    int c, maxi = 1;
public:
    DSU(int n) {
        c = n;
        rnk.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        par.assign(n + 1, 0);
        iota(par.begin(), par.end(), 0);
    }
    int findPar(int i) {
        return (par[i] == i ? i : (par[i] = findPar(par[i])));
    }
    bool isSame(int i, int j) {
        return findPar(i) == findPar(j);
    }
    int get_size(int i) {
        return sz[findPar(i)];
    }
    int count() {
        return c;    // num of connected components
    }
    bool merge(int i, int j) {
        if ((i = findPar(i)) == (j = findPar(j))) return false;
        else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        maxi = max(maxi, sz[j]);
        if (rnk[i] == rnk[j]) rnk[j]++;
        return true;
    }
    int maxsize() {
        return maxi;    // max size of any component
    }
    vector<int> giveComponents() {
        vector<int> comps;
        for (int i = 1; i < par.size(); i++) {
            // cout << i << " " << par[i] << endl;
            if (par[i] == i) comps.push_back(i);
        }
        return comps;
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    DSU dsu(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (!dsu.isSame(x, y)) dsu.merge(x, y);
        else edges.push_back({ x,y });
    }
    int ans = edges.size();
    cout << ans << endl;
    if (!ans) return 0;
    vector<int> comps = dsu.giveComponents();
    int x = comps.back();
    comps.pop_back();
    for (auto i : edges) {
        cout << i.first << " " << i.second << " " << x << " " << comps.back() << endl;
        comps.pop_back();
    }
}