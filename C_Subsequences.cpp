// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

class BIT {
public:
    int size = 1e5 + 69;
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

    // compute the range sum value[i, j]
    int rangeSum(int i, int j) {
        return sum(j) - sum(i);
    }
};

void solve(int t) {
    int n, k;
    cin >> n >> k;
    BIT bit;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int smaller = bit.sum(x);
        cout << x << " " << smaller << endl;

        // choose k-1 elemets out of # of smaller elements
        // if (smaller >= k) ans += ;

        bit.update(x, 1);
    }
    if (k) cout << ans;
    else cout << 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}