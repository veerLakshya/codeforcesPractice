#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind {
private:
    vector<int> p, rank, points;
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        points.assign(n, 0);
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
            if (rank[x] > rank[y]) {
                p[y] = x;
                points[x] += points[y];
            }
            else {
                p[x] = y;
                points[y] += points[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    void add(int x, int exp) {
        int y = findSet(x);
        points[y] += exp;
    }
    int get(int x) {
        int y = findSet(x);
        return points[y];
    }
};

int main() {
    int n, m; cin >> n >> m;
    UnionFind dsu(n + 1);
    while (m--) {
        string s; cin >> s;
        if (s == "add") {
            int x, y; cin >> x >> y;
            dsu.add(x, y);
        }
        else if (s == "join") {
            int x, y; cin >> x >> y;
            dsu.unionSet(x, y);
        }
        else {
            int x; cin >> x;
            cout << (dsu.get(x)) << endl;
        }
    }
}