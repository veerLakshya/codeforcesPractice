#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind {
private:
    vector<int> p, rank, size;
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        size.assign(n, 1);
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }
    int findSet(int a) {
        if (p[a] == a) return a;
        return p[a] = findSet(p[a]);
    }
    void unionSet(int a, int b) {
        if (p[a] != p[b]) {
            int x = findSet(a), y = findSet(b);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind dsu(n);

    return 0;
}