// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int ll = 0, rr = 0;
    while (m--) {
        if (abs(ll) < abs(l)) ll--;
        else if (rr < r) rr++;
    }
    cout << ll << " " << rr << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}