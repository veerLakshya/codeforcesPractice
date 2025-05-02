// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int n;
    cin >> n;
    string s; cin >> s;
    int z = count(s.begin(), s.end(), '0');
    int o = n - z;
    int ans = ( o * z ) + z + ( o * ( o - 1 ) );
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}