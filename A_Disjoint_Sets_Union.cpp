#include<bits/stdc++.h>
using namespace std;

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
        if (par[i] == i) return i;
        return par[i] = findPar(par[i]);
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
};

int32_t main() {

    return 0;
}