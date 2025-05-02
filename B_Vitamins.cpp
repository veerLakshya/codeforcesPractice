#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(9, 1e18));
    dp[0][0] = 0;
    for (ll i = 0; i < n; i++) {
        ll cost;
        string s;
        cin >> cost >> s;

        ll string_mask = 0;
        ll freq[3]{ 0 };
        for (auto c : s) {
            freq[c - 'A']++;
        }
        for (ll i = 0; i < 3; i++) {
            if (freq[i]) string_mask |= (1 << i);
        }
        for (ll mask = 0; mask < 8; mask++) {
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);
            dp[i + 1][mask | string_mask] = min(dp[i + 1][mask | string_mask], dp[i][mask] + cost);
        }
    }
    ll ans = dp[n][7];
    cout << (ans == 1e18 ? -1 : ans);
    return 0;
}