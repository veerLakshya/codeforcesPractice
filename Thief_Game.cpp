#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i] = { x, y };
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    for (ll ind = 0; ind < n; ind++) {
        for (ll flag = 0; flag <= 1; flag++) {
            ll ans = 0;
            if (flag) {
                if (v[ind].first == 0) {
                    ans = max(dp[ind][1], v[ind].second + dp[ind][0]);
                }
                else {
                    ans = dp[ind][1];
                }
            }
            else {
                if (v[ind].first == 1) {
                    ans = max(dp[ind][0], v[ind].second + dp[ind][1]);
                }
                else {
                    ans = max(dp[ind][0], v[ind].second + dp[ind][0]);
                }
            }
            dp[ind + 1][flag] = ans;
        }
    }

    cout << dp[n][0] << endl;
    return 0;
}
