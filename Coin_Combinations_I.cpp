#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

ll h(ll i, vector<ll>& coins, vector<ll>& dp) {
    if (i < 0) return 0;
    if (i == 0) return 1;
    if (dp[i] != -1) return dp[i];
    ll ways = 0;
    for (auto coin : coins) ways = (ways + h(i - coin, coins, dp)) % mod;
    dp[i] = ways % mod;
    return dp[i];
}

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> coins(n), dp(x + 1, -1);
    for (ll i = 0; i < n; i++) cin >> coins[i];

    h(x, coins, dp);
    cout << (dp[x] == -1 ? 0 : dp[x]);

    return 0;
}