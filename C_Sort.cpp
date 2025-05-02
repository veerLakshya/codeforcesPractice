// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> pre(n + 1, vector<int>(27, 0));

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        pre[i][a[i - 1] - 'a']++;
        pre[i][b[i - 1] - 'a']--;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += max(0ll, pre[r][i] - pre[l][i]);
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}