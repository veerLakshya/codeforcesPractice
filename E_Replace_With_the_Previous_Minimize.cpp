#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define INF 1e9
#define NINF -1e9
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class UnionFind {
private:
    vector<int> p;
public:
    UnionFind(int n) {
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
            if (x > y)swap(x, y);
            p[y] = x;
        }
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    UnionFind dsu(26);

    for (auto& i : s) {
        i = dsu.findSet(i - 'a') + 'a';
        while (i - 'a' > 0 && k > 0) {
            dsu.unionSet(i - 'a', i - 'a' - 1);
            i = dsu.findSet(i - 'a') + 'a';
            k--;
        }
    }
    cout << s << endl;
}

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}