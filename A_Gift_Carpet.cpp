// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    string like = "vika";

    for (int i = 0; i < n; i++) cin >> s[i];

    auto helper = [&](int i, int j, int pos, auto self)->bool {
        if (pos < 0) return 1;
        if (j < 0) return 0;
        if (i < 0) return self(n - 1, j - 1, pos, self);

        bool f = 0;
        if (s[i][j] == like[pos]) f |= self(n - 1, j - 1, pos - 1, self);

        return f || self(i - 1, j, pos, self);
        };

    if (helper(n - 1, m - 1, 3, helper)) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}