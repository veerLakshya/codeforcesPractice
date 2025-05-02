// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

class BIT {
public:
    int size = 1e7 + 69;
    vector<int> table;

    BIT() {
        table.resize(size);
    }
    // update position i by delta
    void update(int i, int delta) {
        while (i < size) {
            table[i] += delta;
            i += i & -i;
        }
    }
    // compute the prefix sum value [1, i]
    int sum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += table[i];
            i -= i & -i;
        }
        return sum;
    }

    int cnt(int i) {
        return sum(size) - sum(i);
    }
};

void solve(int t) {
    int n, inv = 0;
    cin >> n;

    BIT bit;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        inv += bit.cnt(x);
        bit.update(x, 1);
    }

    cout << inv << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}