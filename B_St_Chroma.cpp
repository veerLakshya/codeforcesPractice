// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int n, x;
    cin >> n >> x;
    vector<int> ans;
    for (int i = 0; i < n; i++) if (i != x) ans.push_back(i);
    if (ans.size() != n) ans.push_back(( x ));
    for (auto i : ans) cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}