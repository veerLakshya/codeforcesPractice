// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int total = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            if (total == -1) {
                total = a[i] + b[i];
            }
            else if (a[i] + b[i] != total) {
                cout << 0 << endl;
                return;
            }
        }
    }
    if (total == -1) {
        int ans = k - *max_element(a.begin(), a.end()) + *min_element(a.begin(), a.end()) + 1;
        cout << ans << endl;
        return;
    }
    // cout << total << " t" << endl;
    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            int x = total - a[i];
            if (x > k || x < 0) {
                cout << 0 << endl;
                return;
            }
        }
    }
    cout << 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}