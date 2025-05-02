#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9;


int solve(int x, vector<int>& coins, vector<int>& dp) {
    if (x < 0) return inf;
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];
    int best = inf;
    for (int coin : coins) {
        best = min(best, solve(x - coin, coins, dp) + 1);
    }
    dp[x] = best;
    return dp[x];
}


int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n), dp(x + 2, -1);
    for (int i = 0; i < n; i++) cin >> coins[i];

    solve(x, coins, dp);
    cout << (dp[x] == inf ? -1 : dp[x]);
}