// Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;

    vector<ll> a(n);
    vector<string> s(n), t(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) {
        cin >> s[i];
        t[i] = s[i];
        reverse(t[i].begin(), t[i].end());
    }

    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][1] = a[0];
    dp[0][0] = 0;

    for (ll i = 1; i < n; i++) {
        dp[i][0] = 1e18;
        dp[i][1] = 1e18;
        if (s[i - 1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (t[i - 1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (s[i - 1] <= t[i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        if (t[i - 1] <= t[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
    }

    ll ans = min(dp[n - 1][1], dp[n - 1][0]);
    if (ans < 1e18) cout << ans;
    else cout << -1;
}