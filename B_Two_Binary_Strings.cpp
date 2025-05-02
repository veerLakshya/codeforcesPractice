// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size() - 1; i++) {
        if ((a[i] == '0' && a[i] == b[i]) && (a[i + 1] == '1' && a[i + 1] == b[i + 1])) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}