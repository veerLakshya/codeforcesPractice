// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

int bitfreq[32], a[200069];

void solve(int t) {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            if ((a[i] & (1 << j)) != 0) {
                bitfreq[j]++;
            }
        }
    }

    int inc = LONG_LONG_MIN;

    for (int i = 1; i <= n; i++) {
        int cur = 0;

        for (int j = 0; j < 30; j++) {
            if ((a[i] & (1ll << j)) != 0) {
                cur += (1ll << j) * (n - bitfreq[j]) - (1ll << j) * bitfreq[j];
            }
        }

        inc = max(inc, cur);
    }

    cout << sum + inc << endl;

    fill(bitfreq, bitfreq + 32, 0);
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}