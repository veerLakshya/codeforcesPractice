// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while (a > 0) {
        if (c > b)c--;
        else if (b)b--;
        else break;
        a--;
        ans++;
    }
    while (b > 0) {
        c--, b--, ans++;
    }
    if (c % 2 || a % 2 || b % 2) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}