// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int n, price;
    cin >> n >> price;

    int c[505];
    for (int i = 0; i < n; i++) cin >> c[i];

    bool dp[505][505];
    dp[0][0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int x = price; x >= 0; x--) {
            for (int y = x; y >= 0; y--) {
                if (c[i] <= x) {
                    dp[x][y] |= dp[x - c[i]][y]; // in our subset but not used 
                    if (c[i] <= y) dp[x][y] |= dp[x - c[i]][y - c[i]]; // in our subset and also used
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i <= price; i++) if (dp[price][i]) ans.push_back(i);

    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}